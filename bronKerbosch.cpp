#include "bronKerbosch.h"

void bron_kerbosch(graph *g)
{
    vector<int> P = {}, R = {}, X = {};

    map<int, vector<int>> adjancyListGraph = g->get_adjancyList();

    map<int, vector<int>>::iterator it;

    for (it = adjancyListGraph.begin(); it != adjancyListGraph.end(); it++)
        P.push_back(it->first);

    bron_kerbosch_aux(g, P, R, X);
}

void bron_kerbosch_aux(graph *g, vector<int> P, vector<int> R, vector<int> X)
{
    int v;
    vector<int> Ploop = P;
    map<int, vector<int>> cliquesMax = g->get_cliquesMax(), adjancyListGraph = g->get_adjancyList();

    if (P.empty() && X.empty())
    {
        cliquesMax.insert(pair<int, vector<int>>((int)(cliquesMax.size()), R));
        g->set_cliquesMax(cliquesMax);
        return;
    }

    for (long unsigned int i = 0; i < Ploop.size(); i++) // Pour chaque sommet v de P
    {
        vector<int> Pinter = {}, Runion = {}, Xinter = {};

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

        bron_kerbosch_aux(g, Pinter, Runion, Xinter);

        X.push_back(v);
        remove(P.begin(), P.end(), v);
    }
}
