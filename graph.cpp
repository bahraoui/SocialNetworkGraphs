#include "graph.h"


    graph::graph() 
    {
    }

    short int graph::get_totalDegree(){
        int totalDegree;
        for (long unsigned int i = 0; i < get_adjancyList().size(); i++) {
           totalDegree += (int)(get_adjancyList()[i].size());
        }
        return totalDegree;
    }
    
    map<int, vector<int>> graph::get_adjancyList() {
        return adjancyList;
    }
    

    void graph::display_graph(){
        printf("##################################\n\n");
        map<int, vector<int>>::iterator it;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++) {
            for (long unsigned int j = 0; j < it->second.size();j++)
            {
                printf(" %d ", it->second[j]);
            }
            printf("\n");
        }
        printf("\n##################################\n\n");
    }

    void graph::add_vertice(int numberVerticeToAdd){
        int i;
        for (i = 0; i < numberVerticeToAdd; i++) {
            vector<int> v (0, {});
            adjancyList.insert(pair<int, vector<int>>(i, v));
        }
        
    }

    bool graph::add_edge(short int verticeSrc, short int verticeDest){
        if (verticeDest==verticeSrc || verticeDest < 0 || verticeSrc < 0 || verticeDest >= MAX_VERTICES || verticeSrc >= MAX_VERTICES)
            return false; // les valeurs donnees sont incorrects
        
        adjancyList[verticeSrc].push_back(verticeDest);
        adjancyList[verticeDest].push_back(verticeSrc);

        return true;
    }

    
    int graph::get_number_neighbors(short int verticeNumber) {
        return get_adjancyList()[verticeNumber].size();
    }

    

    vector<short int> graph::get_neighbors(short int verticeNumber){
        vector<short int> neighbors = {};
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size() ; i++)
            neighbors.push_back(get_adjancyList()[verticeNumber][i]);
        return neighbors;
    }

    

    vector<short int> graph::get_neighbors_intersection(short int verticeNumber, vector<short int> verticesToLook){
        vector<short int> neighbors;
        for (long unsigned int i = 0; i < get_adjancyList()[verticeNumber].size() ; i++)
        {
            if (count(verticesToLook.begin(), verticesToLook.end(), get_adjancyList()[verticeNumber][i])) {
                neighbors.push_back(get_adjancyList()[verticeNumber][i]);
            }
        }
                
        return neighbors;
    }

    

    bool graph::is_graph_valid() {
        if ((int)(get_adjancyList().size()) > 0){
            return true;
        }
        return false;
    }

   
    void graph::barabasi_albert(short int m) {
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

    bool graph::random_graph(float probability){
        if (probability < 0.0001 || probability > 0.9999) // on verifie que la proba donnee est correcte
            return false;

        for (long unsigned int i = 0; i < get_adjancyList().size(); i++) // chaque sommet existant
            for (long unsigned int j = 0; j < get_adjancyList()[i].size();  j++) // chaque voisin du sommet i
                if (result_probability(probability))
                    add_edge(i,j);
        return true;
    }

    void graph::pop_front(vector<short int> &v)
    {
        if (v.size() > 0) {
            v.erase(v.begin());
        }
    }

    
    map <short int,vector<short int>> graph::bron_kerbosch(){
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

    void graph::bron_kerbosch_aux(vector<short int> P, vector<short int> R, vector<short int> X, map <short int,vector<short int>> cliquesMAX){
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


    map <short int,vector<short int>> graph::bron_kerbosch_pivot(){
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

    void graph::bron_kerbosch_pivot_aux(vector<short int> P, vector<short int> R, vector<short int> X, map <short int,vector<short int>> cliquesMAX){
        if (P.empty() && X.empty() )
        {
            printf("Clique MAX trouve : [");
            for(long unsigned int i = 0; i < R.size(); i++)
                printf(" %d ",R[i]);
            printf("]\n\n");
            return;
        }

        //choose a pivot u ∈ P∪X
        short int u = choose_bron_kerbosh_pivot(P,X);
        printf("CHOIX DE U : %d\n",u);
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

    short int graph::choose_bron_kerbosh_pivot(vector<short int> P, vector<short int> X) {
        vector<short int> neighbors = {};
        int max = -1, actual;
        short int u;
        for (long unsigned int i = 0; i < P.size(); i++)
        {
            actual = get_neighbors_intersection(P[i],P).size();
            if (actual > max) {
                max = actual; u = P[i];
            }
        }
        for (long unsigned int i = 0; i < X.size(); i++)
        {   
            actual = get_neighbors_intersection(X[i],X).size();
            if (actual > max) {
                max = actual; u = X[i];
            }
        }

        return u;
    }

    //Ordre de degenerescence
    vector<short int> graph::ascending_edges() {
        vector<short int> ascendingEdges = {};
        short int v;
        map<int, vector<int>>::iterator it;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++)
        {
            ascendingEdges.push_back(it->first);
        }

        for (long unsigned int i = 0; i < ascendingEdges.size(); i++)
        {
            for (long unsigned int j = 0; j < ascendingEdges.size(); j++)
            {
                if (get_number_neighbors(ascendingEdges[i]) < get_number_neighbors(ascendingEdges[j])) {
                    v = ascendingEdges[i];
                    ascendingEdges[i] = ascendingEdges[j];
                    ascendingEdges[j] = v;
                }
            }       
        }
        return ascendingEdges;
    }

    //Ordre de degenerescence
    vector<short int> graph::find_degeneracy_order() {
        vector<short int> ascendingEdges = ascending_edges();
        vector<short int> degeneracyOrder = {};
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

    void graph::delete_vertice(short int vertice) {
        vector<short int> neighbors = get_neighbors(vertice);

        for (long unsigned int i = 0; i < neighbors.size(); i++)
            for (long unsigned int j = 0; j < adjancyList[neighbors[i]].size(); j++) 
                if (adjancyList[neighbors[i]][j] == vertice)
                    adjancyList[neighbors[i]].erase(adjancyList[neighbors[i]].begin()+j);
        
        adjancyList.erase(vertice);  
    }

    void graph::bron_kerbosch_degeneracy(){
        map <short int,vector<short int>>cliquesMax;
        vector<short int> P = {}, degeneracyOrder = {}, X = {}, degeneracyP= {}, degeneracyX = {}, viBKP = {};
        short int vi;

        degeneracyOrder = find_degeneracy_order();
        degeneracyP = degeneracyOrder;
        for (long unsigned int i = 0; i < degeneracyOrder.size(); i++)
        {
            vi = degeneracyOrder[i];

            degeneracyP.erase(degeneracyP.begin());
            P = get_neighbors_intersection(vi,degeneracyP);

            X = get_neighbors_intersection(vi,degeneracyX);
            degeneracyX.push_back(vi);

            viBKP = {};
            viBKP.push_back(vi);
            bron_kerbosch_pivot_aux(P, viBKP ,X, cliquesMax);
        }        
        //return cliquesMax; // toutes les cliques ùaximales
    }

    void graph::add_vertice_algo1(graph g, short int vertice){
        vector<short int> vertices = {};
        map<int, vector<int>>::iterator it;
        graph g2 = g;

        for (it = adjancyList.begin(); it != adjancyList.end(); it++) {
            vertices.push_back(it->first);
        }
        vertices.push_back(vertice);

        
        for (long unsigned int i = 0; i < g.adjancyList.size(); i++)
        {
            if (!count(vertices.begin(), vertices.end(), i)){
                g2.delete_vertice(i);
            }
        }
        *(this) = g2;
    }

    void graph::algo1() {
        map <short int,vector<short int>>cliquesMax;
        vector<short int> degeneracyOrder = {};
        graph Gj;

        // k ? 

        degeneracyOrder = find_degeneracy_order();

        for (long unsigned int i = 0; i < degeneracyOrder.size(); i++)
        {
            //creer un graphe vide
            //ajouter le sommet j
            Gj.add_vertice_algo1(*(this),degeneracyOrder[i]);
            //bk
            //for chaque clique K de Gj
                //degen
                //if count search k dans t
                    //suppr click
                //else
                    // ?????
                    //renvoyer k
        }
        
    }

    void graph::algo2() {
        
        
    }