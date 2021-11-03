#include "graph.h"


int main() 
{
    graph mama = graph();
    mama.display_graph(); // graphe vide
    mama.add_vertice(2);
    printf("%d",mama.add_edge(1,2));
    printf("%d",mama.add_edge(-9,2));
    mama.display_graph(); // graphe pas vide (meme si auncun sens pr l'instant)
    printf("MAMA : %d\n",mama.get_adjacencyList()[5]);
    
    /*int listSubgraphe[2] = {5,4};
    int subgrapheSize = 2;

    mama.create_subgraph(listSubgraphe, subgrapheSize);*/
    
    return 0;
}