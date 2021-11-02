#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX_VERTICES 100

class graph
{
private:
    short int* adjacencyList;
public:
    graph() 
    {
        int i,j;

        adjacencyList = (short int *)malloc((MAX_VERTICES * (MAX_VERTICES-1)) * sizeof(short int));


        for (i = 0; i < MAX_VERTICES * (MAX_VERTICES-1); i++)
        {
            adjacencyList[i]= -1;
        }
    }
    
    short int* get_adjacencyList() {
        return adjacencyList;
    }
};

int main() 
{
    graph mama = graph();

    printf("MAMA : %d\n",mama.get_adjacencyList()[5]);
    
    return 0;
}