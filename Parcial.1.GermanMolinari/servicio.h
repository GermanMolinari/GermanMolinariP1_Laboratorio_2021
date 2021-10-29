#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED
int cargarDescripcionServicio( eServicio servicio[], int tam, int idServicio, char descripcion[]);
int mostrarServicio( eServicio servicios[], int tam);
int validarIdServicio(int id, eServicio servicio[], int tam);
int cargarPrecioServicio(eServicio servicios[], int tamS, int idServicio, float* pPrecio);
