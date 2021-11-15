#include "random.h"
#include <time.h>

bool result_probability(float probability)
{
    float r = ((double)rand() / (RAND_MAX));
    //printf("%f -- %f\n",r,probability);
    if (r <= probability)
        return true;
    return false;
}

void barabasi_albert(graph *g, int m)
{
    long unsigned int i = 0;
    float barabasiAlbertProbability;

    map<int, vector<int>> adjancyListGraph = g->get_adjancyList();

    if (!g->is_graph_valid())
    {
        return;
    }

    //graphe n sommet

    //Ajout d'un nouveau noeud
    g->add_vertice(1);

    //graphe n sommet + 1 noeud sans arrete

    while (m > 0 && i < adjancyListGraph.size() - 1)
    {
        //calcul proba
        barabasiAlbertProbability = (float)g->get_number_neighbors(i) / g->get_totalDegree();
        if (result_probability(barabasiAlbertProbability))
        {
            g->add_edge((int)(g->get_adjancyList().size()), i);
            m--;
        }
        i++;
    }
}

bool random_graph(graph *g, float probability)
{
    int cmpt = 0;

    map<int, vector<int>> adjancyListGraph = g->get_adjancyList();

    if (probability < 0.0001 || probability > 0.9999) // on verifie que la proba donnee est correcte
        return false;

    for (long unsigned int i = 0; i < adjancyListGraph.size(); i++) // chaque sommet existant
    {
        for (long unsigned int j = 0; j < adjancyListGraph.size(); j++)
        { // chaque voisin du sommet i
            if (result_probability(probability))
            {
                g->add_edge(i, j);
            }
        }
    }
    return cmpt;
}