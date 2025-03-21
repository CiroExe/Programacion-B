#include <stdio.h>
#include <stdlib.h>
void ordenadas(int *, int *);
int main(){
    int a = 30, b = 20;
    printf(" valor de a %d\tvalor de b %d antes\n", a, b);
    ordenadas(&a, &b);
    printf(" valor de a %d\tvalor de b %d\n", a, b);
    return 0;
}


void ordenadas(int *x, int *y){
    int aux;
    if(*x > *y) {
        aux = *x;
        *x =*y;
        *y = aux;
    }
}
