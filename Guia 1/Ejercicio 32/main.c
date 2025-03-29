#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ciudad[20];
    unsigned short int dia;
    float max_temp, min_temp;
}TTemperatura;

void generaArch();
void muestraCiudades();
void corteControl();

int main()
{
    generaArch();
    muestraCiudades();
    corteControl();
    return 0;
}


void generaArch()
{
    FILE *archt, *archb;
    TTemperatura registro;

    archt=fopen("temperaturas.txt","r");
    if (archt==NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        archb=fopen("temperaturas.dat","wb");
        if (archb==NULL)
        {
            printf("No se pudo abrir el archivo .dat");
            fclose(archt);
        }
        else
        {
            while (fscanf(archt,"%s %d %f %f", registro.ciudad, &registro.dia,&registro.max_temp,&registro.min_temp)==4)
                    fwrite(&registro, sizeof(TTemperatura),1,archb);

            fclose(archt);fclose(archb);
        }
    }
}

void muestraCiudades()
{
    FILE *archb;
    TTemperatura registro;


    archb=fopen("temperaturas.dat","rb");
    if (archb!=NULL)
    {
        while(fread(&registro,sizeof(TTemperatura),1,archb)==1)
            printf("%s %d %.2f %.2f\n",registro.ciudad, registro.dia,registro.max_temp, registro.min_temp);

        fclose(archb);
    }
}

void corteControl()
{
    FILE *archb;
    TTemperatura registro;
    float minCiudad=999,min,max;
    unsigned short int diaMin;
    char ciudadAct[20], ciudad_minTemp[20];


    archb=fopen("temperaturas.dat","rb");
    printf("CIUDADES      TEMPERATURA MAXIMA       TEMPERATURA MINIMA\n");
    if (archb==NULL)
        printf("No se pudo abrir el archivo");
    else
    {

        while (fread(&registro,sizeof(TTemperatura),1,archb)==1)
        {
            strcpy(ciudadAct, registro.ciudad);
            printf("%s \t\t", ciudadAct);
            min=999;max=-999;
            while (fread(&registro,sizeof(TTemperatura),1,archb)==1 && strcmp(ciudadAct,registro.ciudad)==0)
            {
                if (registro.min_temp<minCiudad)
                {
                    minCiudad=registro.min_temp;
                    diaMin=registro.dia;
                    strcpy(ciudad_minTemp,registro.ciudad);
                }

                if (registro.min_temp<min)
                    min=registro.min_temp;

                if (registro.max_temp>max)
                    max=registro.max_temp;
            }
            printf("%.2f\t\t %.2f\n",max, min);


        }
        printf("La menor temperatura (° %.2f) la tuvo la ciudad %s el dia %d\n",minCiudad, ciudad_minTemp, diaMin);
        fclose(archb);
    }
}
