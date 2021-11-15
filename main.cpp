#include "graph.h"
#include "bronKerboschDegeneracy.h"
#include "bronKerboschPivot.h"
#include "bronKerbosch.h"
#include "random.h"

#ifndef MAIN
#define MAIN

int main()
{
    srand(time(NULL));

    graph gRandomProbability, gBarabasiAlbert;

    printf("###########################\n");
    printf("  SOCIAL NETWORK GRAPHS\n");
    printf("###########################\n\n");
    printf("Marwane BAHRAOUI & Reda GUENDOUZ\n");

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

    gRandomProbability.display_graph();

    printf("\n\n");

    printf("Add 5 Vertices + Barabasi Albert (m = 8)\n");

    gBarabasiAlbert.add_vertice(8);

    barabasi_albert(&gBarabasiAlbert, 8);

    gBarabasiAlbert.display_graph();

    return 0;
}

#endif