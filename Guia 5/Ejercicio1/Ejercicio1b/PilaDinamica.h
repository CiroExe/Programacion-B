
typedef int TElementoP;
typedef struct nodoP{
    TElementoP elem;
    struct nodo *sig;
} nodoP;
typedef nodoP *TPila;


void IniciaP(TPila *P);
int VaciaP(TPila P);
void poneP(TPila *P, TElementoP dato);
void SacaP(TPila *P, TElementoP *dato);
TElementoP consultaP(TPila P);

