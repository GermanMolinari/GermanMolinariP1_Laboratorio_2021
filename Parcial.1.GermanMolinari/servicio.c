#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"
#include "marca.h"

int cargarDescripcionServicio( eServicio servicio[], int tam, int idServicio, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (servicio!= NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (servicio[i].id == idServicio)
            {
                strcpy(descripcion, servicio[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}

int mostrarServicio( eServicio servicios[], int tam)
{
    int todoOk = 0;
    if (servicios != NULL && tam > 0 )
    {
        system("cls");
        printf("      ***  Servicios *** \n\n");
        printf("  Id         Descripcion        Precio\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s        %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdServicio(int id, eServicio servicio[], int tam )
{
    int esValido = 0;

    if (servicio != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == servicio[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int cargarPrecioServicio(eServicio servicios[], int tamS, int idServicio, float* pPrecio)
{
    int todoOk = 0;
    int flag = 1;
    if (servicios != NULL && tamS > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamS; i++)
        {
            if (servicios[i].id == idServicio)
            {

                *pPrecio=servicios[i].precio;

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
