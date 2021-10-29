#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAM_TRA 10
#define TAM 10

int main()
{
    int idNotebook = 100;
    char seguir = 's';
    char salir;
    eNotebook notebooks[TAM];
    int flag = 0;
    int flagTrabajo = 0;

    eMarca marcas[TAM_M] =
    {
        { 1000, "Compadq" },
        { 1001, "Asus" },
        { 1002, "Acer" },
        { 1003, "Hp" }
    };

    eTipo tipos [TAM_T] =
    {
        { 5000, "Gamer" },
        { 5001, "Disenio" },
        { 5002, "Ultrabook" },
        { 5003, "Normalita"}
    };

    eServicio servicios[TAM_S] =
    {
        { 20000, "Bateria", 2250 },
        { 20001, "Display" , 10300},
        { 20002, "Mantenimiento", 4400},
        { 20003, "Fuente", 5600}
    };

    eTrabajo trabajos[TAM_TRA];
    int idTrabajo = 8000;

     if (!inicializarNotebooks(notebooks, TAM))
    {
        printf("Error al iniciar las notebooks\n");
    }

    if(!inicializarTrabajos(trabajos,TAM_TRA))
    {
        printf("Error al iniciar los trabajos\n");
    }

    hardcodearNotebooks(notebooks, TAM, 7, &idNotebook);

     do
    {
        switch (menu())
        {
        case 'A':
            if(!altaNotebook(notebooks, TAM, tipos, TAM_T, marcas, TAM_M, &idNotebook))
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa!\n");
                flag = 1;
            }

            break;
        case 'B':
                if(flag == 0)
                {
                    printf("No se puede dar de baja sin antes dar de alta\n");
                }
                else
                {
                    if(!bajaNotebook(notebooks, TAM, marcas, TAM_M,tipos,TAM_T))
                    {
                        printf("No se pudo realizar la baja, no se encontró el id ingresado\n");
                    }
                    else
                    {
                        printf("Baja exitosa!");
                    }
                }
            break;
        case 'C':
                if(flag == 0)
                {
                    printf("No se puede modificar sin antes dar de alta\n");
                }
                else
                {
                    if (modificarNotebook(notebooks,TAM,marcas,TAM_M,tipos,TAM_T) != 1)
                    {
                        printf("No se pudo modificar");
                    }
                }
            break;

        case 'D':
                if(flag == 0)
                {
                    printf("No se puede mostrar sin antes dar de alta\n");
                }
                else
                {
                    if(!mostrarNotebooks(notebooks, TAM, marcas, TAM_M,tipos,TAM_T))
                    {
                        printf("No se pudo mostrar\n");
                    }
                }
            break;
        case 'E':
            mostrarMarca(marcas,TAM_M);

            break;
        case 'F':
                mostrarTipo(tipos,TAM_T);
            break;
        case 'G':
                mostrarServicio(servicios, TAM_S);
            break;
        case 'H':
                if (altaTrabajo(trabajos, TAM_TRA,notebooks,TAM,marcas,TAM_M,tipos,TAM_T,servicios,TAM_S,&idTrabajo) != 1)
                {
                    printf("No se pudo dar de alta\n");
                }
                else
                {
                    flagTrabajo = 1;
                }
            break;
        case 'I':
                if (flagTrabajo == 0)
                {
                    printf("No se puede mostrar trabajos sin antes dar de alta uno\n");
                }
                else
                {
                    if(mostrarTrabajos(trabajos, TAM_TRA, notebooks, TAM, marcas, TAM_M, servicios,TAM_S, tipos, TAM_T) == 0)
                    {
                        printf("No se pudo listar trabajos \n");
                    }
                }
            break;
        case 'J':
                printf("Desea salir? s/n \n");
                fflush(stdin);
                scanf("%c", &salir);
                salir = toupper(salir);
                if(salir == 'S')
                {
                    seguir='n';
                }
                else
                {
                    printf("Salida cancelada!");
                }
            break;
        default:
            printf("Opcion invalida\n");
            }
        system("pause");
    }while (seguir=='s');

}
