#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char palabra[15];
    int frecuencia;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void CargaLista(TLista *);
void MuestraLista(TLista);

int main()
{
    TLista L;
    CargaLista(&L);
    MuestraLista(L);


    return 0;
}

void CargaLista(TLista *L){
    FILE *arch;
    char pal[15];
    TLista ant, nuevo,act;

    *L = NULL;
    arch=fopen("palabras.txt", "r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo\n");
    else{


        while (fscanf(arch, "%s", pal) == 1){
            ant=NULL;
            act=*L;

            //Busco donde insertarlo
            while (act != NULL && strcmp(pal, act->palabra)>0){
                ant = act;
                act = act->sig;
            }
            //Pregunto si hay uno igual, si lo hay aumentar frecuencia
            if (act != NULL && strcmp(pal, act->palabra) == 0)
                (act ->frecuencia)++;
            //Si no existe ninguno igual, crea un nodo nuevo y lo inserta a la lista.
            else{
                nuevo=(TLista)malloc(sizeof(nodo));
                strcpy(nuevo->palabra, pal);
                nuevo ->frecuencia = 1;
                nuevo->sig=act;

                if (ant == NULL)
                    *L=nuevo;
                else{
                    ant->sig=nuevo;
                }
            }
        }
        fclose(arch);
    }
}

void MuestraLista(TLista L){
    while(L != NULL){
        printf("%s\t%d\n", L->palabra, L->frecuencia);
        L= L ->sig;
    }
}
