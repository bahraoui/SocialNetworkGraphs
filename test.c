#include <stdio.h>


int main(int argc, char const *argv[])
{
    short int a[4] = {0,1,2,3};
    printf("%ld\n",sizeof(a)/2);
    return 0;
}
