#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int cargarNombre(int id, eCliente clientes[],int tam,char nombre[])
{
    int todoOk= -1;
    if(id>=6000 && id<=6003 && clientes!=NULL && tam>0 && nombre!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].id==id)
            {
                strcpy(nombre,clientes[i].nombre);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

void mostrarCliente(eCliente cliente)
{
    printf("\n %d    %10s            %c ",cliente.id,cliente.nombre,cliente.sexo);
}



int mostrarClientes(eCliente clientes[],int tam){
int todoOk=-1;
if(clientes!=NULL &&tam>0){
    printf("\n----------------------------------------------\n");
    printf("               CLIENTES\n");
    printf("----------------------------------------------\n");
    printf("  ID          NOMBRE          SEXO");
    for(int i =0;i<tam;i++){
        mostrarCliente(clientes[i]);
    }
    printf("\n----------------------------------------------\n\n");
 todoOk=1;
}

return todoOk;
}

