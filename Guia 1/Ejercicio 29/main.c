#include <stdio.h>
#include <stdlib.h>
void generaArch();
void leeArch();


int main()
{
    generaArch();
    leeArch();
    return 0;
}


void generaArch()
{
    FILE *archt, *archb;
    float temperatura;

    archt=fopen("temperatura.txt", "r");

    if (archt==NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        archb=fopen("temperatura.dat","wb");
        if (archb==NULL)
        {
            printf("No se pudo abrir el archivo .dat");
            fclose(archt);
        }
        else
        {
            while (!feof(archt))
            {
                fscanf(archt,"%f\n",&temperatura);
                fwrite(&temperatura, sizeof(float),1,archb);
            }
            fclose(archt);fclose(archb);
        }
    }
}

void leeArch()
{
    FILE *archb;
    float temperatura,min=999, max=-999, prom,acum=0;
    unsigned int cont=0;

    archb=fopen("temperatura.dat","rb");
    if (archb==NULL)
        printf("No se pudo abrir el archivo .dat");
    else
    {
        fread(&temperatura, sizeof(float),1,archb);
        while (!feof(archb))
        {
            cont++;
            acum+=temperatura;
            if (temperatura > max)
                max=temperatura;
            if (temperatura < min)
                min=temperatura;

            fread(&temperatura,sizeof(float),1,archb);

        }
        fclose(archb);
        printf("Temperatura Maxima -> %.2f\n",max);
        printf("Temperatura Minima -> %.2f\n",min);
        printf("Temperatura Promedio -> %.2f\n",acum/cont);
    }
}
