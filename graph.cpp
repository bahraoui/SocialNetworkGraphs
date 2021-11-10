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
    mama.add_vertice(4);
    mama.add_edge(0,1);
    mama.add_edge(1,2);
    mama.add_edge(2,0);
    mama.add_edge(1,3);
    mama.display_graph();

    map <short int,vector<short int>>cliquesMax;
    vertices P;
    vertices R;
    vertices X;
    P = vertices();
    R = vertices();
    X = vertices();
    for (i = 0; i < mama.get_numberVertices() ; i++) // on remplit P avec les sommets du graphe
        P.add_vertice(i);


    mama.bron_kerbosch_aux(P,R,X,cliquesMax);

    //mama.bron_kerbosch();


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