#include "graph.h"

graph::graph()
{
}

int graph::get_numberVertices()
{
    int count = 0;
    map<int, vector<int>>::iterator it;

    for (it = adjancyList.begin(); it != adjancyList.end(); it++)
        count++;
    return count;
}

int graph::get_totalDegree()
{
    int totalDegree;
    for (long unsigned int i = 0; i < get_adjancyList().size(); i++)
        totalDegree += (int)(get_adjancyList()[i].size());
    return totalDegree;
}

map<int, vector<int>> graph::get_adjancyList()
{
    return adjancyList;
}

map<int, vector<int>> graph::get_cliquesMax()
{
    return cliquesMax;
}

void graph::set_cliquesMax(map<int, vector<int>> parCliquesMax)
{
    cliquesMax = parCliquesMax;
}

void graph::display_graph()
{
    printf("################ START #################\n");
    map<int, vector<int>>::iterator it;

    for (it = adjancyList.begin(); it != adjancyList.end(); it++)
    {
        printf("%d : ", it->first);
        for (long unsigned int j = 0; j < it->second.size(); j++)
            printf(" %d ", it->second[j]);
        printf("\n");
    }
    printf("\n############## END ####################\n\n");
}

void graph::display_cliques()
{
    printf("CLIQUES : \n");
    map<int, vector<int>>::iterator p;

    for (p = cliquesMax.begin(); p != cliquesMax.end(); p++)
    {
        printf("[");
        for (long unsigned int i = 0; i < p->second.size(); i++)
        {
            printf("%d ", p->second[i]);
        }
        printf("]\n");
        cout << endl;
    }
    cout << endl;
}

void graph::add_vertice(int numberVerticeToAdd)
{
    int i;
    for (i = 0; i < numberVerticeToAdd; i++)
    {
        vector<int> v(0, {});
        adjancyList.insert(pair<int, vector<int>>(i, v));
    }
}

bool graph::add_edge(int verticeSrc, int verticeDest)
{
    if (verticeDest == verticeSrc || verticeDest < 0 || verticeSrc < 0 || verticeDest >= MAX_VERTICES || verticeSrc >= MAX_VERTICES)
        return false; // les valeurs donnees sont incorrects

    adjancyList[verticeSrc].push_back(verticeDest);
    adjancyList[verticeDest].push_back(verticeSrc);

    return true;
}

int graph::get_number_neighbors(int verticeNumber)
{
    return get_adjancyList()[verticeNumber].size();
}

vector<int> graph::get_neighbors(int verticeNumber)
{
    vector<int> neighbors = {};
    for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size(); i++)
        neighbors.push_back(get_adjancyList()[verticeNumber][i]);
    return neighbors;
}

vector<int> graph::get_neighbors_intersection(int verticeNumber, vector<int> verticesToLook)
{
    vector<int> neighbors;
    for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size(); i++)
    {
        if (count(verticesToLook.begin(), verticesToLook.end(), get_adjancyList()[verticeNumber][i]))
        {
            neighbors.push_back(get_adjancyList()[verticeNumber][i]);
        }
    }

    return neighbors;
}

bool graph::is_graph_valid()
{
    if ((int)(get_adjancyList().size()) > 0)
    {
        return true;
    }
    return false;
}

void graph::delete_vertice(int vertice)
{
    vector<int> neighbors = get_neighbors(vertice);

    for (long unsigned int i = 0; i < neighbors.size(); i++)
        for (long unsigned int j = 0; j < adjancyList[neighbors[i]].size(); j++)
            if (adjancyList[neighbors[i]][j] == vertice)
                adjancyList[neighbors[i]].erase(adjancyList[neighbors[i]].begin() + j);

    adjancyList.erase(vertice);
}