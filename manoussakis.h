#include "bronKerboschDegeneracy.h"
#include "bronKerbosch.h"

void add_vertice_algo1(graph g, int vertice);

vector<int> order_vertices_degeneracy(vector<int> clique, vector<int> order);

int map_contains_clique(map<int, vector<int>> mapTest, vector<int> clique);

map<int, vector<int>> algo1();