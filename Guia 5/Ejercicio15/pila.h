#define MAX 256

typedef char TElementoP[20];


typedef struct {
    TElementoP competidores[MAX];
    int tope;
}TPila;

void iniciaP(TPila *P);
void poneP(TPila *P, TElementoP competidor);
void sacaP(TPila *P, TElementoP *competidor);
int VaciaP(TPila P);
