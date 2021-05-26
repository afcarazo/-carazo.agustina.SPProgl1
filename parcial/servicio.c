#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicio(eServicio servicio)
{
    printf("\n %d    %10s     %2.f ",servicio.id,servicio.descripcion,servicio.precio);
}


int mostrarServicios(eServicio servicios[], int tam)
{

    int todoOk=-1;
    printf("\nLista de servicios\n");
    printf("\n-----------------------------\n");
    printf("  ID     DESCRIPCION   PRECIO");
    printf("\n-----------------------------\n");

    if(servicios!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarServicio(servicios[i]);
        }
        printf("\n");
        todoOk=1;
    }
    printf("\n-----------------------------\n");
    return todoOk;
}


int buscarIdSevicio(int id,eServicio servicios[],int tam){
int valido=-1;

if(servicios!=NULL && tam>0){
    for(int i=0;i<tam;i++){
        if(servicios[i].id==id){
            valido=1;
            break;
        }
        }

    }
    return valido;
}


int cargarDescripcionServicio(int id, eServicio servicios[],int tam,char descripcionServicio[])
{
    int todoOk= -1;
    if(id>=2000&& id<=2003&&servicios!=NULL && tam>0 && descripcionServicio!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                strcpy(descripcionServicio,servicios[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}
