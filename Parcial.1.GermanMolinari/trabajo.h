#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "notebook.h"
typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    int isEmpty;
    eFecha fecha;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo trabajos[], int tam);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
int altaTrabajo(eTrabajo trabajos[], int tamTra, eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* pIdTrabajo);
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS, eNotebook notebooks[], int tam, eMarca marcas [], int tamM, eTipo tipos[], int tamT);
int mostrarTrabajos(eTrabajo trabajos[], int tamTra, eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eServicio servicios[], int tamS, eTipo tipos[], int tamT);
