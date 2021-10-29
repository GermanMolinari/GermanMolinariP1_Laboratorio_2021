#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAM 10


int inicializarTrabajos(eTrabajo trabajos[], int tam)
{

    int todoOk = 0;
    if (trabajos != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indice = -1;
    if(trabajos != NULL && tam > 0){

        for (int i = 0; i < tam; i++)
        {
            if (trabajos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajos[], int tamTra, eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eServicio servicios[], int tamS, int* pIdTrabajo)
{
    int todoOk = 0;
    int indice;

    eTrabajo auxTrabajo;

    if (notebooks != NULL && tam > 0 && pIdTrabajo != NULL && trabajos != NULL && tamTra > 0 && marcas != NULL && tamM > 0 &&
        tipos != NULL && tamT > 0)
    {

        system("cls");
        printf("  ***Alta Trabajo*** \n\n");
        indice = buscarLibreTrabajo(trabajos, tamT);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;


            mostrarServicio(servicios, tamS);
            printf("Ingrese id del servicio: ");
            scanf("%d", &auxTrabajo.idServicio);

            while ( !validarIdServicio(auxTrabajo.idServicio, servicios, tamS))
            {
                printf("Error, ingrese id de servicio valido: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            mostrarNotebooks(notebooks, tam, marcas, tamM, tipos, tamT);
            printf("Ingrese id de la notebook: ");
            scanf("%d", &auxTrabajo.idNotebook);

            while(buscarNotebookId(notebooks, tam, auxTrabajo.idNotebook) == -1)
            {
                printf("Error, ingrese id de la notebook: ");
                scanf("%d", &auxTrabajo.idNotebook);
            }

            auxTrabajo.fecha = tomarFecha();

            auxTrabajo.isEmpty=0;

            trabajos[indice] = auxTrabajo;

            todoOk = 1;
        }
    }
    return todoOk;
}


void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS, eNotebook notebooks[], int tam, eMarca marcas [], int tamM, eTipo tipos[], int tamT)
{
    char descServicios[20];
    char descMarcas[20];
    char descTipos [20];
    int indice;
    float precio;

    indice = buscarNotebookId(notebooks, tam, unTrabajo.idNotebook);

    if ( cargarDescripcionServicio(servicios, tamS, unTrabajo.idServicio, descServicios) == 1 &&
         cargarDescripcionMarca(marcas, tamM, notebooks[indice].idMarca, descMarcas) == 1 &&
         cargarDescripcionTipo(tipos, tamT, notebooks[indice].idTipo, descTipos) == 1 &&
         cargarPrecioServicio(servicios, tamS, unTrabajo.idServicio, &precio)
        )

    {

            printf("%d   %-10s    %-10s    %-10s %-10s  %7.2f  %002d/%002d/%d\n",
               unTrabajo.id,
               notebooks[indice].modelo,
               descServicios,
               descMarcas,
               descTipos,
               precio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio
               );
    }

}


int mostrarTrabajos(eTrabajo trabajos[], int tamTra, eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eServicio servicios[], int tamS, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if (trabajos != NULL && tamTra > 0 && notebooks != NULL && tam > 0 && marcas != NULL && tamM > 0 &&
        servicios != NULL && tamS > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");

        printf("                 ***Lista de Trabajos  ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf(" ID   Notebook      Servicio      Marca       Tipo        Precio      Fecha\n");
        printf("---------------------------------------------------------------------------\n");

        for (int i = 0; i < tam; i++)
        {
            if (!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i],servicios, tamS, notebooks,tam,marcas,tamM,tipos,tamT);
                flag = 0;
            }
        }

        if (flag == 1)
        {
            printf("No hay trabajos para mostrar.\n");
        }

        todoOk = 1;
    }
    return todoOk;
}
