#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

int inicializarAutos(eAuto lista[], int tam)
{
    int todoOk=-1;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
            todoOk=1;
        }
    }
    return todoOk;
}

int altaAuto(eAuto lista[], int tam,eMarca marcas[], int tamM,eColor colores[],int tamC, int* id)
{
    int todoOk=-1;
    eAuto auxAuto;
    int indice;

    system("cls");
    printf("\n-------------------\n");
    printf("      ALTA AUTO");
    printf("\n-------------------\n\n");
    printf("ID: %d\n", *id);

    if(lista!=NULL&& tam>0 && id!=NULL && marcas!=NULL&& tamM>0 && colores!=NULL&& tamC>0)
    {
        indice= buscarLibre(lista,tam);
        if(indice!=-1)
        {
            mostrarMarcas(marcas,tamM);
            if(utn_getNumero(&auxAuto.idMarca,"\nIngrese ID marca: ", "\nERROR, El ID introducido no existe.\n",1000,1004,3)==-1)
            {
                printf("\nHa excedido los reintentos disponibles. \n");
            }
            else
            {
                mostrarColores(colores,tamC);
                if(utn_getNumero(&auxAuto.idColor,"\nIngrese ID color: ", "\nERROR, El ID introducido no existe.\n",5000,5004,3)==-1)
                {
                    printf("\nHa excedido los reintentos disponibles. \n");
                }
                else
                {
                    if(utn_getNumero(&auxAuto.modelo,"\nIngrese modelo: ", "\nERROR, El modelo no existe.\n ",1985,2021,3)==-1)
                    {
                        printf("\nHa excedido los reintentos disponibles. \n");
                    }
                    else
                    {
                        if(get_patente(auxAuto.patente,10, "\nIngrese parente: ", "\nERROR, la patente ingresada no es valida.\n",3)==-1)
                        {
                            printf("\nHa excedido los reintentos disponibles. \n");
                        }
                        else
                        {
                            auxAuto.id=*id;
                            (*id)++;
                            auxAuto.isEmpty=0;
                            lista[indice]=auxAuto;
                            todoOk=1;
                        }

                    }

                }

            }

        }
        else
        {
            printf("\nNO HAY LUGAR \n");
        }
    }
    return todoOk;
}


int buscarLibre(eAuto lista[], int tam)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int modificarAuto(eAuto lista[],int tam, eColor colores[],int tamC, eMarca marcas[], int tamM)
{
    system("cls");
    int todoOk=-1;
    char patente[20];
    int indice;
    char respuesta[2];

    if(lista!=NULL&&tam>0&&colores!=NULL && tamC>0 && marcas!=NULL && tamM>0)
    {
        mostrarAutos(lista,tam,marcas,tamM,colores,tamC);
        printf("\nIngrese la patente del auto que quisiera modificar: ");
        fflush(stdin);
        gets(patente);
        indice= buscarAuto(lista,tam,patente);
        if(indice!=-1)
        {
            printf("\n ID     Patente   Modelo     Color      Marca       \n");
            mostrarAuto(lista[indice],colores,tamC,marcas,tamM);
            if(utn_getChar(respuesta,2,"\n Esta seguro de que quiere modificar este auto? s/n: ", "ERROR, ingrese s/n\n",3)==-1)
            {
                printf("\nHa excedido los reintentos disponibles. \n");
            }
            else
            {
                if(strcmp(respuesta,"s")==0)
                {
                    if(modificarMenu(lista,tam,indice,colores,tamC)==1)
                    {
                        todoOk=1;
                    }
                }
                else
                {
                    printf("Modificacion cancelada \n\n\n");
                }

            }

        }
        else
        {
            printf("No hay ningun auto con esa patente\n");

        }
    }
    return todoOk;

}


