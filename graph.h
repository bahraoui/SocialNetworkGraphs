#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "vertices.h"

/**
 * @class graph
 * @brief graphe en liste d'adjacence 
 * Cette classe permet de manipuler des graphes selon 
 * la théorie des graphes.
 * champ privé : adjacencyList liste d'adjacence du graphe
 * constructeur : graph()
 * Les accesseurs et modifieurs permettent de respecter le principe d'encapsulation.
 * Ils sont de la forme : get_nomDuChamp - set_nomDuChamp
 */
class graph
{
private:
    short int* adjacencyList;
    short int totalDegree;
    short int numberVertices;
public:
    
    graph() 
    {
        int i;

        totalDegree = 0;numberVertices = -1;

        adjacencyList = (short int *)malloc((MAX_VERTICES * (MAX_VERTICES-1)) * sizeof(short int));

        for (i = 0; i < MAX_VERTICES * (MAX_VERTICES-1); i++)
            adjacencyList[i]= -2;
    }

    short int get_numberVertices(){
        return numberVertices+1;
    }

    short int get_totalDegree(){
        return totalDegree;
    }

    void free_graph(){
        free(adjacencyList);
    }
    
    short int* get_adjacencyList() {
        return adjacencyList;
    }

    //obselete fct
    short int* get_actual_vertices(){
        int cmpt=0,i;
        short int* existingVertices = (short int*)malloc(MAX_VERTICES * sizeof(short int));
        for (i = 0; i < MAX_VERTICES * (MAX_VERTICES-1); i+=(MAX_VERTICES-1))
        {
            if (adjacencyList[i] != -2)
                existingVertices[cmpt]=1; // en c, 1 <=> true
            else
                existingVertices[cmpt]=0; // en c, 0 <=> false
            cmpt++;
        }
        return existingVertices;
    }

