#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char dni[9], genero, emitio;
    struct nodo *sig;
}nodo;

typedef nodo *TListaC;

typedef struct{
    char documento[9], genero;
}DocGen;

void CargaLista(TListaC *);
void MuestraLista(TLsitaC);
void votantesFemeninos(TListaC);
void cuentaVotantes(TListaC , unsigned int * , unsigned int *);
int buscaVotante(TListaC , char []);
void eliminaDoc(TListaC *);
void MuestraArchBinario();

int main()
{
    TListaC LC;
    unsigned int contM=0, contF=0;
    char documento[9];


    CargaLista(&LC);
    MuestraLista(LC);


    printf("Votantes del genero femenino que emitieron voto\n");
    votantesFemeninos(LC);

    cuentaVotantes(LC, &contM, &contF);
    printf("Votantes del sexo masculino -> %u\n", contM);
    printf("Votantes del sexo femenino -> %u\n", contF);

    printf("Ingrese dni que desea buscar\t ");
    scanf("%s", documento);
    printf("\n");

    if (buscaVotante(LC, documento))
        printf("Voto\n");
    else
        printf("No voto\n");

    eliminaDoc(&LC);
    MuestraArchBinario();

    return 0;
}


void CargaLista(TListaC *LC){
    FILE *arch;
    char documento[9], sexo, voto;
    TListaC nuevo;



    *LC = NULL;
    arch = fopen("documentos.txt", "r");
    if (arch == NULL)
        printf("No se pudo abrir el archivo\n");
    else{

        while(fscanf(arch, "%s %c %c", documento,&sexo,&voto) == 3){
            nuevo = (TListaC)malloc(sizeof(nodo));
            strcpy(nuevo->dni, documento);
            nuevo->genero = sexo;
            nuevo->emitio = voto;
            if (*LC == NULL){
                nuevo->sig = nuevo;
                *LC = nuevo;
            }
            else{
                nuevo->sig = (*LC)->sig;
                (*LC)->sig = nuevo;
                *LC = nuevo;
            }
        }
    }
    fclose(arch);
}

void MuestraLista(TListaC LC){
    TListaC aux = LC->sig;
    do{
        printf("%s\t %c\t %c\n", aux->dni, aux->genero, aux->emitio);
        aux = aux->sig;
    }while(aux != LC->sig);
}

void votantesFemeninos(TListaC LC){
    TListaC aux = LC->sig;

    do{
        if (aux->genero == 'F' && aux->emitio == 'S')
            printf("%s\n", aux->dni);
        aux = aux->sig;
    }while (aux != LC->sig);
}

void cuentaVotantes(TListaC LC, unsigned int *contM, unsigned int *contF){
    TListaC aux = LC->sig;

    do{
        if (aux->genero == 'M')
            (*contM)++;
        else
            (*contF)++;
        aux = aux->sig;
    }while (aux != LC->sig);
}

int buscaVotante(TListaC LC, char doc[]){
    TListaC aux = LC->sig;

    while(aux != LC && strcmp(doc, aux->dni) != 0)
        aux = aux->sig;


    return (strcmp(doc, aux->dni) == 0) && (aux->emitio =='S');
}

void eliminaDoc(TListaC *LC){
    FILE *archb;
    DocGen reg;
    TListaC ant, act, elim;

    archb = fopen("no_votaron.dat","wb");
    if (archb == NULL)
        printf("No se pudo abrir el archivo");
    else{
        ant = *LC;
        act = (*LC)->sig;

        while (act != *LC){
            if (act->emitio == 'N'){
                elim = act;
                ant->sig = elim->sig;
                act = elim->sig;
                strcpy(reg.documento, elim->dni);
                reg.genero = elim->genero;
                fwrite(&reg, sizeof(DocGen),1, archb);
                free(elim);
            }
            else{
                ant = act;
                act = act->sig;
            }
        }

        if (act->emitio == 'N'){
            if (act->sig = act){
                strcpy(reg.documento, act->dni);
                reg.genero = act->genero;
                fwrite(&reg, sizeof(DocGen),1, archb);
                free(act);
                *LC = NULL;
            }
            else{
                ant->sig = (*LC)->sig;
                *LC = ant;
                strcpy(reg.documento, act->dni);
                reg.genero = act->genero;
                fwrite(&reg, sizeof(DocGen),1, archb);
                free(act);
            }
        }
    }
    fclose(archb);
}

void MuestraArchBinario(){
    FILE *archb;
    DocGen reg;

    archb = fopen("no_votaron.dat","rb");

    if (archb == NULL)
        printf("No se pudo abrir el archivo\n");
    else{
        fread(&reg, sizeof(DocGen), 1 , archb);
        while (!feof(archb)){
            printf("%s %c\n", reg.documento, reg.genero);
            fread(&reg, sizeof(DocGen), 1 , archb);
        }
    }
    fclose(archb);
}


