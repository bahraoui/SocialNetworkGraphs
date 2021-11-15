#ifndef BKP
#define BKP
#include "graph.h"

void bron_kerbosch_pivot(graph g);

void bron_kerbosch_pivot_aux(graph g, vector<int> P, vector<int> R, vector<int> X);

int choose_bron_kerbosh_pivot(graph g, vector<int> P, vector<int> X);

#endif