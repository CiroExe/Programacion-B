typedef int TElementoC;

typedef struct nodo {
    TElementoC dato;
    struct nodo *sig;
}nodo;

typedef struct {
    nodo *pri, *ult;
}TCola;

void iniciaC(TCola *C);
void poneC(TCola *C, TElementoC dato);
void sacaC(TCola *C, TElementoC *dato);
int VaciaC(TCola C);
TElementoC consultaC(TCola C);

