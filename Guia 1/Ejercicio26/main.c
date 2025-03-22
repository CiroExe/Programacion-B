#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[20];
    int matricula;
    float prom;
} TAlumno;

void creaStruct(TAlumno *);
void muestraAlumno(TAlumno);

int main()
{
    TAlumno alumno;
    creaStruct(&alumno);
    muestraAlumno(alumno);
    return 0;
}

void creaStruct(TAlumno *alumno)
{
    printf("Ingrese nombre del alumno: ");
    gets(alumno->nom);

    printf("Ingrese matricula del estudiante: ");
    scanf("%d", &alumno->matricula);

    printf("Ingrese promedio del estudiante: ");
    scanf("%f", &alumno->prom);
}

void muestraAlumno(TAlumno alumno)
{
    printf("\nAlumno: %s\n", alumno.nom);  // No usar "->" porque se pasa como valor, no puntero.
    printf("Matricula: %d\n", alumno.matricula);
    printf("Promedio: %.2f\n", alumno.prom);
}


