#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <thread>
#include "tools.h"

// Le nombre maximum de sommet accepté
#define MAX_VERTICES 15

using namespace std;

/**
 * 
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
    /**
     * @brief Dictionnaire avec :
     * 
     * clé => un sommet
     * ; valeur => sa liste d'adjacence
     */
    map<int, vector<int>> adjancyList;

public:
    
    /**
     * @brief Construit un nouvel objet graph
     * 
     */
    graph();

    short int get_totalDegree();
    
    /**
     * @brief Récupère le champ privé adjancyList
     * 
     * @return adjancyList map<int, vector<int>> 
     */
    map<int, vector<int>> get_adjancyList();

    
    /**
     * @brief Affiche le graphe sous la forme d'une liste d'adjacence
     * 
     */
    void display_graph();

    /**
     * @brief ajoute un nombre defini de sommets
     * 
     * @param numberVerticeToAdd nombre de sommets a ajouter
     */
    void add_vertice(int numberVerticeToAdd);

    /**
     * @brief ajoute l'arete entre verticeSrc et verticeDest
     * 
     * @param verticeSrc 1er sommet de l'arete
     * @param verticeDest 2eme sommet de l'arete
     * @return true si l'ajout s'est bien effectue
     * @return false 
     */
    bool add_edge(short int verticeSrc, short int verticeDest);

    /**
     * @brief Recupere le nombre de voisins du sommet verticeNumber
     * 
     * @param verticeNumber le sommet a analyser
     * @return le nombre de voisins d'un sommet
     */
    int get_number_neighbors(short int verticeNumber);

    /**
     * @brief renvoie la liste des voisins d'un sommet
     * 
     * @param verticeNumber le sommet a analyser
     * @return la liste des voisins du sommet verticeNumber
     */
    vector<short int> get_neighbors(short int verticeNumber);
    

    vector<short int> get_neighbors_intersection(short int verticeNumber, vector<short int> verticesToLook);

    bool is_graph_valid();

    void barabasi_albert(short int m);

    bool random_graph(float probability);

    void pop_front(vector<short int> &v);

    
    map <short int,vector<short int>> bron_kerbosch();

    void bron_kerbosch_aux(vector<short int> P, vector<short int> R, vector<short int> X, map <short int,vector<short int>> cliquesMAX);

    map <short int,vector<short int>> bron_kerbosch_pivot();

    void bron_kerbosch_pivot_aux(vector<short int> P, vector<short int> R, vector<short int> X, map <short int,vector<short int>> cliquesMAX);

    short int choose_bron_kerbosh_pivot(vector<short int> P, vector<short int> X);

    //Ordre de degenerescence
    vector<short int> ascending_edges();

    //Ordre de degenerescence
    vector<short int> find_degeneracy_order();

    void delete_vertice(short int vertice);

    /*map <short int,vector<short int>>*/
    void bron_kerbosch_degeneracy();

    void add_vertice_algo1(graph g, short int vertice);

    void algo1();

    void algo2();

};