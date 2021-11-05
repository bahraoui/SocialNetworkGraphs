#define MAX_VERTICES 15

class vertices
{
    private:
        short int* verticesList;
        short int numberOfVerticesInList;

    public:

        /**
         * @brief Constructeur de la classe vertices
         * 
         */
        vertices();

        /**
         * @brief Retourne la liste de sommets
         * 
         * @return short* 
         */
        short int* get_verticesList();

        /**
         * @brief Retourne le nombre de sommets dans la liste
         * 
         * @return short int 
         */
        short int get_number_vertices();

};

vertices::vertices(){
    int i;
    this->numberOfVerticesInList = 0;
    this->verticesList = (short int*)malloc(MAX_VERTICES*sizeof(short int));
    for (i = 0; i < MAX_VERTICES; i++)
        this->verticesList[i] = -1;
}

short int* vertices::get_verticesList(){
    return verticesList;
}

short int vertices::get_number_vertices(){
    return this->numberOfVerticesInList;
}