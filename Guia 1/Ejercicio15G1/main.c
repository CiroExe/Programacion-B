#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
    printf("Ingrese 3 numeros:\n");
    scanf("%d %d %d", &num1,&num2,&num3);
    consecutivos(num1,num2,num3);
    return 0;
}


void consecutivos(int a, int b, int c)
{
    if (b == a+1 && c == b+1)
       printf("Los numeros ingresados son consecutivos");
    else
       printf("Los numeros ingresados NO son consecutivos");


    printf("%d", a);
}
