#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <thread>
#include <iostream>

#define SIZE_ _INT 2
#define MAX_VERTICES 15

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;

/**
 * @class graph
 * @brief graphe en liste d'adjacence 
 * Cette classe permet de manipuler des graphes selon 
 * la théorie des graphes.
 * champ privé : adjacencyList liste d'adjacence du graphe
 * constructeur : graph()
 * Les accesseurs et modifieurs permettent de respecter le principe d'encapsulation.
 * Ils sont de la forme : get_nomDuChamp - set_nomDuChamp
 */
class graph
{
private:
    map<int, vector<int>> adjancyList;
    map<int, vector<int>> cliquesMax;

public:
    graph()
    {
    }

    int get_numberVertices()
    {
        int count = 0;
        map<int, vector<int>>::iterator it;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
        {
            count++;
        }
        return count;
    }

    int get_totalDegree()
    {
        int totalDegree;
        for (long unsigned int i = 0; i < get_adjancyList().size(); i++)
        {
            totalDegree += (int)(get_adjancyList()[i].size());
        }
        return totalDegree;
    }

    map<int, vector<int>> get_adjancyList()
    {
        return adjancyList;
    }

    map<int, vector<int>> get_cliquesMax()
    {
        return cliquesMax;
    }

    /**
     * Affiche le graphe 
    */

    void display_graph()
    {
        printf("################ Debut #################\n");
        map<int, vector<int>>::iterator it;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
        {
            for (long unsigned int j = 0; j < it->second.size(); j++)
            {
                printf(" %d ", it->second[j]);
            }
            printf("\n");
        }
        printf("\n############## FIN ####################\n\n");
    }

    void add_vertice(int numberVerticeToAdd)
    {
        int i;
        for (i = 0; i < numberVerticeToAdd; i++)
        {
            vector<int> v(0, {});
            adjancyList.insert(pair<int, vector<int>>(i, v));
        }
    }

    bool add_edge(int verticeSrc, int verticeDest)
    {
        if (verticeDest == verticeSrc || verticeDest < 0 || verticeSrc < 0 || verticeDest >= MAX_VERTICES || verticeSrc >= MAX_VERTICES)
            return false; // les valeurs donnees sont incorrects

        adjancyList[verticeSrc].push_back(verticeDest);
        adjancyList[verticeDest].push_back(verticeSrc);

        return true;
    }

    int get_number_neighbors(int verticeNumber)
    {
        return get_adjancyList()[verticeNumber].size();
    }

