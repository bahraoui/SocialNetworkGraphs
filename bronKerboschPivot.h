#include "graph.h"

#ifndef BKP
#define BKP

/**
 * @brief The Bron Kerbosch Pivot Algorithm Launcher
 * 
 * @param g 
 */
void bron_kerbosch_pivot(graph *g);

/**
 * @brief The Bron Kerbosch Pivot Algorithm
 * 
 * @param g 
 */
void bron_kerbosch_pivot_aux(graph *g, vector<int> P, vector<int> R, vector<int> X);

/**
 * @brief Give a pivot for the Bron Kerbosch Pivot Algorithm
 * 
 * @param g 
 */
int choose_bron_kerbosh_pivot(graph *g, vector<int> P, vector<int> X);

#endif