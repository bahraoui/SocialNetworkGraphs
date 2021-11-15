#ifndef G
#define G
#include "graph.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

bool result_probability(float probability);

void barabasi_albert(int m);

bool random_graph(float probability);

#endif