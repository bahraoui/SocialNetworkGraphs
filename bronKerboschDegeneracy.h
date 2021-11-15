#include "graph.h"

#ifndef BKD
#define BKD

vector<int> ascending_edges(graph g);

vector<int> find_degeneracy_order(graph g);

void bron_kerbosch_degeneracy(graph g);

#endif