#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
#define MAX_VERTICES 15

class vertices
{
    private:
        short int* verticesList; // Toujours de taille MAX_VERTICES-1
        short int numberOfVerticesInList;

    public:

        /**
         * @brief Constructeur de la classe vertices
         * 
         */
        vertices();

        /**
         * @brief Cree une copie de clonedVertices et la retourne
         * 
         * @param clonedVertices l'objet a copier
         * @return l'objet copie
         */
        vertices cloneVertices();

        void display_vertices();

        /**
         * @brief Retourne la liste de sommets
         * 
         * @return short* la liste de sommets
         */
        short int* get_verticesList();

        /**
         * @brief Retourne le nombre de sommets dans la liste
         * 
         * @return short int le nombre de sommets 
         */
        short int get_number_vertices();

        /**
         * @brief Ajoute un sommet a la liste
         * 
         * @param verticeToAdd le sommet a ajouter
         * @return true si l'ajout s'est bien effectue
         * @return false si l'ajout ne s'est pas effectue
         */
        bool add_vertice(short int verticeToAdd);

        /**
         * @brief Ajoute plusieurs sommets a la liste
         * 
         * @param verticesToAdd les sommets a ajouter
         * @return true si l'ajout s'est bien effectue
         * @return false si l'ajout ne s'est pas effectue
         */
        bool add_vertices(short int* verticesToAdd, short int numberOfVerticesToAdd);


        /**
         * @brief 
         * 
         * @param verticeToDelete 
         * @return true 
         * @return false 
         */
        bool del_vertice(short int verticeToDelete);

        /**
         * @brief verifie si contient le sommet en entree
         * 
         * @param verticeToVerify le sommet a rechercher
         * @return true si sommet trouve
         * @return false sinon
         */
        bool contains(short int verticeToVerify);

};

vertices::vertices(){
    int i;
    this->numberOfVerticesInList = 0;
    this->verticesList = (short int*)malloc(MAX_VERTICES*sizeof(short int));
    for (i = 0; i < MAX_VERTICES; i++)
        this->verticesList[i] = -1;
}

vertices vertices::cloneVertices(){
    vertices verticesToReturn;
    verticesToReturn = vertices();
    int i;
    verticesToReturn.numberOfVerticesInList = this->numberOfVerticesInList;
    for (i = 0; i < MAX_VERTICES; i++)
        verticesToReturn.verticesList[i] = this->verticesList[i];
    /*printf("-%d-",this->verticesList[0]);
    printf("#%d#",verticesToReturn.verticesList[0]);*/
    return verticesToReturn;
}

void vertices::display_vertices(){
    printf("%d : [",this->numberOfVerticesInList);
    int i;
    for (i = 0; i < MAX_VERTICES-1; i++)
    {
        printf("%d, ",this->verticesList[i]);
    }
    printf("%d",this->verticesList[MAX_VERTICES-1]);
    printf("]\n");
}

short int* vertices::get_verticesList(){
    return this->verticesList;
}

short int vertices::get_number_vertices(){
    return this->numberOfVerticesInList;
}

bool vertices::add_vertice(short int verticeToAdd){
    int i;
    if (verticeToAdd < 0 || verticeToAdd > MAX_VERTICES) // sommet en entree incorrecte
        return false;
    
    for (i = 0; i < MAX_VERTICES; i++) // sommet deja dans la liste
        if (this->verticesList[i] == verticeToAdd)
            return false;

    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (this->verticesList[i] == -1)
        {
            this->numberOfVerticesInList += 1;
            this->verticesList[i] = verticeToAdd;
            return true;
        }
    }
    return false;
}

bool vertices::del_vertice(short int verticeToDelete){
    int i,j=0, max = MAX_VERTICES;
    if (verticeToDelete < 0 || verticeToDelete > MAX_VERTICES)
        return false;
    
    for(i=0; i<max; i++)
    {
        if(this->verticesList[i] ==verticeToDelete)
        {
            for(j=i; j<(max-1); j++)
                this->verticesList[j] = this->verticesList[j+1];
            i--;
            max--;
        }
    }
    this->numberOfVerticesInList--;
    return true;    
}

bool vertices::add_vertices(short int* verticesToAdd, short int numberOfVerticesToAdd){
    int i,j;
    if (numberOfVerticesToAdd < 0 || numberOfVerticesToAdd > MAX_VERTICES)
        return false;
    i=j=0;
    while (numberOfVerticesToAdd != 0)
    {
        if (this->verticesList[i] == -1)
        {
            this->numberOfVerticesInList += 1;
            this->verticesList[i] = verticesToAdd[j];
            numberOfVerticesToAdd--;
            j++;
        }
        i++;
    }
    return true;
}


bool vertices::contains(short int verticeToVerify){
    int i;
    for (i = 0; i < MAX_VERTICES; i++)
        if (this->get_verticesList()[i] == verticeToVerify)
            return true;
    return false;
}