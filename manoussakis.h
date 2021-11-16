#include "bronKerboschDegeneracy.h"
#include "bronKerbosch.h"

#ifndef M
#define M

/**
 * @brief Create a algo GJ for the Manoussakis Algorithm 1 
 * 
 * @param g1 
 * @param g2 
 * @param vertice 
 */
void create_algo_GJ(graph *g1, graph *g2, int vertice);

/**
 * @brief Order a list of vertice thanks to a degeneracy order
 * 
 * @param clique 
 * @param order 
 * @return vector<int> 
 */
vector<int> order_vertices_degeneracy(vector<int> clique, vector<int> order);

/**
 * @brief Indicates if a clique is in a map of clique
 * 
 * @param mapTest 
 * @param clique 
 * @return int 
 */
int map_contains_clique(map<int, vector<int>> mapTest, vector<int> clique);

/**
 * @brief The Manoussakis Algorithm
 * 
 * @param g 
 * @return map<int, vector<int>> 
 */
map<int, vector<int>> manoussakis_algorithm_1(graph *g);

#endif