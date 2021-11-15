#include "bronKerboschDegeneracy.h"
#include "bronKerboschPivot.h"

//Ordre de degenerescence
vector<int> ascending_edges(graph g)
{
    int v;

    vector<int> ascendingEdges = {};

    map<int, vector<int>> adjancyListGraph = g.get_adjancyList();
    map<int, vector<int>>::iterator it;

    for (it = adjancyListGraph.begin(); it != adjancyListGraph.end(); it++)
        ascendingEdges.push_back(it->first);

    for (long unsigned int i = 0; i < ascendingEdges.size(); i++)
    {
        for (long unsigned int j = 0; j < ascendingEdges.size(); j++)
        {
            if (g.get_number_neighbors(ascendingEdges[i]) < g.get_number_neighbors(ascendingEdges[j]))
            {
                v = ascendingEdges[i];
                ascendingEdges[i] = ascendingEdges[j];
                ascendingEdges[j] = v;
            }
        }
    }

    return ascendingEdges;
}

//Ordre de degenerescence
vector<int> find_degeneracy_order(graph g)
{
    long unsigned int maxSize;

    vector<int> ascendingEdges = ascending_edges(g), degeneracyOrder = {};

    graph gCopy = g;

    maxSize = ascendingEdges.size();

    for (long unsigned int i = 0; i < maxSize; i++)
    {
        degeneracyOrder.push_back(ascendingEdges[0]);
        gCopy.delete_vertice(ascendingEdges[0]);
        ascendingEdges = ascending_edges(g);
    }

    return degeneracyOrder;
}

void bron_kerbosch_degeneracy(graph g)
{
    int vertice;

    vector<int> P = {}, X = {}, degeneracyX = {}, verticeBronKerboschPivot = {}, degeneracyOrder = find_degeneracy_order(g), degeneracyP = degeneracyOrder;

    for (long unsigned int i = 0; i < degeneracyOrder.size(); i++)
    {
        vertice = degeneracyOrder[i];

        degeneracyP.erase(degeneracyP.begin());
        P = g.get_neighbors_intersection(vertice, degeneracyP);

        X = g.get_neighbors_intersection(vertice, degeneracyX);
        degeneracyX.push_back(vertice);

        verticeBronKerboschPivot = {};
        verticeBronKerboschPivot.push_back(vertice);
        bron_kerbosch_pivot_aux(g, P, verticeBronKerboschPivot, X);
    }
}