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
 * champ privé  : adjacencyList liste d'adjacence du graphe
 *              : cliquesMax La liste des cliques du graphe
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
    /**
     * @brief Construct a new graph object
     * 
     */
    graph();

    /**
     * @brief Get the numberVertices object
     * 
     * @return int 
     */
    int get_numberVertices();

    /**
     * @brief Get the totalDegree object
     * 
     * @return int 
     */
    int get_totalDegree();

    /**
     * @brief Get the adjancyList object
     * 
     * @return map<int, vector<int>> 
     */
    map<int, vector<int>> get_adjancyList();

    /**
     * @brief Get the cliquesMax object
     * 
     * @return map<int, vector<int>> 
     */
    map<int, vector<int>> get_cliquesMax();

    /**
     * @brief Get the number neighbors of a vertice
     * 
     * @param verticeNumber 
     * @return int 
     */
    int get_number_neighbors(int verticeNumber);

    /**
     * @brief Get the neighbors of a vertice
     * 
     * @param verticeNumber 
     * @return vector<int> 
     */
    vector<int> get_neighbors(int verticeNumber);

    /**
     * @brief Set the cliquesMax object
     * 
     * @param cliquesMax 
     */
    void set_cliquesMax(map<int, vector<int>> cliquesMax);

    /**
     * @brief Display the graph
     * 
     */
    void display_graph();

    /**
     * @brief Display all maximal cliques
     * 
     */
    void display_cliques();

    /**
     * @brief Add numberVerticeToAdd vertices to the graph
     * 
     * @param numberVerticeToAdd the number of vertices to add
     */
    void add_vertice(int numberVerticeToAdd);

    /**
     * @brief Add edges to the graph between two vertices
     * 
     * @param verticeSrc Vertice Source
     * @param verticeDest Vertice Dest
     * @return true 
     * @return false 
     */
    bool add_edge(int verticeSrc, int verticeDest);

    /**
     * @brief Get the neighbors intersection between neighbors of a vertice and verticesToLook
     * 
     * @param verticeNumber 
     * @param verticesToLook 
     * @return vector<int> 
     */
    vector<int> get_neighbors_intersection(int verticeNumber, vector<int> verticesToLook);

    /**
     * @brief Is a graph have more than one vertice
     * 
     * @return true 
     * @return false 
     */
    bool is_graph_valid();

    /**
     * @brief Delete a vertice of a graphe
     * 
     * @param vertice 
     */
    void delete_vertice(int vertice);
};

#endif