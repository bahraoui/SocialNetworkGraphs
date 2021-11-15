#include "graph.h"

#ifndef R
#define R

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

/**
 * @brief Indicates whether the probability generated a success or a failure.
 * 
 * @param probability 
 * @return true 
 * @return false 
 */
bool result_probability(float probability);

/**
 * @brief Algorithm of barabasi albert
 * 
 * @param g 
 * @param m 
 */
void barabasi_albert(graph *g, int m);

/**
 * @brief Add random edges to the graphe
 * 
 * @param g 
 * @param probability 
 * @return true 
 * @return false 
 */
bool random_graph(graph *g, float probability);

#endif