int modificarMenu(eAuto lista[], int tam, int indice, eColor colores[], int tamC)
{
    int opcion;
    int todoOk=-1;

    if(lista!=NULL && tam>0 && colores!=NULL&&tamC>0)
    {
        printf("\nQue desea modificar?\n\n");
        printf("1. Color\n");
        printf("2. Modelo\n");
        printf("3. Salir\n");

        if(utn_getNumero(&opcion, "\nIngrese opcion: \n","\nERROR, opcion invalida\n",1,3,3)==-1)
        {
            printf("\nHa superado la cantidad de reintentos.\n\n");
            opcion=3;
        }

        switch(opcion)
        {

        case 1:
            mostrarColores(colores,tamC);
            if(utn_getNumero(&lista[indice].idColor,"\nIngrese ID color: ", "\nERROR, El ID introducido no existe. \n",5000,5004,3)==0)
            {
                todoOk=1;
            }
            else
            {
                printf("\nHa excedido los reintentos disponibles. \n");
            }

            break;
        case 2:
            if(utn_getNumero(&lista[indice].modelo,"\nIngrese modelo: ", "\nERROR, El modelo no existe. \n",1985,2021,3)==0)
            {
                todoOk=1;
            }
            else
            {
                printf("\nHa excedido los reintentos disponibles. \n");
            }
            break;
        case 3:
            printf("No se ha modificado nada\n\n");
            break;
        }

    }
    return todoOk;
}


int buscarAuto(eAuto lista[], int tam, char patente[])
{
    int indice=-1;

    if(lista!=NULL && tam>0 && patente!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty == 0 && strcmp(lista[i].patente,patente)==0)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
int mostrarAuto(eAuto unAuto,eColor colores[],int tamC, eMarca marcas[],int tamM)
{
    char descripcionColor[20];
    char descripcionMarca[20];
    int todoOk=-1;
    if(colores!=NULL && tamC>0 && marcas!=NULL && tamM>0)
    {
        if(cargarDescripcionColor(unAuto.idColor,colores,tamC,descripcionColor) && cargarDescripcionMarca(unAuto.idMarca,marcas,tamM,descripcionMarca))
        {

            printf("%d %10s    %d %10s %10s\n"
                   ,unAuto.id
                   ,unAuto.patente
                   ,unAuto.modelo
                   ,descripcionColor
                   ,descripcionMarca
                  );
            todoOk=1;
        }
    }
    return todoOk;
}


int mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamM,eColor colores[],int tamC)
{
    int flag=1;
    int todoOk=-1;
    printf("\n----------------------------------------------\n");
    printf("               Listado de autos\n");
    printf("\n ID     Patente   Modelo     Color      Marca       \n");
    printf("----------------------------------------------\n\n");
    if(lista!=NULL && tam>0 && marcas!=NULL && tamM>0 && colores!=NULL && tamC>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                mostrarAuto(lista[i],colores,tamC,marcas,tamM);
                flag=0;
                todoOk=1;
            }
        }
        if(flag==1)
        {
            printf("        No hay autos que mostrar");
            todoOk=1;

        }

        printf("\n----------------------------------------------\n");
        printf("\n\n");
    }
    return todoOk;
}


int ordenarAutos(eAuto lista[],int tam, eMarca marcas[],int tamM,eColor colores[],int tamC)
{
    int opcion;
    int todoOk=-1;
    if(lista!=NULL && tam>0&& marcas!=NULL &&tamM>0 && colores!=NULL&&tamC>0)
    {
        printf("\nDe que forma quisiera ordenar marca y patente?\n\n");
        printf("1. ascendente\n");
        printf("2. descedente\n");
        if(utn_getNumero(&opcion, "\nIngrese opcion: ","\nERROR, opcion invalida\n",1,2,3)==-1)
        {
            printf("\nHa superado la cantidad de reintentos\n\n");
        }
        else
        {
            organizarAutos(lista,tam,opcion,marcas,tamM);
            mostrarAutos(lista,tam,marcas,tamM,colores,tamC);
            todoOk=1;
        }

    }
    return todoOk;
}

