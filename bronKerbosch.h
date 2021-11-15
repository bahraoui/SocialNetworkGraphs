#include "graph.h"

#ifndef BK
#define BK

/**
 * @brief The Standard Bron Kerbosch Algorithm Launcher
 * 
 * @param g 
 */
void bron_kerbosch(graph *g);

/**
 * @brief The Standard Bron Kerbosch Algorithm 
 * 
 * @param g 
 */
void bron_kerbosch_aux(graph *g, vector<int> P, vector<int> R, vector<int> X);

#endif