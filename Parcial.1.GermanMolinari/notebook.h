#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "servicio.h"
#include "marca.h"
#include "tipo.h"

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;


#endif // NOTEBOOK_H_INCLUDED
int menu();
int inicializarNotebooks(eNotebook notebooks[], int tam);
int altaNotebook(eNotebook notebooks [], int tam, eTipo tipos[], int tamT, eMarca marcas[], int tamM,int* id);
int bajaNotebook(eNotebook notebooks [], int tam, eMarca marcas[], int tamM, eTipo tipos [], int tamT);
void mostrarNotebook(eNotebook notebook, eMarca marcas [], int tamM, eTipo tipos[], int tamT);
int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas [], int tamM, eTipo tipos[], int tamT);
int hardcodearNotebooks(eNotebook notebooks[], int tam, int cant, int* pId);
char menuModificar();
int modificarNotebook(eNotebook notebooks[], int tam, eMarca marcas [], int tamM, eTipo tipos [], int tamT);
int buscarNotebookId(eNotebook notebooks[], int tam, int id);
int ordenarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM);


