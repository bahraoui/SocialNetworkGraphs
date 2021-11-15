#include "graph.h"

#ifndef BKD
#define BKD

/**
 * @brief Give an ascending vertice order thanks to thier edges number.
 * 
 * @param g 
 * @return vector<int> 
 */
vector<int> ascending_edges(graph *g);

/**
 * @brief Find the degeneracy order of a graph
 * 
 * @param g 
 * @return vector<int> 
 */
vector<int> find_degeneracy_order(graph *g);

/**
 * @brief Algorithm of Bron Kerbosh
 * 
 * @param g 
 */
void bron_kerbosch_degeneracy(graph *g);

#endif