#include "graph.h"
#include "manoussakis.h"
#include "bronKerboschDegeneracy.h"
#include "bronKerbosch.h"
#include "bronKerboschPivot.h"
#include "random.h"

#ifndef MAIN
#define MAIN

int main()
{
    srand(time(NULL));

    graph gRandomProbability, gBarabasiAlbert, gBronKerbosch, gBronKerboschPivot, gBronKerboschDegeneracy, gManoussakisAlgorithm1;

    printf("###########################\n");
    printf("  SOCIAL NETWORK GRAPHS\n");
    printf("###########################\n\n");
    printf("Marwane BAHRAOUI & Reda GUENDOUZ\n\n");

    printf("Part 1 :\n");

    printf("\n\n\n");

    printf("Graph 1 : Random Graph (Probaility = 0.63) \n");
    printf("###########################################\n\n");

    gRandomProbability.add_vertice(6);

    random_graph(&gRandomProbability, 0.63);

    gRandomProbability.display_graph();

    printf("\n\n\n");

    printf("Graph 2 : Random Graph Barabasi Albert \n");
    printf("###########################################\n\n");
    printf("Graph triangle\n");

    gBarabasiAlbert.add_vertice(3);
    gBarabasiAlbert.add_edge(0, 1);
    gBarabasiAlbert.add_edge(0, 2);
    gBarabasiAlbert.add_edge(1, 2);

    gBarabasiAlbert.display_graph();

    printf("\n\n");

    printf("Add 5 Vertices + Barabasi Albert (m = 8)\n");

    for (int i = 0; i < 8; i++)
    {
        barabasi_albert(&gBarabasiAlbert, 8);
    }

    gBarabasiAlbert.display_graph();

    printf("\n\n\n");

    printf("Part 2 :\n");

    printf("Graph 3 : Bron Kerbosh \n");
    printf("###########################################\n\n");
    printf("Graph : \n");

    gBronKerbosch.add_vertice(4);
    gBronKerbosch.add_edge(0, 1);
    gBronKerbosch.add_edge(0, 2);
    gBronKerbosch.add_edge(1, 2);
    gBronKerbosch.add_edge(2, 3);

    gBronKerbosch.display_graph();

    printf("\n");

    printf("Bron Kerbosch Result : \n");

    bron_kerbosch(&gBronKerbosch);

    gBronKerbosch.display_cliques();

    printf("\n");

    printf("Graph 4 : Bron Kerbosh Pivot \n");
    printf("###########################################\n\n");
    printf("Graph : \n");

    gBronKerboschPivot.add_vertice(6);
    gBronKerboschPivot.add_edge(1, 0);
    gBronKerboschPivot.add_edge(1, 2);
    gBronKerboschPivot.add_edge(2, 3);
    gBronKerboschPivot.add_edge(4, 1);
    gBronKerboschPivot.add_edge(0, 5);
    gBronKerboschPivot.add_edge(1, 5);
    gBronKerboschPivot.add_edge(4, 2);
    gBronKerboschPivot.add_edge(5, 2);
    gBronKerboschPivot.add_edge(4, 3);
    gBronKerboschPivot.add_edge(5, 4);

    gBronKerboschPivot.display_graph();

    printf("Bron Kerbosch Pivot Result : \n");

    bron_kerbosch_pivot(&gBronKerboschPivot);

    gBronKerboschPivot.display_cliques();

    printf("\n");

    printf("Graph 5 : Bron Kerbosh Degeneracy \n");
    printf("###########################################\n\n");
    printf("Graph : \n");

    gBronKerboschDegeneracy.add_vertice(9);
    gBronKerboschDegeneracy.add_edge(0, 1);
    gBronKerboschDegeneracy.add_edge(1, 2);
    gBronKerboschDegeneracy.add_edge(1, 3);
    gBronKerboschDegeneracy.add_edge(1, 4);
    gBronKerboschDegeneracy.add_edge(1, 6);
    gBronKerboschDegeneracy.add_edge(2, 4);
    gBronKerboschDegeneracy.add_edge(2, 8);
    gBronKerboschDegeneracy.add_edge(2, 5);
    gBronKerboschDegeneracy.add_edge(3, 4);
    gBronKerboschDegeneracy.add_edge(3, 7);
    gBronKerboschDegeneracy.add_edge(3, 8);
    gBronKerboschDegeneracy.add_edge(4, 5);
    gBronKerboschDegeneracy.add_edge(4, 6);
    gBronKerboschDegeneracy.add_edge(4, 7);
    gBronKerboschDegeneracy.add_edge(4, 8);
    gBronKerboschDegeneracy.add_edge(5, 7);
    gBronKerboschDegeneracy.add_edge(6, 8);
    gBronKerboschDegeneracy.add_edge(7, 8);

    gBronKerboschDegeneracy.display_graph();

    printf("Bron Kerbosch Degeneracy Result : \n");

    bron_kerbosch_degeneracy(&gBronKerboschDegeneracy);

    gBronKerboschDegeneracy.display_cliques();

    printf("\n");

    printf("Part 3 :\n");

    printf("Graph 6 : Manoussakis' Algorithm 1  \n");
    printf("###########################################\n\n");

    gManoussakisAlgorithm1.add_vertice(9);
    gManoussakisAlgorithm1.add_edge(0,1);
    gManoussakisAlgorithm1.add_edge(1,2);
    gManoussakisAlgorithm1.add_edge(1,3);
    gManoussakisAlgorithm1.add_edge(1,4);
    gManoussakisAlgorithm1.add_edge(1,6);
    gManoussakisAlgorithm1.add_edge(2,4);
    gManoussakisAlgorithm1.add_edge(2,8);
    gManoussakisAlgorithm1.add_edge(2,5);
    gManoussakisAlgorithm1.add_edge(3,4);
    gManoussakisAlgorithm1.add_edge(3,7);
    gManoussakisAlgorithm1.add_edge(3,8);
    gManoussakisAlgorithm1.add_edge(4,5);
    gManoussakisAlgorithm1.add_edge(4,6);
    gManoussakisAlgorithm1.add_edge(4,7);
    gManoussakisAlgorithm1.add_edge(4,8);
    gManoussakisAlgorithm1.add_edge(5,7);
    gManoussakisAlgorithm1.add_edge(6,8);
    gManoussakisAlgorithm1.add_edge(7,8);

    gManoussakisAlgorithm1.display_graph();

    printf("Manoussakis Algorithm 1 Result : \n");

    manoussakis_algorithm_1(&gManoussakisAlgorithm1);

    gManoussakisAlgorithm1.display_cliques();

  return 0;
}

#endif