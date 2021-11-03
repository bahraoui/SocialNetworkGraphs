#include "graph.h"


int main() 
{
    srand(time(NULL)); //Permet d'avoir nos valeurs aleatoires (proba)
    graph mama = graph();
    mama.add_vertice(3);
    mama.add_edge(0,1);
    mama.add_edge(0,2);
    mama.add_edge(1,2);
    //mama.display_graph(); // graphe pas vide (meme si auncun sens pr l'instant)
    
    mama.barabasi_albert(2);
    mama.display_graph();

    /*int listSubgraphe[2] = {5,4};
    int subgrapheSize = 2;

    mama.create_subgraph(listSubgraphe, subgrapheSize);*/
    
    return 0;
}