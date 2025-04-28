#include <stdio.h>
#include <stdlib.h>
typedef struct nodoS{
    char estado, jugador[20];
    unsigned int edad;
    struct nodoS *sig;
}nodoS;
typedef nodoS *Sublista;

typedef struct nodoL{
    char club[15];
    unsigned int puntaje;
    struct nodoL *sig;
    nodoS *sub;
}nodoL;
typedef nodoL *TLista;


void CargaLista(TLista *);
void MuestraLista(TLista);
void IncisoA(TLista , char);
void IncisoB(TLista, unsigned int);
int Cumple(TLista, char [], unsigned int);
void Elimina(TLista );

int main()
{
    TLista L;
    char K, E[20];
    unsigned int X, P;

    printf("Ingrese letra\n");
    scanf("%c", &K);

    CargaLista(&L);
    MuestraLista(L);
    printf("\n");
    IncisoA(L, K);

    printf("Ingrese puntaje: \n");
    scanf("%u", &X);
    IncisoB(L, X);

    printf("Ingrese club a buscar: \n");
    scanf("%s", E);
    printf("Ingrese puntaje: \n");
    scanf("%u", &P);
    Cumple(L,E,P)? printf("El equipo %s tiene %u puntos\n\n", E, P) : printf("El equipo %s no suma %u puntos\n\n", E, P);

    Elimina(L);
    MuestraLista(L);


    return 0;
}

void CargaLista(TLista *L){
    FILE *arch;
    unsigned int i,puntos, cantJugadores, edad;
    char estado, nombre_jugador[20], equipo[15];
    TLista aux, nuevoLista, actL, antL;
    Sublista nuevoSub;

    *L = NULL;

    arch = fopen("clubes.txt","r");
    if(arch == NULL)
        printf("No se pudo abrir el archivo");
    else{

        while(fscanf(arch,"%s %u %u",equipo,&puntos,&cantJugadores) == 3){
            nuevoLista=(TLista)malloc(sizeof(nodoL));
            strcpy(nuevoLista->club, equipo);
            nuevoLista->puntaje = puntos;
            nuevoLista->sub = NULL;

            if(*L == NULL){
                nuevoLista->sig = NULL;
                *L = nuevoLista;
            }
            else{
                actL = *L;
                antL = NULL;
                while(actL != NULL && (nuevoLista->puntaje < actL->puntaje || nuevoLista->puntaje == actL->puntaje && strcmp(nuevoLista->club, actL->club) > 0)){
                    antL = actL;
                    actL = actL->sig;
                }

                if(antL == NULL){
                    nuevoLista->sig = *L;
                    *L = nuevoLista;
                }
                else{
                    antL->sig = nuevoLista;
                    nuevoLista->sig = actL;
                }
            }
            for (i=0; i<cantJugadores; i++){
                fscanf(arch,"%s %u %c",nombre_jugador, &edad, &estado);
                nuevoSub=(Sublista)malloc(sizeof(nodoS));
                strcpy(nuevoSub->jugador, nombre_jugador);
                nuevoSub->edad = edad;
                nuevoSub->estado = estado;
                nuevoSub->sig=NULL;

                if(nuevoLista->sub == NULL)
                    nuevoLista->sub = nuevoSub;
                else{
                    nuevoSub->sig = nuevoLista->sub;
                    nuevoLista->sub = nuevoSub;
                    }
                }

        }
        fclose(arch);
    }
}

//a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
//finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
//cumplan el criterio solicitado.

void IncisoA(TLista L, char K){
    int contListados, max, contClub, contJugadores;
    Sublista actS;
    char maxClubes[20];

    contListados = 0;
    max = -1;
    while(L != NULL){
        contClub = 0;
        actS = L->sub;
        while(actS != NULL){
            if (toupper(actS->jugador[0]) == toupper(K)){
                contClub++;
                contListados++;
                printf("%s\n", actS->jugador);
            }
            actS = actS->sig;
        }

        if (contClub > max){
            max = contClub;
            strcpy(maxClubes, L->club);
        }
        L = L->sig;
    }
    printf("%d jugadores fueron listados\n", contListados);
    printf("El club que mas jugadores cumplieron la condicion fue: %s\n",maxClubes);
}

// b)Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
//   mostrando edad promedio de cada equipo.

void IncisoB(TLista L, unsigned int X){
    Sublista actS;
    unsigned int acumEdad, contJugadores;


    while (L != NULL){
        acumEdad=0;
        contJugadores=0;
        if (L->puntaje >= X){
            printf("%s\n", L->club);
            actS = L->sub;
            while(actS != NULL){
                acumEdad += actS->edad;
                contJugadores++;
                printf("%s\n", actS->jugador);
                actS = actS -> sig;
            }
            printf("Edad promedio del equipo: %2.2f años\n",(float)acumEdad / contJugadores);
        }
        L = L->sig;
        printf("\n");
    }
}

//c) Verificar si el equipo E (dato) tiene P (dato) puntos.
int Cumple(TLista L, char E[20], unsigned int P){
    while (L != NULL && strcmp(L->club, E) != 0)
        L = L->sig;

    if (strcmp(L->club, E) == 0 && L->puntaje == P)
        return 1;
    else
        return 0;
}


// d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos.
void Elimina(TLista L){
    Sublista actS, elim,antS;

    while(L != NULL){
        if (L->sub->estado == 'S'){
            elim = L->sub;
            if (L->sub->sig == NULL)
                L->sub = NULL;
            else{
                L->sub = elim->sig;
            }
            free(elim);
        }
        else{
            antS = L->sub;
            actS = L->sub->sig;
            while(actS != NULL){
                if (actS->estado == 'S'){
                    elim = actS;
                    antS->sig = actS->sig;
                    actS = elim -> sig;
                    free(elim);
                }
                else{
                    antS = actS;
                    actS = actS->sig;
                }
            }
        }
        L = L->sig;
    }
}

void MuestraLista(TLista L){
    Sublista actS;

    while(L != NULL){
        printf("%s\n", L->club);
        actS=L->sub;
        while(actS != NULL){
            printf("%s\n", actS->jugador);
            actS = actS->sig;
        }
        printf("\n");
        L = L->sig;
    }
}





