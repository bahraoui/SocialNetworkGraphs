#include "graph.h"
#include <time.h>

int main() 
{
    int moyenne=0,i,nbessais=1000;
    srand(time(NULL));
    for (i = 0; i < nbessais; i++)
    {
        graph mama = graph();
        mama.add_vertice(10);
        moyenne += mama.random_graph(0.9);
    }
    printf("moyenne : %f\n",((float)moyenne/nbessais));
    /*
    mama.barabasi_albert(2);
    mama.display_graph();
    */
    /*int listSubgraphe[2] = {5,4};
    int subgrapheSize = 2;

    mama.create_subgraph(listSubgraphe, subgrapheSize);*/
    
    return 0;
}