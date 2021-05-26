#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"

int altaTrabajo(eTrabajo trabajos[],int tam, eServicio servicios[],int tamS, eAuto autos[],int tamA, eMarca marcas[],int tamM,eColor colores[],int tamC, int *id,eCliente clientes[],int tamCl)
{
    eTrabajo nuevoTrabajo;
    int indiceTrabajo;
    int indiceAuto;
    int todoOk=-1;

    system("cls");
    printf("\n-------------------\n");
    printf("     ALTA TRABAJO");
    printf("\n-------------------\n\n");
    printf("ID: %d\n", *id);
    if(trabajos!=NULL && tam>0 && servicios!=NULL && tamS>0 && autos!=NULL && tamA>0 && colores!=NULL && tamC>0 && marcas!=NULL && tamM>0 &&clientes!=NULL && tamCl>0)
    {
        indiceTrabajo=buscarLibreTrabajo(trabajos,tam);
        if(indiceTrabajo==-1)
        {
            printf("\nNo hay lugar\n");
        }
        else
        {
            mostrarAutos(autos,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
            if(get_patente(nuevoTrabajo.patente,10, "\nIngrese patente: ", "\nERROR, la patente ingresada no es valida.\n ",3)==-1)
            {
                printf("\nHa excedido los reintentos disponibles. \n");
            }
            else
            {
                indiceAuto=buscarAuto(autos,tamA,nuevoTrabajo.patente);
                if(indiceAuto==-1)
                {
                    printf("\nNo existe ningun auto con esa patente.\n");
                }
                else
                {
                    mostrarServicios(servicios,tamS);
                    if(utn_getNumero(&nuevoTrabajo.idServicio,"\nIngrese ID del servicio: ", "\nERROR, El ID no existe.\n",2000,2003,3)==-1)
                    {
                        printf("\nHa excedido los reintentos disponibles. \n");
                    }
                        else
                        {
                            printf("\nIngrese fecha dd/mm/aaaa: ");
                            fflush(stdin);
                            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);
                            while(validarFechaTrabajo(nuevoTrabajo)==-1)
                            {
                                printf("\nERROR.Reingrese fecha dd/mm/aaaa: ");
                                fflush(stdin);
                                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);

                            }
                            nuevoTrabajo.id= *id;
                            (*id)++;
                            nuevoTrabajo.isEmpty=0;
                            trabajos[indiceTrabajo]=nuevoTrabajo;
                            todoOk=1;


                        }

                }
            }


        }
    }

    return todoOk;
}



int inicializarTrabajos(eTrabajo trabajos[],int tam)
{
    int todoOk=-1;
    if(trabajos!=NULL&& tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            trabajos[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}



int buscarLibreTrabajo(eTrabajo trabajo[],int tam)
{
    int indice=-1;
    if(trabajo!=NULL&& tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(trabajo[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int validarFechaTrabajo(eTrabajo fecha)
{
    int todoOk=-1;

    if ( fecha.fecha.mes >= 1 && fecha.fecha.mes <= 12 && fecha.fecha.anio>1900 && fecha.fecha.anio<=2021 )
    {
        switch ( fecha.fecha.mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( fecha.fecha.dia >= 1 && fecha.fecha.dia <= 31)
            {
                todoOk=1;
            }
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( fecha.fecha.dia >= 1 && fecha.fecha.dia <= 30 )
            {
                todoOk=1;
            }
            break;

        case  2 :

            if( (fecha.fecha.anio % 4 == 0 && fecha.fecha.anio % 100 != 0) || (fecha.fecha.anio % 400 == 0) )
            {
                if ( fecha.fecha.dia >= 1 && fecha.fecha.dia <= 29)
                {
                    todoOk=1;
                }
            }
            else if( fecha.fecha.dia >= 1 && fecha.fecha.dia <= 28)
            {
                todoOk=1;
            }
          break;

        }

    }
    return todoOk;
}


int mostrarTrabajo(eTrabajo trabajo, eServicio servicios[],int tamS)
{
    int todoOk=-1;
    if(servicios!=NULL && tamS>0){
    char descripcion[20];
    if(cargarDescripcionServicio(trabajo.idServicio,servicios,tamS,descripcion))
    {
        printf("\n%10s    %d    %10s     %02d/%02d/%d ",trabajo.patente,trabajo.id,descripcion,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
    todoOk=1;
    }
    }
return todoOk;
}
int mostrarTrabajos(eTrabajo trabajo[],int tam,eServicio servicios[],int tamS)
{

    int flag=1;
    int todoOk=-1;
    if(trabajo!=NULL && tam>0 &&servicios!=NULL && tamS>0)
    {
        system("cls");
        printf("\n----------------------------------------------------------\n");
        printf("                 Listado de trabajos\n");
        printf("\n   PATENTE     ID       SERVICIO      FECHA   \n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(trabajo[i].isEmpty==0)
            {
                mostrarTrabajo(trabajo[i],servicios,tamS);
                flag=0;
            }
            todoOk=1;
        }
        if(flag)
        {
            printf("\n\n         No hay trabajos que mostrar\n\n");

        }
        printf("\n----------------------------------------------------------\n");
    }
    return todoOk;


}