int organizarAutos(eAuto autos[],int tam,int ascendenteDescendente, eMarca marcas[],int tamM)
{
    eAuto auxAuto;
    int todoOk=-1;
    char marcaI[20];
    char marcaJ[20];
    if(autos!=NULL && tam>0 && marcas!=NULL && tamM>0)
    {
        switch(ascendenteDescendente)
        {
        case 1:
            for(int i=0; i<tam-1; i++ )
            {
                for(int j= i+1; j<tam; j++)
                {
                    cargarDescripcionMarca(autos[i].idMarca,marcas,tamM,marcaI);
                    cargarDescripcionMarca(autos[j].idMarca,marcas,tamM,marcaJ);
                    if(strcmp(marcaI,marcaJ)>0 || (strcmp(marcaI,marcaJ)==0 && strcmp(autos[i].patente,autos[j].patente)>0 ))
                    {
                        auxAuto= autos[i];
                        autos[i]=autos[j];
                        autos[j]=auxAuto;
                        todoOk=1;
                    }

                }
            }
            break;
        case 2:
            for(int i=0; i<tam-1; i++ )
            {
                for(int j= i+1; j<tam; j++)
                {
                    cargarDescripcionMarca(autos[i].idMarca,marcas,tamM,marcaI);
                    cargarDescripcionMarca(autos[j].idMarca,marcas,tamM,marcaJ);
                    if(strcmp(marcaI,marcaJ)<0 || (strcmp(marcaI,marcaJ)==0 && strcmp(autos[i].patente,autos[j].patente)<0 ))
                    {
                        auxAuto= autos[i];
                        autos[i]=autos[j];
                        autos[j]=auxAuto;
                        todoOk=1;
                    }

                }
            }
            break;

        }
    }

    return todoOk;
}


int bajaAuto(eAuto autos[],int tam, eColor colores[],int tamC, eMarca marcas[],int tamM)
{
    int indice;
    char confirma[2];
    char patente[20];
    int todoOk=-1;
    system("cls");
    printf("\n-------------------\n");
    printf("      BAJA AUTO:");
    printf("\n-------------------\n\n");
    if(autos!=NULL&&tam>0&&colores!=NULL&&tamC>0 && marcas!=NULL && tamM>0)
    {
        mostrarAutos(autos,tam,marcas,tamM,colores,tamC);
        printf("\nIngrese la patente del auto que quisiera dar de baja: ");
        gets(patente);
        printf("\n");
        indice= buscarAuto(autos,tam,patente);
        if(indice==-1)
        {
            printf("\nNo hay ningun auto registrado con la patente %s\n",patente);
            todoOk=-1;
        }
        else
        {
            printf("\n ID     Patente   Modelo     Color      Marca       \n");
            mostrarAuto(autos[indice],colores,tamC,marcas,tamM);
            if(utn_getChar(confirma,2,"\n Esta seguro de que quiera dar de baja este auto? s/n: ", "ERROR, no ha ingresado lo solicitado. \n",3)==-1)
            {
                printf("\nHa excedido los reintentos disponibles. \n");
            }
            else
            {
                if(strcmp(confirma,"s")==0)
                {
                    autos[indice].isEmpty=1;
                    todoOk=1;
                }
                else
                {
                    printf("\nBaja cancelada por el usuario\n\n");

                }
            }

        }
    }
    return todoOk;

}

int cargarPatenteAuto(int id, eAuto autos[],int tam,char nombrePatente[])
{
    int todoOk= -1;
    if(autos!=NULL && tam>0 && nombrePatente!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(autos[i].id==id && autos[i].isEmpty==0)
            {
                strcpy(nombrePatente,autos[i].patente);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}


int hayAutosActivos(eAuto autos[], int tam)
{
    int activo=0;
    if(autos!=NULL && tam>0)
    {
        for(int a =0; a<tam; a++)
        {
            if(autos[a].isEmpty==0)
            {
                activo=1;
            }

        }

    }
    return activo;
}

int obtenerIdPorPatente(eAuto autos[], int tam,char patente[], int *pId)
{
    int todoOk=-1;
    if(autos!=NULL &&tam>0 && patente!=NULL && pId!=NULL )
    {

        for(int i=0; i<tam; i++)
        {
            if(strcmp(autos[i].patente,patente)==0 && autos[i].isEmpty==0)
            {
                *pId= autos[i].id;
                todoOk=1;
                break;
            }

        }

    }
    return todoOk;
}

