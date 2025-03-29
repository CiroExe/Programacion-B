#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch;
    unsigned int suma=0, num;

    arch=fopen("numeros.txt", "r");

    if (arch==NULL)
        printf("El archivo no se pudo abrir");
    else
    {
        while (!feof(arch))
        {
            fscanf(arch,"%d",&num);
            suma+=num;
        }
        fclose(arch);
        printf("La suma de numeros naturales es: %d", suma);

    }

    return 0;
}
