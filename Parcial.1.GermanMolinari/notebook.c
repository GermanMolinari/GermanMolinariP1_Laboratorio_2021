#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"

int menu()
{
    char opcion;

    system("cls");
    printf("     *** ABM Notebooks ***\n");
    printf("A- Alta Notebook\n");
    printf("B- Baja Notebook\n");
    printf("C- Modificar Notebook\n");
    printf("D- Listar Notebooks\n");
    printf("E- Listar Marcas\n");
    printf("F- Listar Tipos\n");
    printf("G- Listar Servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Salir \n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    return opcion;

}

int hardcodearNotebooks(eNotebook notebooks[], int tam, int cant, int* pId)
{


    char modelos [10][20] =
    {
        "F34",
        "OHANA 420",
        "DARK 500",
        "WHITE 881",
        "NIMBUS 2000",
        "LOCAL 60",
        "FASE 5866",
        "COMMIT 634",
        "ADD 981",
        "KELO 988",
    };

    float precios[10] = {10000,74000,68000,80000,69000,69000,75000,74000,73000,82000};

    int idMarcas[10] = {1000,1002,1003,1003,1003,1001,1001,1000,1000,1003};

    int idTipos[10] = {5000,5002,5003,5002,5003,5001,5001,5000,5000,5003};

    int contador = -1;
    if (notebooks != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;

        for (int i = 0; i < cant;  i++)
        {
            notebooks[i].id = *pId;
            (*pId)++;
            strcpy(notebooks[i].modelo, modelos[i]);
            notebooks[i].idMarca = idMarcas[i];
            notebooks[i].idTipo = idTipos[i];
            notebooks[i].precio = precios[i];
            notebooks[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;

}


int inicializarNotebooks(eNotebook notebooks[], int tam)
{
    int todoOk = 0;

    if (notebooks != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            notebooks[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibre(eNotebook notebooks[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (notebooks[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaNotebook(eNotebook notebooks [], int tam, eTipo tipos[], int tamT, eMarca marcas[], int tamM,int* id)
{
    int todoOk = 0;
    int indice;
    eNotebook aux;
    if (notebooks != NULL && tam > 0 && marcas != NULL && tipos != NULL && tamT > 0 && tamM > 0 && id != NULL)
    {
        system("cls");
        printf("  ***Alta Notebook*** \n\n");
        indice = buscarLibre(notebooks, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            aux.id = *id;
            (*id)++;

            printf("Ingrese nombre del modelo: ");
            fflush(stdin);
            gets(aux.modelo);

            mostrarTipo(tipos, tamT);


            printf("Ingrese id del tipo de notebook: ");
            scanf("%d", &aux.idTipo);

            while ( !validarIdTipo(aux.idTipo, tipos, tamT))
            {
                printf("Error, ingrese id de un tipo valido: ");
                scanf("%d", &aux.idTipo);
            }

            mostrarMarca(marcas, tamM);


            printf("Ingrese id de la marca: ");
            scanf("%d", &aux.idMarca);

            while ( !validarIdMarca(aux.idMarca, marcas, tamM))
            {
                printf("Error, ingrese id de una marca valido: ");
                scanf("%d", &aux.idMarca);
            }

            system("cls");
            printf("Ingrese precio de la notebook: ");
            scanf("%f", &aux.precio);

            while ( aux.precio < 1000)
            {
                printf("Error, el precio debe superar los $1000: ");
                scanf("%f", &aux.precio);
            }

            aux.isEmpty = 0;

            notebooks[indice] = aux;

            todoOk = 1;
        }
    }
    return todoOk;
}

int bajaNotebook(eNotebook notebooks [], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int id;
    char confirma;
    int indice;


    if(notebooks != NULL && tam > 0)
    {

        printf("Ingrese id de la notebook que desea dar de baja\n");
        scanf("%d", &id);
        indice= buscarNotebookId(notebooks, tam, id);

        if(indice != -1)
        {
            system("cls");
            printf("      ***  NOTEBOOKS *** \n\n");
            printf("Id         Modelo         Marca              Tipo             Precio\n\n");

            mostrarNotebook(notebooks[indice], marcas, tamM, tipos, tamT);

            printf("\n Confirma borrar la notebook? S/N \n");

            fflush(stdin);
            scanf("%c", &confirma);
            confirma=toupper(confirma);
        }


        if(confirma == 'S')
        {

            for (int i = 0; i < tam; i++)
            {
                if(id == notebooks[i].id)
                {
                    notebooks[indice].isEmpty = 1;
                    todoOk = 1;
                }

            }
        }
        else
        {
            printf("Baja cancelada");
        }
    }
    return todoOk;
}

void mostrarNotebook(eNotebook notebook, eMarca marcas [], int tamM, eTipo tipos[], int tamT)
{
    char descripcionMarca [20];
    char descripcionTipo [20];


    cargarDescripcionMarca(marcas, tamM, notebook.idMarca, descripcionMarca);
    cargarDescripcionTipo(tipos, tamT, notebook.idTipo, descripcionTipo);

    {
         printf("%d      %-15s       %-10s       %-15s       %5.2f \n",
           notebook.id,
           notebook.modelo,
           descripcionMarca,
           descripcionTipo,
           notebook.precio);

    }

}

int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas [], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;



    if(notebooks != NULL && marcas != NULL && tam > 0 && tamM > 0 && tipos != NULL && tamT > 0)
    {

        ordenarNotebooks(notebooks, tam, marcas, tamM);

        system("cls");
        printf("      ***  NOTEBOOKS *** \n\n");
        printf("  Id         Modelo         Marca              Tipo             Precio\n\n");

        for (int i = 0; i < tam; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                mostrarNotebook(notebooks[i], marcas, tamM,tipos, tamT);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int ordenarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM)
{

    int todoOk = 0;
    char descripcionI[20];
    char descripcionJ[20];
    eNotebook auxNote;


    if(notebooks != NULL && marcas != NULL && tamM > 0&& tam > 0)
    {

        for (int i = 0; i < tam - 1; i++)
        {
            for (int j = i + 1; j < tam; j++)
            {
                cargarDescripcionMarca(marcas, tamM, notebooks[i].idMarca, descripcionI);
                cargarDescripcionMarca(marcas, tamM, notebooks[j].idMarca, descripcionJ);

                if((strcmp(descripcionI, descripcionJ) == 0 && notebooks[i].precio > notebooks[j].precio) ||
                (strcmp(descripcionI, descripcionJ) > 0))
                {
                    auxNote = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxNote;
                }
            }
        }
    todoOk = 1;
    }
    return todoOk;
}


int buscarNotebookId(eNotebook notebooks[], int tam, int id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (notebooks[i].id == id && notebooks[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarNotebook(eNotebook notebooks[], int tam, eMarca marcas [], int tamM, eTipo tipos [], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eNotebook auxNote;

    if (notebooks != NULL && tam > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Modificar Notebook *** \n\n");
        mostrarNotebooks(notebooks, tam, marcas, tamM, tipos,tamT);

        printf("Ingrese id: ");
        scanf("%d", &id);


        indice = buscarNotebookId(notebooks, tam, id);
        mostrarNotebook(notebooks[indice], marcas, tamM, tipos, tamT);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch (menuModificar())
                {
                case 'P':
                    printf("Ingrese nuevo precio: ");
                    fflush(stdin);
                    scanf("%f", &auxNote.precio);
                    printf("Confirma (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        notebooks[indice].precio = auxNote.precio;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 'T':
                    printf("Ingrese nuevo tipo \n");
                    mostrarTipo(tipos,tamT);
                    printf("Seleccione el id del tipo que desea: ");
                    scanf("%d", &auxNote.idTipo);

                    while(validarIdTipo(auxNote.idTipo, tipos,tamT) != 1)
                    {
                        mostrarTipo(tipos,tamT);
                        printf("Error, seleccione un id valido: ");
                        scanf("%d", &auxNote.idTipo);
                    }

                    printf("Confirma el cambio de tipó? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        notebooks[indice].idTipo = auxNote.idTipo;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 'S':
                    printf("Esta seguro que quiere salir? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = toupper(salir);
                    if (salir == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }
                //system("pause");
            }
            while(seguir == 's');
            todoOk = 1;
        }
    }
    return todoOk;
}


char menuModificar()
{
    char opcion;

    system("cls");

    printf("Desea modificar precio, tipo o salir del menu? (P/T/S): ");
    fflush(stdin);
    opcion = getchar();
    opcion = toupper(opcion);

    while ( opcion != 'P' && opcion != 'T' && opcion != 'S')
    {
        printf("Opcion incorrecta, ingrese nuevamente (P/T/S): ");
        fflush(stdin);
        opcion = getchar();
        opcion = tolower(opcion);
    }

    return opcion;
}
