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

#ifndef GRAPH
#define GRAPH

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
    graph();

    int get_numberVertices();

    int get_totalDegree();

    map<int, vector<int>> get_adjancyList();

    map<int, vector<int>> get_cliquesMax();

    void display_graph();

    void add_vertice(int numberVerticeToAdd);

    bool add_edge(int verticeSrc, int verticeDest);

    int get_number_neighbors(int verticeNumber);

    vector<int> get_neighbors(int verticeNumber);

    vector<int> get_neighbors_intersection(int verticeNumber, vector<int> verticesToLook);

    bool is_graph_valid();

    void delete_vertice(int vertice);
};

#endif