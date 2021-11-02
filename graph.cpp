#include "graph.h"


int main() 
{
    graph mama = graph();
    mama.display_graph(); // graphe vide
    mama.get_adjacencyList()[499]=5;
    mama.display_graph(); // graphe pas vide (meme si auncun sens pr l'instant)
    printf("MAMA : %d\n",mama.get_adjacencyList()[5]);
    
    return 0;
}