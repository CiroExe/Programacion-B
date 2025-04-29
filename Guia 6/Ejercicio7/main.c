#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodito{
    char titulo[20], autor[20];
    unsigned int anio_edicion;
    struct nodito *sig;
}nodito;
typedef nodito *Sublista;

typedef struct nodoA{
    char autor[20];
    nodito *subLibros;
    struct nodoA *sig;
}nodoA;
typedef nodoA *TListaA;

typedef struct nodoS{
    char socio[20];
    nodito *subLibros;
    struct nodoS *sig;
}nodoS;
typedef nodoS *TListaS;

typedef TListaA TVectorAutores;

void CargaAutores(TListaA []);
void agregaAutor(TListaA [], char []);
void agregaLibro(TListaA [], char [], char[], unsigned int);
void CargaSocios(TListaS *);
void RegistraPrestamos(TListaS ,TListaA []);
void extraeLibro(TListaA [], TListaS, char [], char[], char [], unsigned int);
void insertaLibro(TListaS, char[], nodito*);
void extraeLibroSocio(TListaS , TListaA [], char [], char []);
void insertarLibroAutores(TListaA [], nodito*, unsigned int);

int main()
{
    TListaA Autores[26];
    TListaS Socios;
    unsigned int i;

    for(i=0; i<26; i++)
        Autores[i]=NULL;

    CargaAutores(Autores);
    CargaSocios(&Socios);
    RegistraPrestamos(Socios, Autores);
    RegistraDevoluciones(Socios, Autores);



    return 0;
}


void CargaAutores(TListaA Autores[]){
    FILE *archA;
    unsigned int cantLibros, i, anioEdicion;
    char autor[20], libro[20];


    archA = fopen("autores.txt","r");
    if (archA == NULL)
        printf("No se pudo abrir el archivo\n");
    else{
        while(fscanf(archA, "%s %u", autor, &cantLibros) == 2){
            agregarAutor(Autores, autor);
            for(i = 0; i < cantLibros; i++){
                fscanf(archA,"%s %u", libro, &anioEdicion);
                agregarLibro(Autores,autor ,libro, anioEdicion);
            }
        fclose(archA);
    }
}

void agregaAutor(TListaA Autores[], char autor[]){
    unsigned int indice;
    TListaA aux, ant,nuevo;

    indice=(int)tolower(autor[0])-97;
    nuevo=(TListaA)malloc(sizeof(nodoA));
    strcpy(nuevo->autor, autor);
    nuevo->subLibros = NULL;

    if(Autores[indice] == NULL || strcmp(nuevo->autor, Autores[indice]->autor) < 0){
        nuevo->sig = Autores[indice];
        Autores[indice] = nuevo;
    }
    else{
        aux = Autores[indice];

        while (aux != NULL && strcmp(nuevo->autor, aux->autor) > 0){
            ant = aux;
            aux = aux->sig;
        }

        nuevo->sig = aux;
        ant->sig = nuevo;
    }
}

void agregaLibro(TListaA Autores[], char autor[], char libro[], unsigned int anioEdicion){
    int indice = (int)tolower(autor[0])-97;
    Sublista nuevaSub, actS, antS;
    TListaA aux;

    nuevaSub=(Sublista)malloc(sizeof(nodito));
    strcpy(nuevaSub->autor, autor);
    strcpy(nuevaSub->titulo, libro);
    nuevaSub->anio_edicion=anioEdicion;

    aux = Autores[indice];
    while(aux != NULL && strcmp(nuevaSub->autor, aux->autor) != 0)
        aux = aux->sig;

    if (aux != NULL){

        if (aux->subLibros == NULL || strcmp(nuevaSub->titulo, aux->subLibros->titulo)<0){
            nuevaSub->sig = aux->subLibros;
            aux->subLibros = nuevaSub;
        }
        else{
            antS=aux->subLibros;
            actS= aux->subLibros->sig;
            while (actS != NULL && strcmp(nuevaSub->titulo, actS->titulo)>0){
                antS = actS;
                actS = actS->sig;
            }
            antS->sig = nuevaSub;
            nuevaSub->sig = actS;
        }
    }
    else
        free(nuevaSub); //Libera memoria si no encuentra autor.
}

void CargaSocios(TListaS *Socios){
    FILE *archS;
    TListaS nuevoSocio, act, ant;
    Sublista nuevoLibro, antS, actS;
    unsigned int i, librosPrestados, anioEdicion;
    char socio[20], libro[20], autor[20]; //Mejor declarar una constante.

    archS = fopen("socios.txt","r");
    if(archS == NULL)
        printf("No se pudo abrir el archivo\n");
    else{
        *Socios=NULL;
        while (fscanf(archS,"%s %u", socio, &librosPrestados) == 2){
            nuevoSocio=(TListaS)malloc(sizeof(nodoS));
            strcpy(nuevoSocio->socio, socio);
            nuevoSocio->subLibros = NULL;
            if (*Socios == NULL){
                nuevoSocio->sig = *Socios;
                *Socios = nuevoSocio;
            }
            else{
                ant=NULL;
                act = *Socios;

                while(act != NULL && strcmp(nuevoSocio->socio, act->socio)>0){
                    ant = act;
                    act = act->sig;
                }
                if(ant == NULL){
                    nuevoSocio->sig = act;
                    *Socios=nuevoSocio;
                }
                else{
                    ant->sig = nuevoSocio;
                    nuevoSocio->sig = act;
                }
            }
            for (i=0; i<librosPrestados; i++){
                fscanf(archS,"%s %u %s", libro, &anioEdicion, autor);
                nuevoLibro = (Sublista)malloc(sizeof(nodito));
                nuevoLibro->anio_edicion=anioEdicion;
                strcpy(nuevoLibro->titulo, libro);
                strcpy(nuevoLibro->autor, autor);

                nuevoLibro->sig=nuevoSocio->subLibros;
                nuevoSocio->subLibros= nuevoLibro;
            }
        }
        fclose(archS);
    }
}

void RegistraPrestamos(TListaS Socios, TListaA Autores[]){
    char socio[20], autor[20], libro[20];
    unsigned int indice;

    printf("Ingrese nombre del socio\n");
    scanf("%s", socio);

    printf("Ingrese libro que desea\n");
    scanf("%s", libro);

    printf("Ingrese autor del libro\n");
    scanf("%s", autor);

    indice = (int)tolower(autor[0])-97;
    extraeLibro(Autores, Socios, autor, socio, libro, indice);

    }
}

