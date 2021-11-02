#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
/**
 * @class graph
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
public:
    
    graph() 
    {
        int i;

        adjacencyList = (short int *)malloc((MAX_VERTICES * (MAX_VERTICES-1)) * sizeof(short int));

        for (i = 0; i < MAX_VERTICES * (MAX_VERTICES-1); i++)
            adjacencyList[i]= -2;
    }
    
    short int* get_adjacencyList() {
        return adjacencyList;
    }


    short int* actual_vertices(){
        int cmpt=0,i;
        short int* existingVertices = (short int*)malloc(MAX_VERTICES * sizeof(short int));
        for (i = 0; i < MAX_VERTICES * (MAX_VERTICES-1); i+=(MAX_VERTICES-1))
        {
            if (adjacencyList[i] != -2)
                existingVertices[cmpt]=1; // en c,  <=> true
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
        short int* existingVertices = actual_vertices();
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (existingVertices[i]) // on verifie si le sommet i existe bien
            {
                printf("Voisins du sommet %d : ",i);
                
                for (j = 0; j <(MAX_VERTICES-1); j++)
                    if (adjacencyList[(i * (MAX_VERTICES - 1)) + j] != -2)
                        printf("%d  ",adjacencyList[(i * (MAX_VERTICES - 1)) + j]);
                // printf("  ///i=%d,j=%d///\n",i,j); // ligne a utiliser pour debug cette methode
                printf("\n");

            }
        }
        printf("\n##################################\n");
    }

    bool add_vertice(short int verticeToAdd){
        short int i;
        if (adjacencyList[verticeToAdd*(MAX_VERTICES-1)] != -2 || verticeToAdd < 0 || verticeToAdd >= MAX_VERTICES)
            // print (sommet existe deja) : a mettre la ou il sera utilise plus tard
            return false;
        for (i = verticeToAdd*(MAX_VERTICES-1); i < (verticeToAdd+1)*(MAX_VERTICES-1); i++)
            adjacencyList[i]=-1;
        return true;
    }

    bool add_edge(short int verticeSrc, short int verticeDest){
        short int i;
        if (adjacencyList[verticeSrc*(MAX_VERTICES-1)] == -2 || adjacencyList[verticeDest*(MAX_VERTICES-1)] == -2 || verticeDest==verticeSrc)
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
                        return true;
                    }
                }
            }
        }
        return false;
    }
};