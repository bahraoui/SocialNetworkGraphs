#include "graph.h"
#include <time.h>

int main() 
{
    srand(time(NULL));
    int i;
    graph mama = graph();
    /*
    int moyenne=0,i,nbessais=1;
    graph mama;
    for (i = 0; i < nbessais; i++)
    {
        mama = graph();
        mama.add_vertice(10);
        moyenne += mama.random_graph(0.50);
        //mama.display_graph();
        mama.free_graph();
    }
    printf("essais : %d\nmoyenne : %f\n",nbessais,((float)moyenne/nbessais));
    */
    short int cliquesMaximales[MAX_VERTICES][MAX_VERTICES];
    if (cliquesMaximales[0][0] != 0)
    {
        printf("ok\n");
    }
    
   /* 
    // TEST/DEBUG de la fct memcpy pr voir si elle fonctionne avec cliquesMaximales et un struct vertices
    vertices R;
    R.numberOfVerticesInList=1;
    R.verticesList = (short int*)malloc(MAX_VERTICES*sizeof(short int));
    for (i = 0; i < MAX_VERTICES; i++)
    {
        R.verticesList[i]=5;
    }
    
    short int cliquesMaximales[MAX_VERTICES][MAX_VERTICES];
    memcpy(cliquesMaximales[1],R.verticesList,MAX_VERTICES*sizeof(short int));
    printf("1-max: %d, 2: %d\n",cliquesMaximales[0][14],R.verticesList[0]);
    */

    /*
    mama.barabasi_albert(2);
    mama.display_graph();
    */
    /*int listSubgraphe[2] = {5,4};
    int subgrapheSize = 2;

    mama.create_subgraph(listSubgraphe, subgrapheSize);*/
    
    return 0;
}