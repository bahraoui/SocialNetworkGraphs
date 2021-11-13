#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <thread>

#define SIZE_SHORT_INT 2
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

public:
    
    graph() 
    {
    }

    short int get_numberVertices(){
        return 0;
    }

    short int get_totalDegree(){
        int totalDegree;
        for (long unsigned int i = 0; i < get_adjancyList().size(); i++) {
           totalDegree += (int)(get_adjancyList()[i].size());
        }
        return totalDegree;
    }
    
    map<int, vector<int>> get_adjancyList() {
        return adjancyList;
    }
    

    /**
     * Affiche le graphe 
    */

    void display_graph(){
        printf("\nAffichage du graphe via liste d'adjacence (%d sommets possibles): \n##################################\n\n",MAX_VERTICES);
        for (long unsigned int i = 0; i < adjancyList.size(); i++)
        {
            for (long unsigned int j = 0; j < adjancyList[i].size();j++)
            {
                printf(" %d ", adjancyList[i][j]);
            }
            printf("\n");
        }
        printf("\n##################################\n\n");
    }

    void add_vertice(int numberVerticeToAdd){
        int i;
        for (i = 0; i < numberVerticeToAdd; i++) {
            vector<int> v (0, {});
            adjancyList.insert(pair<int, vector<int>>(i, v));
        }
        
    }

    bool add_edge(short int verticeSrc, short int verticeDest){
        if (verticeDest==verticeSrc || verticeDest < 0 || verticeSrc < 0 || verticeDest >= MAX_VERTICES || verticeSrc >= MAX_VERTICES)
            return false; // les valeurs donnees sont incorrects
        
        adjancyList[verticeSrc].push_back(verticeDest);
        adjancyList[verticeDest].push_back(verticeSrc);

        return true;
    }

    
    int get_number_neighbors(short int verticeNumber) {
        int numberNeighbors = 0;

        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size(); i++)
            numberNeighbors++;

        return numberNeighbors;
    }

    

    vector<short int> get_neighbors(short int verticeNumber){
        vector<short int> neighbors = {};
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size() ; i++)
            neighbors.push_back(get_adjancyList()[verticeNumber][i]);
        return neighbors;
    }

    

    vector<short int> get_neighbors_intersection(short int verticeNumber, vector<short int> verticesToLook){
        vector<short int> neighbors;
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size() ; i++)
        {
            if (count(verticesToLook.begin(), verticesToLook.end(), get_adjancyList()[verticeNumber][i])) {
                neighbors.push_back(get_adjancyList()[verticeNumber][i]);
            }
        }
                
        return neighbors;
    }

    

    bool is_graph_valid() {
        if ((int)(get_adjancyList().size()) > 0){
            return true;
        }
        return false;
    }

    bool result_probability(float probability) {
        float r = ((double) rand() / (RAND_MAX));
        //printf("%f -- %f\n",r,probability);
        if (r <= probability) 
            return true;
        return false;
    }

    void barabasi_albert(short int m) {
        if (!is_graph_valid()){
            return;
        }

        long unsigned int i = 0;
        float barabasiAlbertProbability;

        //graphe n sommet

        //Ajout d'un nouveau noeud
        add_vertice(1);

        //graphe n sommet + 1 noeud sans arrete

        while (m > 0 && i < get_adjancyList().size()-1) {
            //calcul proba
            barabasiAlbertProbability = (float)get_number_neighbors(i)/get_totalDegree();
            if (result_probability(barabasiAlbertProbability)) {
                add_edge((int)(get_adjancyList().size()),i);
                m--;
            }
            i++;
        }
    }

    bool random_graph(float probability){
        int cmpt=0;
        if (probability < 0.0001 || probability > 0.9999) // on verifie que la proba donnee est correcte
            return false;
        //display_matrix();
        for (long unsigned int i = 0; i < get_adjancyList().size(); i++) // chaque sommet existant
        {
            for (long unsigned int j = 0; j < get_adjancyList()[i].size();  j++) { // chaque voisin du sommet i
                if (result_probability(probability))
                    add_edge(i,j);
            }
        }
        return cmpt;
    }

    void pop_front(vector<short int> &v)
    {
        if (v.size() > 0) {
            v.erase(v.begin());
        }
    }

    
    map <short int,vector<short int>> bron_kerbosch(){
        map <short int,vector<short int>>cliquesMax;
        vector<short int> P = {}, R = {}, X = {};

        for (long unsigned int i = 0; i < get_adjancyList().size() ; i++) // on remplit P avec les sommets du graphe
            P.push_back(i);

        printf("Initialisation \n [");
        for(long unsigned int i = 0; i < P.size(); i++)
            printf(" %d ",P[i]);
        printf("]\n\n");

        bron_kerbosch_aux(P,R,X,cliquesMax);
        return cliquesMax; // toutes les cliques ùaximales
    }

    void bron_kerbosch_aux(vector<short int> P, vector<short int> R, vector<short int> X, map <short int,vector<short int>> cliquesMAX){
        if (P.empty() && X.empty() )
        {
            printf("Clique MAX trouve : [");
            for(int i = 0; i < (int)(R.size()); i++)
                printf(" %d ",R[i]);
            printf("]\n\n");
            //return;
        }

        vector<short int> Ploop = P;

        for (long unsigned int i = 0; i < Ploop.size(); i++) // Pour chaque sommet v de P
        {
            vector<short int> Pinter = {}, Runion = {}, Xinter = {};

            short int v = Ploop[i];
            auto neighborsIterator = adjancyList.find(v);

            for (long unsigned int j = 0; j < neighborsIterator->second.size(); j++)
            {   
                // Création de l'intersection P               
                if (count(P.begin(), P.end(), neighborsIterator->second[j])) {
                    Pinter.push_back(neighborsIterator->second[j]);
                }
                // Création de l'intersection X
                if (count(X.begin(), X.end(), neighborsIterator->second[j])) {
                    Xinter.push_back(neighborsIterator->second[j]);
                }         
            }
            
            Runion = R;
            Runion.push_back(v);

            bron_kerbosch_aux(Pinter,Runion,Xinter,cliquesMAX);

            X.push_back(v);
            remove(P.begin(),P.end(),v);
        }
        
    }



    map <short int,vector<short int>> bron_kerbosch_pivot(){
        map <short int,vector<short int>>cliquesMax;
        vector<short int> P = {}, R = {}, X = {};

        for (long unsigned int i = 0; i < get_adjancyList().size() ; i++) // on remplit P avec les sommets du graphe
            P.push_back(i);

        printf("Initialisation \n [");
        for(long unsigned int i = 0; i < P.size(); i++)
            printf(" %d ",P[i]);
        printf("]\n\n");

        bron_kerbosch_pivot_aux(P,R,X,cliquesMax);
        return cliquesMax; // toutes les cliques ùaximales
    }

    void bron_kerbosch_pivot_aux(vector<short int> P, vector<short int> R, vector<short int> X, map <short int,vector<short int>> cliquesMAX){
        if (P.empty() && X.empty() )
        {
            printf("Clique MAX trouve : [");
            for(int i = 0; i < (int)(R.size()); i++)
                printf(" %d ",R[i]);
            printf("]\n\n");
            return;
        }

        //choose a pivot u ∈ P∪X
        short int u = choose_bron_kerbosh_pivot(P,X);
        auto uNeighbors = adjancyList.find(u);

        vector<short int> Ploop;

        for (long unsigned int i = 0; i < P.size(); i++)
        {   
            // Création de l'intersection Ploop             
            if (!count(uNeighbors->second.begin(), uNeighbors->second.end(), P[i])) {
                Ploop.push_back(P[i]);
            }  
        }

        for (long unsigned int i = 0; i < Ploop.size(); i++) // Pour chaque sommet v de P
        {
            vector<short int> Pinter = {}, Runion = {}, Xinter = {};

            short int v = Ploop[i];
            auto neighborsIterator = adjancyList.find(v);

            for (long unsigned int j = 0; j < neighborsIterator->second.size(); j++)
            {   
                // Création de l'intersection P               
                if (count(P.begin(), P.end(), neighborsIterator->second[j])) {
                    Pinter.push_back(neighborsIterator->second[j]);
                }
                // Création de l'intersection X
                if (count(X.begin(), X.end(), neighborsIterator->second[j])) {
                    Xinter.push_back(neighborsIterator->second[j]);
                }         
            }
            
            Runion = R;
            Runion.push_back(v);

            bron_kerbosch_pivot_aux(Pinter,Runion,Xinter,cliquesMAX);

            X.push_back(v);
            remove(P.begin(),P.end(),v);
        }
        
    }

    short int choose_bron_kerbosh_pivot(vector<short int> P, vector<short int> X) {
        
        if (!P.empty()) {
            return P[0];
        }
        else if (!X.empty()) {
            return X[0];
        }
        return -1;
    }
};