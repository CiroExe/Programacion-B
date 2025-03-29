#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char apellido[10],nombre[10], nacionalidad[15];
    unsigned int puntaje;

} TTenista;

void generaArch();
void muestraDatos(unsigned short int );


int main()
{
    unsigned int n;

    printf("Ingrese posicion que desea buscar\n");
    scanf("%d",&n);

    generaArch();
    muestraDatos(n);


    return 0;
}


void generaArch()
{
    FILE *archt,*archb;
    TTenista tenista;
    int cont=0;

    archt=fopen("tenistas.txt","r");
    if (archt==NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        archb=fopen("tenistas.dat","wb");
        if (archb==NULL)
        {
            printf("No se pudo abrir el archivo .dat");
            fclose(archt);
        }
        else
        {
            while (fscanf(archt,"%9s %9s %11s %u", tenista.apellido,tenista.nombre ,tenista.nacionalidad,&tenista.puntaje)==4)
            {
                cont+=1;
                fwrite(&tenista, sizeof(TTenista),1,archb);
            }
            printf("%d\n", cont);
            fclose(archt);fclose(archb);
        }
    }
}

void muestraDatos(unsigned short int n)
{
    FILE *archb;
    TTenista tenista;

    archb=fopen("tenistas.dat","rb");
    if (archb==NULL)
        printf("El archivo no se pudo abrir");
    else
    {
        fseek(archb,n*sizeof(TTenista),SEEK_SET);
        fread(&tenista, sizeof(TTenista),1,archb);
        printf("%s %s %s %d",tenista.apellido,tenista.nombre, tenista.nacionalidad, tenista.puntaje);
        fclose(archb);

    }

}
