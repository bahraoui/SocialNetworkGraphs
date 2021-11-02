#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 500
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

    void display_graph(){
        int i,j,cmpt;
        printf("\nAffichage du graphe via liste d'adjacence (%d sommets possibles): \n##################################\n\n",MAX_VERTICES);
        short int existingVertices[MAX_VERTICES];
        for (size_t i = 0; i < MAX_VERTICES; i++)
            existingVertices[i]=i;
        
        cmpt=0;
        for (i = 0; i < MAX_VERTICES * (MAX_VERTICES-1); i+=(MAX_VERTICES-1))
        {
            if (adjacencyList[i] == -2)
                existingVertices[cmpt]=-2;
            cmpt++;
        }
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (existingVertices[i] != -2)
            {
                printf("Voisins du sommet %d : ",i);
                
                for (j = 0; j <(MAX_VERTICES-1); j++){
                    if (adjacencyList[(i * (MAX_VERTICES - 1)) + j] != -1)
                        printf("%d  ",adjacencyList[(i * (MAX_VERTICES - 1)) + j]);
                }
                // printf("  ///i=%d,j=%d///\n",i,j); // ligne a utiliser pour debug cette methode
                printf("\n");
            }
        }
        printf("\n##################################\n");
    }
};
