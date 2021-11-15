#include "bronKerboschPivot.h"

void bron_kerbosch_pivot(graph *g)
{
    vector<int> P = {}, R = {}, X = {};

    map<int, vector<int>> adjancyListGraph = g->get_adjancyList();

    map<int, vector<int>>::iterator it;

    for (it = adjancyListGraph.begin(); it != adjancyListGraph.end(); it++)
        P.push_back(it->first);

    bron_kerbosch_pivot_aux(g, P, R, X);
}

void bron_kerbosch_pivot_aux(graph *g, vector<int> P, vector<int> R, vector<int> X)
{
    int v, u;

    vector<int> Pinter, Runion, Xinter, Ploop = {};

    map<int, vector<int>> cliquesMax = g->get_cliquesMax(), adjancyListGraph = g->get_adjancyList();

    if (P.empty() && X.empty())
    {
        cliquesMax.insert(pair<int, vector<int>>((int)(cliquesMax.size()), R));
        g->set_cliquesMax(cliquesMax);
        return;
    }

    //choose a pivot u ∈ P∪X
    u = choose_bron_kerbosh_pivot(g, P, X);
    auto uNeighbors = adjancyListGraph.find(u);

    for (long unsigned int i = 0; i < P.size(); i++)
    {
        // Création de l'intersection Ploop
        if (!count(uNeighbors->second.begin(), uNeighbors->second.end(), P[i]))
            Ploop.push_back(P[i]);
    }

    for (long unsigned int i = 0; i < Ploop.size(); i++) // Pour chaque sommet v de P
    {
        Pinter = {}, Runion = {}, Xinter = {};
        v = Ploop[i];
        auto neighborsIterator = adjancyListGraph.find(v);

        for (long unsigned int j = 0; j < neighborsIterator->second.size(); j++)
        {
            // Création de l'intersection P
            if (count(P.begin(), P.end(), neighborsIterator->second[j]))
                Pinter.push_back(neighborsIterator->second[j]);
            // Création de l'intersection X
            if (count(X.begin(), X.end(), neighborsIterator->second[j]))
                Xinter.push_back(neighborsIterator->second[j]);
        }

        Runion = R;
        Runion.push_back(v);

        bron_kerbosch_pivot_aux(g, Pinter, Runion, Xinter);

        X.push_back(v);
        remove(P.begin(), P.end(), v);
    }
}

int choose_bron_kerbosh_pivot(graph *g, vector<int> P, vector<int> X)
{
    int u, actual, max = -1;

    vector<int> neighbors = {};

    for (long unsigned int i = 0; i < P.size(); i++)
    {
        actual = g->get_neighbors_intersection(P[i], P).size();
        if (actual > max)
        {
            max = actual;
            u = P[i];
        }
    }
    for (long unsigned int i = 0; i < X.size(); i++)
    {
        actual = g->get_neighbors_intersection(X[i], X).size();
        if (actual > max)
        {
            max = actual;
            u = X[i];
        }
    }

    return u;
}