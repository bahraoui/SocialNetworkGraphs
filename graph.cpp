#include "graph.h"
#include <time.h>

int main() 
{
    int moyenne=0,i,nbessais=1;
    srand(time(NULL));
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
    /*
    mama.barabasi_albert(2);
    mama.display_graph();
    */
    /*int listSubgraphe[2] = {5,4};
    int subgrapheSize = 2;

    mama.create_subgraph(listSubgraphe, subgrapheSize);*/
    
    return 0;
}