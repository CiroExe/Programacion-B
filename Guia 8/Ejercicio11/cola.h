typedef int TElementoC;
typedef struct nodoC{
    TElementoC dato;
    struct nodo*sig;
}nodoC;
typedef struct {
    nodoC *pri, *ult;
}TCola;

void iniciaC(TCola *C);
int VaciaC(TCola C);
void poneC(TCola *C, TElementoC X);
void sacaC(TCola *C, TElementoC *X);
