#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,suma = 0;
    printf("Ingrese numero -->");
    scanf("%d",&num);
    while (num!=0) {
            suma = suma + num;
            printf("Ingrese numero -->\n");
            scanf("%d",&num);

    }
    printf("La suma es --> %d", suma);
    return 0;
}
