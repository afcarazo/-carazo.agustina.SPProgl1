#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
void mostrarColor(eColor color)
{
    printf("\n %d    %10s       ",color.id,color.nombreColor);
}


int mostrarColores(eColor colores[], int tam)
{

    int todoOk=-1;
    printf("\nLista de colores:\n");
    printf("\n---------------------\n");
    printf("  ID     DESCRIPCION  ");
    printf("\n---------------------");

    if(colores!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarColor(colores[i]);
        }
       printf("\n---------------------\n\n");
       todoOk=1;
    }
    return todoOk;
}
int cargarDescripcionColor(int id, eColor colores[],int tam,char descripcionColor[])
{
    int todoOk= -1;
    if(id>=5000 && id<=5004 && colores!=NULL && tam>0 && descripcionColor!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(colores[i].id==id)
            {
                strcpy(descripcionColor,colores[i].nombreColor);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}
