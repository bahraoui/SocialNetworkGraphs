#include "manoussakis.h"

void create_algo_GJ(graph g1, graph g2, int vertice)
{
    vector<int> vertices = {};

    map<int, vector<int>>::iterator it;
    map<int, vector<int>> adjancyListGraph1 = g1.get_adjancyList();
    map<int, vector<int>> adjancyListGraph2 = g2.get_adjancyList();

    graph g3 = g2;

    for (it = adjancyListGraph1.begin(); it != adjancyListGraph1.end(); it++)
        vertices.push_back(it->first);

    vertices.push_back(vertice);

    for (long unsigned int i = 0; i < adjancyListGraph2.size(); i++)
    {
        if (!count(vertices.begin(), vertices.end(), i))
        {
            g3.delete_vertice(i);
        }
    }
    g1 = g3;
}

vector<int> order_vertices_degeneracy(vector<int> clique, vector<int> order)
{
    vector<int> finalOrder = {};

    for (long unsigned int i = 0; i < order.size(); i++)
        if (count(clique.begin(), clique.end(), order[i]))
            finalOrder.push_back(order[i]);

    return finalOrder;
}

int map_contains_clique(map<int, vector<int>> mapTest, vector<int> clique)
{
    map<int, vector<int>>::iterator it;
    int i = 0;

    for (it = mapTest.begin(); it != mapTest.end(); it++)
    {
        if (it->second == clique)
            return i;
        i++;
    }

    return -1;
}

map<int, vector<int>> manoussakis_algorithm_1(graph g)
{
    int inT, inDeletedClique, vertices = g.get_numberVertices();

    vector<int> degeneracyOrder = {}; //find_degeneracy_order(g);
    vector<int> K;

    map<int, vector<int>> T, p;
    map<int, vector<int>> deletedClique;
    map<int, vector<int>> cliquesMaxFind;
    map<int, vector<int>>::iterator it;

    graph *Gj;

    Gj->add_vertice(1);

    for (int i = 1; i < vertices; i++)
    {
        create_algo_GJ(g, *Gj, i);
        bron_kerbosch(Gj);

        cliquesMaxFind = Gj->get_cliquesMax();

        for (it = cliquesMaxFind.begin(); it != cliquesMaxFind.end(); it++)
        {
            K = order_vertices_degeneracy(it->second, degeneracyOrder);

            inT = map_contains_clique(T, K);
            inDeletedClique = map_contains_clique(deletedClique, K);

            if (inT != -1)
            {
                T.erase(inT);
                deletedClique.insert(pair<int, vector<int>>((int)(deletedClique.size()), K));
            }
            else if (inDeletedClique == -1)
                T.insert(pair<int, vector<int>>((int)(T.size()), K));
        }
    }

    return T;
}