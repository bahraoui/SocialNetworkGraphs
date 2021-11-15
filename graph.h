#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <thread>
#include <iostream>

#define SIZE_ _INT 2
#define MAX_VERTICES 15

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

/**
 * @class graph
 * @brief graphe en liste d'adjacence 
 * Cette classe permet de manipuler des graphes selon 
 * la théorie des graphes.
 * champ privé : adjacencyList liste d'adjacence du graphe
 * constructeur : graph()
 * Les accesseurs et modifieurs permettent de respecter le principe d'encapsulation.
 * Ils sont de la forme : get_nomDuChamp - set_nomDuChamp
 */
class graph
{
private:
    map<int, vector<int>> adjancyList;
    map<int, vector<int>> cliquesMax;

public:
    graph()
    {
    }

    int get_numberVertices()
    {
        int count = 0;
        map<int, vector<int>>::iterator it;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
            count++;
        return count;
    }

    int get_totalDegree()
    {
        int totalDegree;
        for (long unsigned int i = 0; i < get_adjancyList().size(); i++)
            totalDegree += (int)(get_adjancyList()[i].size());
        return totalDegree;
    }

    map<int, vector<int>> get_adjancyList()
    {
        return adjancyList;
    }

    map<int, vector<int>> get_cliquesMax()
    {
        return cliquesMax;
    }

    /**
     * Affiche le graphe 
    */
    void display_graph()
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

    void add_vertice(int numberVerticeToAdd)
    {
        int i;
        for (i = 0; i < numberVerticeToAdd; i++)
        {
            vector<int> v(0, {});
            adjancyList.insert(pair<int, vector<int>>(i, v));
        }
    }

    bool add_edge(int verticeSrc, int verticeDest)
    {
        if (verticeDest == verticeSrc || verticeDest < 0 || verticeSrc < 0 || verticeDest >= MAX_VERTICES || verticeSrc >= MAX_VERTICES)
            return false; // les valeurs donnees sont incorrects

        adjancyList[verticeSrc].push_back(verticeDest);
        adjancyList[verticeDest].push_back(verticeSrc);

        return true;
    }

    int get_number_neighbors(int verticeNumber)
    {
        return get_adjancyList()[verticeNumber].size();
    }

    vector<int> get_neighbors(int verticeNumber)
    {
        vector<int> neighbors = {};
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size(); i++)
            neighbors.push_back(get_adjancyList()[verticeNumber][i]);
        return neighbors;
    }

    vector<int> get_neighbors_intersection(int verticeNumber, vector<int> verticesToLook)
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

    bool is_graph_valid()
    {
        if ((int)(get_adjancyList().size()) > 0)
        {
            return true;
        }
        return false;
    }

    void delete_vertice(int vertice)
    {
        vector<int> neighbors = get_neighbors(vertice);

        for (long unsigned int i = 0; i < neighbors.size(); i++)
            for (long unsigned int j = 0; j < adjancyList[neighbors[i]].size(); j++)
                if (adjancyList[neighbors[i]][j] == vertice)
                    adjancyList[neighbors[i]].erase(adjancyList[neighbors[i]].begin() + j);

        adjancyList.erase(vertice);
    }
};
