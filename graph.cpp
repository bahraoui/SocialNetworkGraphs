#include "graph.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    graph mama = graph();
    graph mama2 = graph();
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
    /*
   a 0
   b 1
   c 
   d 2
   e 1
   f 0
   */

    /*mama.add_vertice(6);
    mama.add_edge(1, 0);
    mama.add_edge(1, 2);
    mama.add_edge(2, 3);
    mama.add_edge(4, 1);
    mama.add_edge(0, 5);
    mama.add_edge(1, 5);
    mama.add_edge(4, 2);
    mama.add_edge(5, 2);
    mama.add_edge(4, 3);
    mama.add_edge(5, 4);*/

    mama.add_vertice(4);
    mama.add_edge(0, 1);
    mama.add_edge(0, 2);
    mama.add_edge(1, 2);
    mama.add_edge(1, 3);

    /*
   a 0
   b 1
   c 2
   d 3
   e 4
   f 5
   g 6
   h 7
   i 8
   */

    /*mama.add_vertice(9);
    mama.add_edge(0,1);

    mama.add_edge(1,2);
    mama.add_edge(1,3);
    mama.add_edge(1,4);
    mama.add_edge(1,6);

    mama.add_edge(2,4);
    mama.add_edge(2,8);
    mama.add_edge(2,5);

    mama.add_edge(3,4);
    mama.add_edge(3,7);
    mama.add_edge(3,8);

    mama.add_edge(4,5);
    mama.add_edge(4,6);
    mama.add_edge(4,7);
    mama.add_edge(4,8);

    mama.add_edge(5,7);

    mama.add_edge(6,8);

    mama.add_edge(7,8);*/

    mama.display_graph();

    mama.algo1();

    /*mama2.add_vertice_algo1(mama, 0);

    mama2.display_graph();

    mama2.add_vertice_algo1(mama, 1);

    mama2.display_graph();*/

    /*vector<int> degeneracyOrder = mama.find_degeneracy_order();

    vector<int> K = {2, 3, 4};

    K = mama.order_vertices_degeneracy(K, degeneracyOrder);

    printf("CLIQUE : [");
    for (long unsigned int i = 0; i < K.size(); i++)
    {
        printf("%d ", K[i]);
    }
    printf("]\n");
    */

    //

    /*map<int, vector<int>> cliquesMaxFind = mama.get_cliquesMax();

    printf("taille : %ld \n", cliquesMaxFind.size());

    map<int, vector<int>>::iterator p;
    for (p = cliquesMaxFind.begin(); p != cliquesMaxFind.end(); p++)
    {
        cout << "clique " << p->first << " : ";
        for (long unsigned int i = 0; i < p->second.size(); i++)
        {
            cout << p->second[i] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    //mama2.add_vertice_algo1(mama,0);
    //mama2.add_vertice_algo1(mama,1);
    //mama2.add_vertice_algo1(mama,2);
    //mama2.add_vertice_algo1(mama,3);
    //mama2 = mama2.add_vertice_algo1(mama,4);
    //mama2 = mama2.add_vertice_algo1(mama,5);

    //mama2.display_graph();

    //mama.bron_kerbosch();

    /*map<int, vector<int>> cliquesMaxFind = mama.get_cliquesMax();

    map<int, vector<int>>::iterator p;
    for (p = cliquesMaxFind.begin(); p != cliquesMaxFind.end(); p++)
    {
        cout << "clique " << p->first << " : ";
        for (long unsigned int i = 0; i < p->second.size(); i++)
        {
            cout << p->second[i] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    /*printf("Tri : [");
    for(long unsigned int i = 0; i < ascendingVertices.size(); i++)
        printf(" %d ",ascendingVertices[i]);
    printf("]\n\n");*/

    /*vector<short int> adjancyOrder = mama.find_degeneracy_order();
    printf("Ordre d'adjacence : [");
    for(long unsigned int i = 0; i < adjancyOrder.size(); i++)
        printf(" %d ",adjancyOrder[i]);
    printf("]\n\n");*/
    //mama.bron_kerbosch_pivot();

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