    vector<int> get_neighbors(int verticeNumber)
    {
        vector<int> neighbors = {};
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size(); i++)
            neighbors.push_back(get_adjancyList()[verticeNumber][i]);
        return neighbors;
    }

    vector<int> get_neighbors_intersection(int verticeNumber, vector<int> verticesToLook)
    {
        vector<int> neighbors;
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size(); i++)
        {
            if (count(verticesToLook.begin(), verticesToLook.end(), get_adjancyList()[verticeNumber][i]))
            {
                neighbors.push_back(get_adjancyList()[verticeNumber][i]);
            }
        }

        return neighbors;
    }

    bool is_graph_valid()
    {
        if ((int)(get_adjancyList().size()) > 0)
        {
            return true;
        }
        return false;
    }

    bool result_probability(float probability)
    {
        float r = ((double)rand() / (RAND_MAX));
        //printf("%f -- %f\n",r,probability);
        if (r <= probability)
            return true;
        return false;
    }

    void barabasi_albert(int m)
    {
        if (!is_graph_valid())
        {
            return;
        }

        long unsigned int i = 0;
        float barabasiAlbertProbability;

        //graphe n sommet

        //Ajout d'un nouveau noeud
        add_vertice(1);

        //graphe n sommet + 1 noeud sans arrete

        while (m > 0 && i < get_adjancyList().size() - 1)
        {
            //calcul proba
            barabasiAlbertProbability = (float)get_number_neighbors(i) / get_totalDegree();
            if (result_probability(barabasiAlbertProbability))
            {
                add_edge((int)(get_adjancyList().size()), i);
                m--;
            }
            i++;
        }
    }

    bool random_graph(float probability)
    {
        int cmpt = 0;
        if (probability < 0.0001 || probability > 0.9999) // on verifie que la proba donnee est correcte
            return false;
        //display_matrix();
        for (long unsigned int i = 0; i < get_adjancyList().size(); i++) // chaque sommet existant
        {
            for (long unsigned int j = 0; j < get_adjancyList()[i].size(); j++)
            { // chaque voisin du sommet i
                if (result_probability(probability))
                    add_edge(i, j);
            }
        }
        return cmpt;
    }

    void pop_front(vector<int> &v)
    {
        if (v.size() > 0)
        {
            v.erase(v.begin());
        }
    }

    void bron_kerbosch()
    {
        vector<int> P = {}, R = {}, X = {};

        map<int, vector<int>>::iterator it;
        int i = 0;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
            P.push_back(it->first);

        bron_kerbosch_aux(P, R, X);
    }

    void bron_kerbosch_aux(vector<int> P, vector<int> R, vector<int> X)
    {
        if (P.empty() && X.empty())
        {
            cliquesMax.insert(pair<int, vector<int>>((int)(cliquesMax.size()), R));
            return;
        }

        vector<int> Ploop = P;

        for (long unsigned int i = 0; i < Ploop.size(); i++) // Pour chaque sommet v de P
        {
            vector<int> Pinter = {}, Runion = {}, Xinter = {};

            int v = Ploop[i];
            auto neighborsIterator = adjancyList.find(v);

            for (long unsigned int j = 0; j < neighborsIterator->second.size(); j++)
            {
                // Création de l'intersection P
                if (count(P.begin(), P.end(), neighborsIterator->second[j]))
                {
                    Pinter.push_back(neighborsIterator->second[j]);
                }
                // Création de l'intersection X
                if (count(X.begin(), X.end(), neighborsIterator->second[j]))
                {
                    Xinter.push_back(neighborsIterator->second[j]);
                }
            }

            Runion = R;
            Runion.push_back(v);

            bron_kerbosch_aux(Pinter, Runion, Xinter);

            X.push_back(v);
            remove(P.begin(), P.end(), v);
        }
    }

    void bron_kerbosch_pivot()
    {
        vector<int> P = {}, R = {}, X = {};

        for (long unsigned int i = 0; i < get_adjancyList().size(); i++) // on remplit P avec les sommets du graphe
            P.push_back(i);

        printf("Initialisation \n [");
        for (long unsigned int i = 0; i < P.size(); i++)
            printf(" %d ", P[i]);
        printf("]\n\n");

        bron_kerbosch_pivot_aux(P, R, X);
    }

    void bron_kerbosch_pivot_aux(vector<int> P, vector<int> R, vector<int> X)
    {
        if (P.empty() && X.empty())
        {
            cliquesMax.insert(pair<int, vector<int>>((int)(cliquesMax.size()), R));
            return;
        }

        //choose a pivot u ∈ P∪X
        int u = choose_bron_kerbosh_pivot(P, X);
        auto uNeighbors = adjancyList.find(u);

        vector<int> Ploop;

        for (long unsigned int i = 0; i < P.size(); i++)
        {
            // Création de l'intersection Ploop
            if (!count(uNeighbors->second.begin(), uNeighbors->second.end(), P[i]))
            {
                Ploop.push_back(P[i]);
            }
        }

        for (long unsigned int i = 0; i < Ploop.size(); i++) // Pour chaque sommet v de P
        {
            vector<int> Pinter = {}, Runion = {}, Xinter = {};

            int v = Ploop[i];
            auto neighborsIterator = adjancyList.find(v);

            for (long unsigned int j = 0; j < neighborsIterator->second.size(); j++)
            {
                // Création de l'intersection P
                if (count(P.begin(), P.end(), neighborsIterator->second[j]))
                {
                    Pinter.push_back(neighborsIterator->second[j]);
                }
                // Création de l'intersection X
                if (count(X.begin(), X.end(), neighborsIterator->second[j]))
                {
                    Xinter.push_back(neighborsIterator->second[j]);
                }
            }

            Runion = R;
            Runion.push_back(v);

            bron_kerbosch_pivot_aux(Pinter, Runion, Xinter);

            X.push_back(v);
            remove(P.begin(), P.end(), v);
        }
    }

    int choose_bron_kerbosh_pivot(vector<int> P, vector<int> X)
    {
        vector<int> neighbors = {};
        int max = -1, actual;
        int u;
        for (long unsigned int i = 0; i < P.size(); i++)
        {
            actual = get_neighbors_intersection(P[i], P).size();
            if (actual > max)
            {
                max = actual;
                u = P[i];
            }
        }
        for (long unsigned int i = 0; i < X.size(); i++)
        {
            actual = get_neighbors_intersection(X[i], X).size();
            if (actual > max)
            {
                max = actual;
                u = X[i];
            }
        }

        return u;
    }

    //Ordre de degenerescence
    vector<int> ascending_edges()
    {
        vector<int> ascendingEdges = {};
        int v;
        map<int, vector<int>>::iterator it;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
        {
            ascendingEdges.push_back(it->first);
        }

        for (long unsigned int i = 0; i < ascendingEdges.size(); i++)
        {
            for (long unsigned int j = 0; j < ascendingEdges.size(); j++)
            {
                if (get_number_neighbors(ascendingEdges[i]) < get_number_neighbors(ascendingEdges[j]))
                {
                    v = ascendingEdges[i];
                    ascendingEdges[i] = ascendingEdges[j];
                    ascendingEdges[j] = v;
                }
            }
        }
        return ascendingEdges;
    }

    //Ordre de degenerescence
    vector<int> find_degeneracy_order()
    {
        vector<int> ascendingEdges = ascending_edges();
        vector<int> degeneracyOrder = {};
        graph gCopy = *(this);
        long unsigned int maxSize = ascendingEdges.size();

        for (long unsigned int i = 0; i < maxSize; i++)
        {
            degeneracyOrder.push_back(ascendingEdges[0]);
            gCopy.delete_vertice(ascendingEdges[0]);
            ascendingEdges = gCopy.ascending_edges();
        }
        return degeneracyOrder;
    }

    void delete_vertice(int vertice)
    {
        vector<int> neighbors = get_neighbors(vertice);

        for (long unsigned int i = 0; i < neighbors.size(); i++)
            for (long unsigned int j = 0; j < adjancyList[neighbors[i]].size(); j++)
                if (adjancyList[neighbors[i]][j] == vertice)
                    adjancyList[neighbors[i]].erase(adjancyList[neighbors[i]].begin() + j);

        adjancyList.erase(vertice);
    }

    void bron_kerbosch_degeneracy()
    {
        vector<int> P = {}, degeneracyOrder = {}, X = {}, degeneracyP = {}, degeneracyX = {}, viBKP = {};
        int vi;

        degeneracyOrder = find_degeneracy_order();
        degeneracyP = degeneracyOrder;
        for (long unsigned int i = 0; i < degeneracyOrder.size(); i++)
        {
            vi = degeneracyOrder[i];

            degeneracyP.erase(degeneracyP.begin());
            P = get_neighbors_intersection(vi, degeneracyP);

            X = get_neighbors_intersection(vi, degeneracyX);
            degeneracyX.push_back(vi);

            viBKP = {};
            viBKP.push_back(vi);
            bron_kerbosch_pivot_aux(P, viBKP, X);
        }
    }

    void add_vertice_algo1(graph g, int vertice)
    {
        vector<int> vertices = {};
        map<int, vector<int>>::iterator it;
        graph g2 = g;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
        {
            vertices.push_back(it->first);
        }
        vertices.push_back(vertice);

        for (long unsigned int i = 0; i < g.adjancyList.size(); i++)
        {
            if (!count(vertices.begin(), vertices.end(), i))
            {
                g2.delete_vertice(i);
            }
        }
        *(this) = g2;
    }

    vector<int> order_vertices_degeneracy(vector<int> clique, vector<int> order)
    {
        vector<int> finalOrder = {};

        for (long unsigned int i = 0; i < order.size(); i++)
            if (count(clique.begin(), clique.end(), order[i]))
                finalOrder.push_back(order[i]);

        return finalOrder;
    }

    int map_contains_clique(map<int, vector<int>> mapTest, vector<int> clique)
    {
        map<int, vector<int>>::iterator it;
        int i = 0;

        for (it = mapTest.begin(); it != mapTest.end(); it++)
        {
            if (it->second == clique)
                return i;
            i++;
        }

        return -1;
    }

    map<int, vector<int>> algo1()
    {
        vector<int> degeneracyOrder = {};
        map<int, vector<int>> T;
        map<int, vector<int>> deletedClique;
        map<int, vector<int>>::iterator it;
        graph Gj;
        int taille = 0;
        int vertices = get_numberVertices();

        vector<int> K;

        degeneracyOrder = find_degeneracy_order();

        Gj.add_vertice_algo1(*(this), 0);

        for (int i = 1; i < vertices; i++)
        {
            Gj.add_vertice_algo1(*(this), i);
            Gj.bron_kerbosch();

            map<int, vector<int>> cliquesMaxFind = Gj.get_cliquesMax();

            for (it = cliquesMaxFind.begin(); it != cliquesMaxFind.end(); it++)
            {
                K = it->second;
                K = order_vertices_degeneracy(K, degeneracyOrder);

                /*printf("Order : [");
                for (long unsigned int i = 0; i < degeneracyOrder.size(); i++)
                {
                    printf("%d ", degeneracyOrder[i]);
                }
                printf("]\n");*/

                int inT = map_contains_clique(T, K);
                int inDeletedClique = map_contains_clique(deletedClique, K);

                if (inT != -1 && inDeletedClique == -1)
                {
                    T.erase(inT);
                    deletedClique.insert(pair<int, vector<int>>((int)(deletedClique.size()), K));
                }
                else if (inT == -1 && inDeletedClique == -1)
                {
                    T.insert(pair<int, vector<int>>((int)(T.size()), K));
                }

                map<int, vector<int>>::iterator p;
                for (p = T.begin(); p != T.end(); p++)
                {
                    cout << "clique " << p->first << " : ";
                    for (long unsigned int i = 0; i < p->second.size(); i++)
                    {
                        cout << p->second[i] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }

        return T;
    }

    void algo2()
    {
    }
};
