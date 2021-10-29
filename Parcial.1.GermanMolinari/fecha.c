#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"

eFecha tomarFecha()
{
    eFecha fechaIngresada;
    int retorno;

    printf("ingrese fecha (dd/mm/aaaa) \n");
    fflush(stdin);
    retorno = scanf("%d/%d/%d", &fechaIngresada.dia,&fechaIngresada.mes, &fechaIngresada.anio);

    while(!(retorno == 3 && (fechaIngresada.dia >= 1 && fechaIngresada.dia <= 31) &&
            (fechaIngresada.mes >= 1 && fechaIngresada.mes <= 12) &&
            (fechaIngresada.anio >= 2000 && fechaIngresada.anio <= 2021)))
    {
        printf("Error, reingrese la fecha en el formato correcto (dd/mm/aaaa)");
        fflush(stdin);
        retorno = scanf("%d/%d/%d", &fechaIngresada.dia,&fechaIngresada.mes, &fechaIngresada.anio);
    }
    return fechaIngresada;
}

