#include <stdio.h>
#include <stdlib.h>
//El Archivo contiene en cada linea: Patente, Velocidad registrada, Velocidad maxima permitida, fecha y hora de la medicion.

typedef struct {
    char patente[7],fecha[11],hora[6];
    int velocidad_registrada, velocidad_maxima;
 } TRadar;

void generaArchBin();

int main()
{
    generaArchBin();
    return 0;
}

void generaArchBin()
{
    FILE *archt, *archb;
    TRadar registro;
    unsigned int mediciones=0, procesados=0;

    archt=fopen("radar_vigia.txt", "r");
    if (archt==NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        archb=fopen("superan_velocidad.dat","wb");
        if (archb==NULL)
        {
            printf("No se pudo abrir el archivo");
            fclose(archt);
        }
        else
        {


            while (fscanf(archt,"%s %d %d %s %s\n", registro.patente, &registro.velocidad_registrada,&registro.velocidad_maxima,registro.fecha,registro.hora)==5)
            {
                mediciones+=1;

                if (registro.velocidad_registrada > registro.velocidad_maxima*1.20)
                {
                    procesados+=1;
                    fwrite(&registro, sizeof(TRadar),1,archb);

                }
            }
            fclose(archt);fclose(archb);
            printf("Cantidad de mediciones: %d\n", mediciones);
            printf("Cantidad de procesamientos en el archivo binario: %d\n", procesados);

            archb=fopen("superan_velocidad.dat", "rb");
            fread(&registro, sizeof(TRadar),1,archb);
            while (!feof(archb))
            {
                printf("%s %d %d %s %s\n", registro.patente, registro.velocidad_registrada, registro.velocidad_maxima, registro.fecha, registro.hora);
                fread(&registro, sizeof(TRadar),1,archb);
            }
        }

    }

}
