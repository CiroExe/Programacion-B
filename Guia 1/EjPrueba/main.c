#include <stdio.h>


int main()
{
    int num, i, factorial;


    printf("Ingrese numeros hasta que sea distinto de 0\n");
    do {
        scanf("%d", &num);

        for (i=1, factorial = 1;i<=num;i++){
          factorial = factorial*i;
        }

        printf("El factorial de %d es %d\n", num, factorial);


    } while (num!=0);
    return 0;
}
