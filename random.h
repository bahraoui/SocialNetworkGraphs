#include "graph.h"

#ifndef R
#define R

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

bool result_probability(float probability);

void barabasi_albert(graph *g, int m);

bool random_graph(graph *g, float probability);

#endif