    /**
     * Affiche le graphe 
    */
    void display_graph(){
        int i,j;
        printf("\nAffichage du graphe via liste d'adjacence (%d sommets possibles): \n##################################\n\n",MAX_VERTICES);
        short int* existingVertices = get_actual_vertices();
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (existingVertices[i]) // on verifie si le sommet i existe bien
            {
                printf("Voisins du sommet %d : ",i);
                
                for (j = 0; j <(MAX_VERTICES-1); j++)
                    if (adjacencyList[(i * (MAX_VERTICES - 1)) + j] != -1)
                        printf("%d  ",adjacencyList[(i * (MAX_VERTICES - 1)) + j]);
                // printf("  ///i=%d,j=%d///\n",i,j); // ligne a utiliser pour debug cette methode
                printf("\n");

            }
        }
        printf("\n##################################\n");
    }

    void display_matrix(){
        int i,j;
        printf("\n\n##################################\n\n");
        for (i = 0; i < MAX_VERTICES; i++)
        {              
            printf("%d => ",i);  
            for (j = 0; j <(MAX_VERTICES-1); j++)
                printf("%d  ",adjacencyList[(i * (MAX_VERTICES - 1)) + j]);
            // printf("  ///i=%d,j=%d///\n",i,j); // ligne a utiliser pour debug cette methode
            printf("\n");
        }
        printf("\n##################################\n");
    }

    bool add_vertice(int numberVerticeToAdd){
        int i, j;
        for (j = 0; j < numberVerticeToAdd; j++)
        {
            if(numberVertices + 1 < MAX_VERTICES)
            {
                numberVertices += 1;
                for (i = numberVertices*(MAX_VERTICES-1); i < (numberVertices+1)*(MAX_VERTICES-1); i++)
                    adjacencyList[i]=-1;
            }
            else 
                return false;  
        }
        return true;    
    }

    bool add_edge(short int verticeSrc, short int verticeDest){
        short int i;
        if (verticeDest==verticeSrc || verticeDest < 0 || verticeSrc < 0 || verticeDest >= MAX_VERTICES || verticeSrc >= MAX_VERTICES)
            return false; // les valeurs donnees sont incorrects
        if (adjacencyList[verticeSrc*(MAX_VERTICES-1)] == -2 || adjacencyList[verticeDest*(MAX_VERTICES-1)] == -2)
            return false; // le cas ou au moins un des deux sommets n'existe pas
        
        for (i = 0; i < MAX_VERTICES-1; i++)
            if (adjacencyList[(verticeSrc * (MAX_VERTICES-1)) + i] == verticeDest)
                return true; // false ou true ? // le cas ou il existe deja une arrete entre les deux sommets
        for (i = 0; i < MAX_VERTICES-1; i++)
        {
            if (adjacencyList[(verticeSrc * (MAX_VERTICES-1)) + i] == -1) // recherche d'une place "libre" pour inserer le voisiin
            {
                adjacencyList[(verticeSrc * (MAX_VERTICES-1)) + i] = verticeDest;
                for (i = 0; i < MAX_VERTICES-1; i++)
                {
                    if (adjacencyList[(verticeDest * (MAX_VERTICES-1)) + i] == -1) // idem
                    {
                        adjacencyList[(verticeDest * (MAX_VERTICES-1)) + i] = verticeSrc;
                        totalDegree += 2;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int get_number_neighbors(short int verticeNumber) {
        int i, numberNeighbors = 0;

        for (i = verticeNumber*(MAX_VERTICES-1); i < (verticeNumber+1)*(MAX_VERTICES-1)-1; i++)
            if (adjacencyList[i] !=-1)
                numberNeighbors++;

        return numberNeighbors;
    }

    short int* get_neighbors(short int verticeNumber){
        int i, j=0, numberNeighbor = get_number_neighbors(verticeNumber); // double boucle necessaire pour simplification de la fonction add_vertices dans vertices
        short int* neighbors = (short int*)malloc(numberNeighbor*sizeof(short int));
        for (i = verticeNumber*(MAX_VERTICES-1); i < (verticeNumber+1)*(MAX_VERTICES-1)-1; i++)
        if (adjacencyList[i] !=-1) {
            neighbors[j]=adjacencyList[i];
            j++;
        }
        return neighbors;
    }

    bool is_graph_valid() {
        if (totalDegree > 0){
            return true;
        }
        return false;
    }

    bool is_clique() {
        //si le graphe comporte plus de deux sommets
        //chaque sommet est lié a tout les autres = complet
        int i;

        if (numberVertices < 2){
            return false;
        }
        for (i = 0; i < numberVertices; i++)
            if (get_number_neighbors(i) != MAX_VERTICES-1) 
                return false;
        
        return true;
    }

    bool result_probability(float probability) {
        float r = ((double) rand() / (RAND_MAX));
        //printf("%f -- %f\n",r,probability);
        if (r <= probability) 
            return true;
        return false;
    }

    void barabasi_albert(short int m) {
        if (!is_graph_valid()){
            return;
        }

        int i = 0;
        float barabasiAlbertProbability;

        //graphe n sommet

        //Ajout d'un nouveau noeud
        add_vertice(1);

        //graphe n sommet + 1 noeud sans arrete

        while (m > 0 && i < numberVertices-1) {
            //calcul proba
            barabasiAlbertProbability = (float)get_number_neighbors(i)/totalDegree;
            if (result_probability(barabasiAlbertProbability)) {
                add_edge(numberVertices,i);
                m--;
            }
            i++;
        }
    }

    bool random_graph(float probability){
        int i,j,cmpt=0;
        if (probability < 0.0001 || probability > 0.9999) // on verifie que la proba donnee est correcte
            return false;
        //display_matrix();
        for (i = 0; i <= numberVertices; i++) // chaque sommet existant
        {
            for (j = (i+1); j <=(numberVertices);  j++) { // chaque voisin du sommet i
                if (adjacencyList[(i * (numberVertices -1)) + j] == -1 && result_probability(probability))
                    add_edge(i,j);
            }
        }
        return cmpt;
    }

    void BronKerbosch(vertices P, vertices R, vertices X, short int** cliquesMax){
        /**
         * Conditions intiales :
         *  Mettre toutes les valeurs de cliquesMax/R/X a 0
         *  P doit au depart contenir tous les sommets du graphe
         * Algo:
        si P et X sont vides alors
            déclarer R clique maximale
        pour tout sommet v de P faire
            BronKerbosch1(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
            P := P \ {v}
            X := X ⋃ {v}
         */
        int i;
        if (P.get_number_vertices() == 0 && X.get_number_vertices() == 0) // P et X sont vides
        {
            int i;
            // on ajoute au tableau de cliquesMax le R trouve
            for (i = 0; i < MAX_VERTICES; i++)
            {
                if (cliquesMax[i][0] == -1)
                {
                    memcpy(cliquesMax[i],R.get_verticesList(),MAX_VERTICES*sizeof(short int));
                    return;
                }
            }            
        }

        for (i = 0; i <= numberVertices; i++) // Pour tout sommet v de P
        {
            short int v = P.get_verticesList()[i];
            // a finir =>
            P.add_vertices(get_neighbors(v),get_number_neighbors(v));
            X.add_vertices(get_neighbors(v),get_number_neighbors(v));
            R.add_vertice(v);
            BronKerbosch(P.cloneVertices(), R.cloneVertices(), X.cloneVertices(), cliquesMax);
            P.del_vertice(v);
            X.add_vertice(v);
        }
    }


};