#include <stdio.h>
#include <stdlib.h>

void llenarValores(int **);

int main()
{
    int *n1, *n2, *n3;

    printf("Ingrese valor del numero 1 ->\n");
    printf("%p\n", n1);
    llenarValores(&n1);
    printf("Ingrese valor del numero 2 ->\n");
    llenarValores(&n2);
    printf("Ingrese valor del numero 3->\n");
    llenarValores(&n3);

    printf("Suma -> %d\n", (*n1)+(*n2)+(*n3));
    printf("Multiplicacion -> %d\n", (*n1)*(*n2)*(*n3));

    free(n1);
    free(n2);
    free(n3);

    return 0;
}

void llenarValores(int **n){

    *n=(int *)(malloc(sizeof(int)));
    printf("%p\n", n);
    scanf("%d", *n);


}


