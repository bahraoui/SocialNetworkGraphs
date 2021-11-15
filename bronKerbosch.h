#include "graph.h"

#ifndef BK
#define BK

void bron_kerbosch(graph g);

void bron_kerbosch_aux(graph g, vector<int> P, vector<int> R, vector<int> X);

#endif