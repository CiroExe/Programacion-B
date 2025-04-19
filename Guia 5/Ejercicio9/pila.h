typedef char TElementoP;

typedef struct nodo {
    TElementoP elem;
    struct nodo *sig;
}nodo;

typedef nodo *TPila;

void iniciaP(TPila *P);
void poneP(TPila *P, TElementoP elem);
void sacaP(TPila *P, TElementoP *elem);
int VaciaP(TPila P);

