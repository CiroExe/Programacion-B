

void arrgrado2(arbol a, char v[N], int dimv) {
  if (a != NULL) {
    if(a->izq != NULL && a->der == NULL) {/* grado 2 */ //La condicion deberia ser igual para los dos casos de otra manera seria de grado1
       (*dimv)++;  //No fue pasado como parametro puntero no hace falta "*"
       v[dimv] = a->dato;
    } else
       arrgrado2(a->izq, v[], dimv); //No hace falta pasar v[], se puede pasar solo v
       arrgrado2(a->der, v[], dimv);
  }
}

void arrgrado2(arbol a, char v[], int *dimv){
    if(a != NULL)
        if(a->izq != NULL && a->der != NULL){
            (*dimv)++;
            v[*dimv] = a->dato;
        }
        else{
            arrgrado2(a->izq, v, *dimv);
            arrgrado2(a->der, v, *dimv);
        }
}
