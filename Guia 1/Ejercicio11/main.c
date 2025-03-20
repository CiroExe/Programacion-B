#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a > b) ? a:b


int main()
{
    int x=5, y=3;
    printf("El maximo entre %d y %d es --> %d\n", x,y,MAX(x,y));
    return 0;
}