void RegistraDevoluciones(TListaS Socios, TListaA Autores[]){
    char socio[20], autor[20], libro[20];
    unsigned int indice;

    printf("Ingrese nombre del socio\n");
    scanf("%s", socio);

    printf("Ingrese libro que desea\n");
    scanf("%s", libro);

    printf("Ingrese autor del libro\n");
    scanf("%s", autor);

    indice = (int)tolower(autor[0])-97;
    extraeLibroSocio(Socios, Autores, socio, libro, indice);
}

void extraeLibroSocio(TListaS Socios, TListaA Autores[], char socio[], char libro[], unsigned int indice){
    TListaS aux;
    Sublista actS, antS;
    nodito *libroExtraido;

    aux = Socios;
    //Busco al socio
    while (aux != NULL && strcmp(socio, aux->socio)!= 0)
        aux = aux->sig;

    if(aux != NULL){//Si lo encontró busco el libro.

        if(aux->subLibros != NULL && strcmp(libro, aux->subLibros->titulo) == 0){ //Si es el primero
            libroExtraido = aux->subLibros;
            libroExtraido->sig = NULL;
            aux->subLibros = aux->subLibros->sig;
            insertaLibroAutores(Autores, libroExtraido, indice);
        }
        else{ //Si no es el primero
            antS = aux->subLibros;
            actS = aux->subLibros->sig;
            while (actS != NULL && strcmp(libro, actS->titulo) != 0){
                antS = actS;
                actS = actS->sig;
            }

            if (actS != NULL){
                libroExtraido = actS;
                libroExtraido->sig = NULL;
                antS->sig = actS->sig;
                insertaLibroAutores(Autores, libroExtraido, indice);
            }
            else
                printf("No existe el libro\n");
        }
    }
    else
        printf("No existe el socio\n");
}

void insertarLibroAutores (TListaA Autores[], nodito *libro, unsigned int indice){
    TListaA aux;
    Sublista antS, actS;


    aux = Autores[indice];


    while (aux != NULL && strcmp(libro->autor, aux->autor) != 0) //Busco autor
        aux = aux->sig;

    if (aux != NULL){//Si lo encuentra busco donde insertar el libro
        antS=NULL;
        actS=aux->subLibros;

        while(actS != NULL && strcmp(libro->titulo, actS->titulo) > 0){
            antS= actS;
            actS = actS->sig;
        }

        libro->sig = actS;

        if (antS == NULL)
            aux->subLibros = libro;
        else
            antS->sig = libro;
    }
}

void insertaLibro(TListaS Socios, char socio[],nodito *libro){
    TListaS aux;
    Sublista nuevoLibro, auxS;

    aux = Socios;

    while(aux != NULL && strcmp(socio, aux->socio) != 0) //Busco al socio
        aux = aux->sig;

    if(aux != NULL){ //Si lo encuentra insertar nodito al final de la sublista.

        if (aux->subLibros == NULL)
            aux->subLibros = libro;
        else {
            auxS = aux->subLibros;
            while (auxS->sig != NULL)
                auxS = auxS->sig;
            auxS->sig = libro;
        }
    }
}

void extraeLibro(TListaA Autores[], TListaS Socios,char autor[], char socio[],char libro[],unsigned int indice){
    TListaA aux;
    Sublista actS, antS;
    nodito *nuevoLibro;

    aux = Autores[indice];

    while(aux != NULL && strcmp(autor, aux->autor) != 0)
        aux = aux->sig;

    if (aux != NULL){ //Si encontro al autor, buscar en las sublistas el libro
        if (aux->subLibros != NULL && strcmp(libro, aux->subLibros->titulo) == 0){
            nuevoLibro = aux->subLibros;
            aux->subLibros = aux->subLibros->sig;
            insertaLibro(Socios, socio, nuevoLibro);
        }
        else{
            antS = aux->subLibros;
            actS = aux->subLibros->sig;
            while (actS != NULL && strcmp(libro, actS->titulo) != 0){
                antS = actS;
                actS = actS->sig;
            }

            if (actS != NULL){
                nuevoLibro = actS;
                nuevoLibro->sig = NULL;
                antS->sig = actS->sig;
                insertaLibro(Socios, socio, nuevoLibro);
            }
        }
    }
}



