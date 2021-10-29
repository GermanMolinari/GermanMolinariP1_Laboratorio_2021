#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"

int cargarDescripcionMarca( eMarca marcas[], int tam, int idMarca, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (marcas!= NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (marcas[i].id == idMarca)
            {
                strcpy(descripcion, marcas[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int mostrarMarca( eMarca marcas[], int tam)
{
    int todoOk = 0;
    if (marcas != NULL && tam > 0 )
    {
        system("cls");
        printf("      ***  MARCAS *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", marcas[i].id, marcas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdMarca(int id, eMarca marcas[], int tam )
{
    int esValido = 0;

    if (marcas != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == marcas[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
