typedef char TElementoC;

typedef struct nodoC {
    TElementoC dato;
    struct nodoC *sig;
}nodoC;

typedef struct {
    nodoC *pri, *ult;
}TCola;

void iniciaC(TCola *C);
void poneC(TCola *C, TElementoC dato);
void sacaC(TCola *C, TElementoC *dato);
int VaciaC(TCola C);
