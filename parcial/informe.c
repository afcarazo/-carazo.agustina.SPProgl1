#include "informe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int menuInformes(eAuto autos[], int tamA, eColor colores[],int tamC, eMarca marcas[], int tamM,eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT, eCliente clientes[],int tamCl)
{

    int todoOk=-1;
    int opcion;
    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && servicios!=NULL && tamS>0 && trabajos!=NULL && tamT>0 && clientes!=NULL && tamCl>0)
    {
        todoOk=1;
        system("cls");
        printf("\n--------------------------------------------------------------------------------------------\n");
        printf("                                   INFORMES                                                     ");
        printf("\n--------------------------------------------------------------------------------------------\n\n");
        printf("1. Mostrar autos del color seleccionado por el usuario.\n");
        printf("2. Mostrar autos de una marca seleccionada\n");
        printf("3. Informar el o los autos mas viejos.\n");
        printf("4. Mostrar un listado de los autos separados por marca.\n");
        printf("5. Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca.\n");
        printf("6. Mostrar la o las marcas mas elegidas por los clientes.\n");
        printf("7. Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo.\n");
        printf("8  Pedir un auto e informar la suma de los importes que se le hicieron al mismo.\n");
        printf("9. Pedir un servicio y mostrar los autos a los que se realizo ese servicio y la fecha.\n");
        printf("10.Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
        printf("\n--------------------------------------------------------------------------------------------\n");
        if(utn_getNumero(&opcion, "\nIngrese opcion: ","\nERROR, opcion invalida. \n",1,10,3)==-1)
        {
            printf("\nHa superado la cantidad de reintentos disponibles\n");
            opcion=11;
        }

        switch(opcion)
        {

        case 1:

            if(mostrarAutosColorSelec(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }

            break;
        case 2:
            if( mostrarAutosMarcaSelec(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;
        case 3:
            if(mostrarAutosMasViejos(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;

        case 4:
            if(mostrarAutosPorMarca(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;


        case 5:
            if( contarAutosColorMarcaSelec(autos,tamA,colores,tamC,marcas,tamM)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }

            break;
        case 6:
            if( mostrarMarcaMasSeleccionada(autos,tamA,colores,tamC,marcas,tamM)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;

        case 7:
            if( trabajosPorAuto(autos,tamA,trabajos,tamT,colores,tamC,marcas,tamM,servicios,tamS,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;

        case 8:
            if( importesPorAuto(autos,tamA,trabajos,tamT,colores,tamC,marcas,tamM,servicios,tamS,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;

        case 9:
            if( serviciosPorAuto(autos,tamA,trabajos,tamT,colores,tamC,marcas,tamM,servicios,tamS,clientes,tamCl)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }
            break;

        case 10:
           if( serviciosPorFecha(trabajos,tamT,servicios,tamS)==1)
            {
                printf("\nMuestra exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra\n\n");
            }

            break;

       case 11:
        printf("\nLa opcion no existe. \n");
        todoOk=-1;
        break;
        }
    }
    return todoOk;

}


int mostrarAutosPorMarca(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM, eCliente clientes[],int tamCl)
{
    system("cls");
    int todoOk=-1;
    int indice;
    int existeAuto=0;
    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && clientes!=NULL && tamCl>0)
    {
        for(int m=0; m<tamC; m++)
        {
            printf("\n-------------------------------------------------------------------------");
            printf("\n                       Total de la marca:  %s\n",marcas[m].descripcion);
            printf("-------------------------------------------------------------------------\n");
            printf(" ID     Patente   Modelo     Color      Marca     Cliente   \n");
            for(int a=0; a<tamA; a++)
            {
                if(autos[a].isEmpty==0 && autos[a].idMarca == marcas[m].id)
                {
                    indice= buscarAuto(autos,tamA,autos[a].patente);
                    mostrarAuto(autos[indice],colores,tamC,marcas,tamM,clientes,tamCl);
                    existeAuto=1;
                }

            }
            if(existeAuto==0)
            {
                printf("\nNo hay ningun para mostrar \n");
            }

        }
        todoOk=1;


    }

    return todoOk;
}

int mostrarAutosMasViejos(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[], int tamCl)
{
    system("cls");
    int todoOk=-1;
    int masViejo;
    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && clientes!=NULL && tamCl>0)
    {

        for(int a=0; a<tamA; a++)
        {
            if( (autos[a].modelo<masViejo || a==0 )&& autos[a].isEmpty==0)
            {
                masViejo= autos[a].modelo;
            }
        }
        printf("\n---------------------------------------------------------------");
        printf("\n                   El/los autos mas viejos           \n");
        printf("---------------------------------------------------------------\n");
        printf(" ID     Patente   Modelo     Color      Marca     Cliente   \n");
        for(int i=0; i<tamA; i++)
        {
            if(autos[i].isEmpty==0 && autos[i].modelo==masViejo)
            {
                mostrarAuto(autos[i],colores,tamC,marcas,tamM,clientes,tamCl);

            }
        }
        printf("---------------------------------------------------------------\n");
        todoOk=1;


    }

    return todoOk;
}

int mostrarAutosColorSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[], int tamCl)
{
    int todoOk=-1;
    int idColor;
    int existeAuto=0;
    char nombreColor[20];

    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 &&clientes!=NULL&&tamCl>0)
    {

        mostrarColores(colores,tamC);
        if(utn_getNumero(&idColor,"\nIngrese ID del color deseado: ", "\nERROR, El ID introducido no existe. \n",5000,5004,3)==-1)
        {
            printf("\nHa excedido los reintentos disponibles. \n");
        }
        else
        {
            system("cls");
            cargarDescripcionColor(idColor,colores,tamC,nombreColor);
            printf("\n---------------------------------------------------------------");
            printf("\n        Mostrar auto por color %s     \n", nombreColor );
            printf("---------------------------------------------------------------\n");
            printf(" ID     Patente   Modelo     Color      Marca     Cliente   \n");
            for(int a=0; a<tamA; a++)
            {
                if(autos[a].isEmpty==0 && autos[a].idColor == idColor)
                {
                    mostrarAuto(autos[a],colores,tamC,marcas,tamM,clientes,tamCl);
                    existeAuto=1;
                }
            }
            todoOk=1;
        }
        if(existeAuto==0)
        {
            printf("\nNo hay ningun auto con el color %s \n", nombreColor);
        }
        printf("---------------------------------------------------------------\n");
    }

    return todoOk;
}
int mostrarAutosMarcaSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[],int tamCl)
{
    int todoOk=-1;
    int idMarca;
    int existeAuto=0;
    char nombreMarca[20];

    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && clientes!=NULL && tamCl>0)
    {

        mostrarMarcas(marcas,tamM);
        if(utn_getNumero(&idMarca,"\nIngrese ID de la marca deseada: ", "\nERROR, El ID introducido no existe. \n",1000,1004,3)==-1)
        {
            printf("\nHa excedido los reintentos disponibles. \n");
        }
        else
        {
            system("cls");
            cargarDescripcionMarca(idMarca,marcas,tamM,nombreMarca);
            printf("\n------------------------------------------------------------");
            printf("\n            Mostrar autos de la marca %s     \n", nombreMarca );
            printf("------------------------------------------------------------\n");
            printf(" ID     Patente   Modelo     Color      Marca     Cliente   \n");
            for(int a=0; a<tamA; a++)
            {
                if(autos[a].isEmpty==0 && autos[a].idMarca == idMarca)
                {
                    mostrarAuto(autos[a],colores,tamC,marcas,tamM,clientes,tamCl);
                    existeAuto=1;
                }
            }
            todoOk=1;
        }
        if(existeAuto==0)
        {
            printf("\nNo hay ningun auto de la marca %s \n", nombreMarca);
        }
        printf("------------------------------------------------------------\n");
    }

    return todoOk;
}


int contarAutosColorMarcaSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM)
{
    int todoOk=-1;
    int idMarca;
    int idColor;
    int existeAuto=0;
    char nombreMarca[20];
    char nombreColor[20];
    int contadorAutosMarcaColor=0;

    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0)
    {

        mostrarMarcas(marcas,tamM);
        if(utn_getNumero(&idMarca,"\nIngrese ID de la marca deseada: ", "\nERROR, El ID introducido no existe. \n",1000,1004,3)==-1)
        {
            printf("\nHa excedido los reintentos disponibles. \n");
        }
        mostrarColores(colores,tamC);
        if(utn_getNumero(&idColor,"\nIngrese ID del color deseado: ", "\nERROR, El ID introducido no existe. \n",5000,5004,3)==-1)
        {
            printf("\nHa excedido los reintentos disponibles. \n");
        }
        else
        {
            system("cls");
            cargarDescripcionMarca(idMarca,marcas,tamM,nombreMarca);
            cargarDescripcionColor(idColor,colores,tamC,nombreColor);
            printf("\n---------------------------------------------------------");
            printf("\n     Cantidad autos de la marca %s  y de color %s   \n", nombreMarca,nombreColor );
            printf("---------------------------------------------------------\n");
            for(int a=0; a<tamA; a++)
            {
                if(autos[a].isEmpty==0 && autos[a].idMarca == idMarca && autos[a].idColor == idColor)
                {
                    contadorAutosMarcaColor++;
                    existeAuto=1;
                }
            }
            todoOk=1;
        }
        if(existeAuto==0)
        {
            printf("\nNo hay ningun auto de la marca %s y del color %s\n", nombreMarca,nombreColor);
        }
        printf("                La cantidad es de: %d", contadorAutosMarcaColor);
        printf("\n---------------------------------------------------------\n");
    }

    return todoOk;
}

int mostrarMarcaMasSeleccionada(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM)
{
    int todoOk=-1;
    int totalesMarca[tamM];
    int contadorMarca;
    int mayor=0;
    int flag;

    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0)
    {

        system("cls");

        printf("\n---------------------------------------------------------");
        printf("\n             Marca/marcas mas elegidas    \n");
        printf("---------------------------------------------------------\n");
        for(int m=0; m<tamM; m++)
        {
            contadorMarca=0;
            for(int a=0; a<tamA; a++)
            {
                if(autos[a].isEmpty==0 && autos[a].idMarca == marcas[m].id)
                {
                    contadorMarca++;
                }
            }
            totalesMarca[m]= contadorMarca;
        }
        todoOk=1;
        for(int i=0; i<tamM; i++)
        {
            if(flag==0 || totalesMarca[i]>mayor)
            {
                mayor =totalesMarca[i];
                flag=1;
            }
        }
        for(int i=0; i<tamM; i++)
        {
            if(mayor==totalesMarca[i])
            {
                printf("%s\n", marcas[i].descripcion);
            }

        }

        printf("---------------------------------------------------------\n");
    }

    return todoOk;
}

int trabajosPorAuto(eAuto autos[],int tamA, eTrabajo trabajos[], int tamT, eColor colores[],int tamC, eMarca marcas[], int tamM, eServicio servicios[], int tamS,eCliente clientes[],int tamCl)
{
    system("cls");
    int todoOk=-1;
    char nombrePatente[20];
    int indice;
    int flag=0;
    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && trabajos!=NULL && tamT>0 && servicios!=NULL && tamS>0 && clientes!=NULL && tamCl>0)
    {
        mostrarAutos(autos,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
        printf("\nIngrese la patente del auto: ");
        fflush(stdin);
        gets(nombrePatente);
        indice= buscarAuto(autos,tamA,nombrePatente);
        if(indice==-1)
        {
            printf("\n\nNo hay ningun auto registrado con la patente %s",nombrePatente);
            todoOk=-1;
        }
        else
        {
            printf("\n---------------------------------------------------------------");
            printf("\n     Servicios realizados al auto  de patente %s\n",nombrePatente);
            printf("---------------------------------------------------------------\n");
            printf("     PATENTE     ID       SERVICIO      FECHA   \n");
            for(int t=0; t<tamT; t++)
            {
                if(strcmp(trabajos[t].patente,nombrePatente)==0 && trabajos[t].isEmpty==0)
                {

                    mostrarTrabajo(trabajos[t],servicios,tamS);
                    flag=1;
                    todoOk=1;
                }

            }
            printf("\n---------------------------------------------------------------\n\n");
        }

    }
    if(flag==0)
    {
        printf("\nNo se han encontrado trabajos para el auto con patente %s\n",nombrePatente);
    }

    return todoOk;
}

int importesPorAuto(eAuto autos[],int tamA, eTrabajo trabajos[], int tamT, eColor colores[],int tamC, eMarca marcas[], int tamM, eServicio servicios[], int tamS, eCliente clientes[],int tamCl)
{
    system("cls");
    int todoOk=-1;
    char nombrePatente[20];
    int indice;
    int flag=0;
    float acumuladorImporte=0;
    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && trabajos!=NULL && tamT>0 && servicios!=NULL && tamS>0 && clientes!=NULL && tamCl>0)
    {
        mostrarAutos(autos,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
        printf("\nIngrese la patente del auto: ");
        fflush(stdin);
        gets(nombrePatente);
        indice= buscarAuto(autos,tamA,nombrePatente);
        if(indice==-1)
        {
            printf("\n\nNo hay ningun auto registrado con la patente %s",nombrePatente);
            todoOk=-1;
        }
        else
        {
            printf("\n---------------------------------------------------------------");
            printf("\n     Total importe  auto  de patente %s\n",nombrePatente);
            printf("---------------------------------------------------------------\n");
            for(int t=0; t<tamT; t++)
            {
                if(strcmp(trabajos[t].patente,nombrePatente)==0 && trabajos[t].isEmpty==0){
                for(int s=0; s<tamS; s++)
                {
                    if(servicios[s].id== trabajos[t].idServicio)
                    {
                        acumuladorImporte= acumuladorImporte+servicios[s].precio;
                        flag=1;
                    }

                }
            }

            }

            if(flag==1)
            {
                printf("\nEl importe total es de $%2.f \n", acumuladorImporte);
                printf("\n---------------------------------------------------------------\n\n");
                todoOk=1;
            }
            else
            {
                printf("\nNo se han encontrado trabajos para el auto con patente %s\n",nombrePatente);
            }

        }

    }


    return todoOk;
}

int serviciosPorAuto(eAuto autos[],int tamA, eTrabajo trabajos[], int tamT, eColor colores[],int tamC, eMarca marcas[], int tamM, eServicio servicios[], int tamS,eCliente clientes[],int tamCl)
{
    system("cls");
    int todoOk=-1;
    char nombrePatente[20];
    char servicioNombre[20];
    int indice;
    int flag=0;
    int idServicio;
    int idAuto;
    if(autos!=NULL && tamA>0 && colores!=NULL && tamC>0&& marcas!=NULL && tamM>0 && trabajos!=NULL && tamT>0 && servicios!=NULL && tamS>0 && clientes!=NULL && tamCl>0)
    {
        mostrarServicios(servicios,tamS);
        if(utn_getNumero(&idServicio,"\nIngrese ID del servicio: ", "\nERROR, El ID no existe.\n ",2000,2003,3)==-1)
        {
            printf("\nHa excedido los reintentos disponibles. \n");
        }
        else
        {
            cargarDescripcionServicio(idServicio,servicios,tamS,servicioNombre);
            system("cls");
            printf("\n\n----------------------------------------------------------------------------------------\n");
            printf("                       SERVICIO:%10s POR AUTO", servicioNombre);
            printf("\n----------------------------------------------------------------------------------------\n");
            for(int t=0; t<tamT; t++)
            {
                if(trabajos[t].isEmpty==0 && trabajos[t].idServicio == idServicio){
                obtenerIdPorPatente(autos,tamA,trabajos[t].patente,&idAuto);
                indice= buscarAuto(autos,tamA,trabajos[t].patente);
                }
                if(indice==-1)
                {
                    printf("\nNo existe un auto con esa parente\n");
                }
                else
                {
                    printf("\n");
                    printf(" ID     Patente   Modelo     Color      Marca     Cliente   \n");
                    mostrarAuto(autos[indice],colores,tamC,marcas,tamM,clientes,tamCl);
                    printf("\nEl servicio al auto de patente %s se lo realizo en la fecha %d/%d/%d\n",trabajos[t].patente, trabajos[t].fecha.dia,trabajos[t].fecha.mes,trabajos[t].fecha.anio);
                    printf("\n----------------------------------------------------------------------------------------\n");
                    flag=1;
                }

            }

            todoOk=1;

            if(flag==0)
            {
                printf("\nNo se han encontrado servicios para el auto con patente %s\n",nombrePatente);
            }
        }
    }



    return todoOk;
}
int serviciosPorFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    int todoOk=-1;
    eFecha auxFecha;
    int flag=0;
    if(trabajos!=NULL && tamT>0 && servicios!=NULL && tamS>0)
    {
        system("cls");
        printf("\n\n----------------------------------------------------------------------------------------\n");
        printf("                                TRABAJOS REALIZADOS EN UNA FECHA");
        printf("\n----------------------------------------------------------------------------------------\n\n");

        printf("\nIngrese fecha dd/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d", &auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
        while(validarFecha(auxFecha)==-1)
        {
            printf("\nERROR.Reingrese fecha dd/mm/aaaa: ");
            fflush(stdin);
            scanf("%d/%d/%d", &auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
        }
        system("cls");
        printf("\n\n---------------------------------------------------------------\n");
        printf("              TRABAJOS REALIZADOS EL %d/%d/%d" , auxFecha.dia,auxFecha.mes,auxFecha.anio);
        printf("\n---------------------------------------------------------------\n\n");


        for(int t=0; t<tamT; t++)
        {
            if(comparaFecha(auxFecha,trabajos[t].fecha)==1)
            {
                printf("     PATENTE     ID       SERVICIO      FECHA   \n");
                mostrarTrabajo(trabajos[t],servicios,tamS);
                printf("\n---------------------------------------------------------------\n\n");
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("\nNo se realizaron trabajos en la fecha %d/%d/%d\n",auxFecha.dia,auxFecha.mes,auxFecha.anio);

        }
        todoOk=1;

    }
    return todoOk;
}

