#define MAX 100

typedef char TElementoP[9];

typedef struct {
    TElementoP V[MAX];
    int tope;
} TPila;

void iniciaP(TPila *P);
void poneP(TPila *P, TElementoP dni);
void sacaP(TPila *P, TElementoP *dni);
TElementoP *consultaP(TPila P);
int VaciaP(TPila P);




