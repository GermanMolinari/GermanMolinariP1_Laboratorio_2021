#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED
int cargarDescripcionMarca( eMarca marcas[], int tam, int idMarca, char descripcion[]);
int mostrarMarca( eMarca marcas[], int tam);
int validarIdMarca(int id, eMarca marcas[], int tam);
