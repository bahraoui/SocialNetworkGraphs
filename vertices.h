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
         * @brief Supprime un sommet de la liste
         * 
         * @param verticeToDelete le sommet a supprimer
         * @return true si la suppression a bien ete efffectue
         * @return false si la suppresion n'a pas ete fait
         */
        bool del_vertice(short int verticeToDelete);

};

vertices::vertices(){
    int i;
    this->numberOfVerticesInList = 0;
    this->verticesList = (short int*)malloc(MAX_VERTICES*sizeof(short int));
    for (i = 0; i < MAX_VERTICES; i++)
        this->verticesList[i] = -1;
}

vertices vertices::cloneVertices(){
    vertices verticesToReturn = vertices();
    int i;
    verticesToReturn.numberOfVerticesInList = this->numberOfVerticesInList;
    for (i = 0; i < MAX_VERTICES; i++)
        verticesToReturn.verticesList[i] = this->verticesList[i] ;
    printf("-%d-",this->verticesList[0]);
    printf("#%d#",verticesToReturn.verticesList[0]);
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
    return verticesList;
}

short int vertices::get_number_vertices(){
    return this->numberOfVerticesInList;
}

bool vertices::add_vertice(short int verticeToAdd){
    int i;
    if (verticeToAdd < 0 || verticeToAdd > MAX_VERTICES)
        return false;
    
    for (i = 0; i < MAX_VERTICES; i++)
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
    int i;
    if (verticeToDelete < 0 || verticeToDelete > MAX_VERTICES)
        return false;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        if (this->verticesList[i]==verticeToDelete)
        {
            this->verticesList[i] = -1;
            this->numberOfVerticesInList -= 1;
            return true;
        }
    }
    return false;    
}

bool vertices::add_vertices(short int* verticesToAdd, short int numberOfVerticesToAdd){
    int i,j,cmpt=0;
    if (numberOfVerticesToAdd < 0 || numberOfVerticesToAdd > MAX_VERTICES)
        return false;
    for ( j = 0; j < numberOfVerticesToAdd; j++)
    {
        if (verticesToAdd[j] < 0 || verticesToAdd[j] > MAX_VERTICES) // valeur incorrecte
            continue;
        
        for (i = 0; i < MAX_VERTICES; i++)
            if (this->verticesList[i] == verticesToAdd[j]) // valeur deja dans la liste
                continue;

        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (this->verticesList[i] == -1)
            {
                this->numberOfVerticesInList += 1;
                this->verticesList[i] = verticesToAdd[cmpt];
                cmpt++;
            }
        }
    }
    return true;
}