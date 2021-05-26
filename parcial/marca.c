#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  "marca.h"

void mostrarMarca(eMarca marca)
{
    printf("\n %d    %10s       ",marca.id,marca.descripcion);
}


int mostrarMarcas(eMarca marcas[], int tam)
{

    int todoOk=-1;
    printf("\nLista de marcas:\n");
    printf("\n---------------------\n");
    printf("  ID     DESCRIPCION  ");
    printf("\n---------------------\n");

    if(marcas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarMarca(marcas[i]);
        }
       printf("\n---------------------\n");
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionMarca(int id, eMarca marcas[],int tam,char descripcionMarca[])
{
    int todoOk= -1;
    if(id>=1000&& id<=1004 && marcas!=NULL && tam>0 && descripcionMarca!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(marcas[i].id==id)
            {
                strcpy(descripcionMarca,marcas[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}


