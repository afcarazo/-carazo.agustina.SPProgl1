#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
#include "color.h"
#include "fecha.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "input.h"
#include "cliente.h"
#include "informe.h"
#include "dataWareHouse.h"
#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMA 10
#define TAMT 10
#define TAMCL 4
void menu();
int main()
{
    eAuto autos[TAMA];
    eTrabajo trabajos[TAMT];
    eMarca marcas[TAMM]=
    {
        {1000,"Renault"},
        {1001,"Fiat"},
        {1002,"Ford"},
        {1003,"Chevrolet"},
        {1004,"Peugeot"},
    };

    eColor colores[TAMC]=
    {
        {5000,"Negro"},
        {5001,"Blanco"},
        {5002,"Gris"},
        {5003,"Rojo"},
        {5004,"Azul"},
    };

    eServicio servicios[TAMS]=
    {
        {2000,"Lavado", 250},
        {2001,"Pulido",300},
        {2002,"Encerado",400},
        {2003,"Completo",600},
    };
    eCliente clientes[TAMCL]=
    {
        {6000,"Juan", 'm'},
        {6001,"Carla",'f'},
        {6002,"Manuel",'m'},
        {6003,"Lucia",'f'},
    };
    inicializarAutos(autos,TAMA);
    inicializarTrabajos(trabajos,TAMT);
    int nextIdAuto=3000;
    int nextIdTrabajo=4000;
    //hardcodearAutos(autos,TAMA,10,&nextIdAuto);
    //hardcodearTrabajos(trabajos,TAMT,10,&nextIdTrabajo);
    char salir= 'n';
    int opcion;

    do
    {
        menu();
        if(utn_getNumero(&opcion, "\nIngrese opcion: ","\nERROR, opcion invalida. \n",1,11,3)==-1)
        {
            printf("\nDesea salir del programa?\n");
            opcion=11;
        }
        switch(opcion)
        {

        case 1:

            if(altaAuto(autos,TAMA,marcas,TAMM,colores, TAMC, &nextIdAuto,clientes,TAMCL)==1)
            {
                printf("\nAlta de auto exitosa\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar el alta del auto\n\n");
            }

            break;

        case 2:
            if(hayAutosActivos(autos,TAMA)!=0)
            {
                if(modificarAuto(autos,TAMA,colores,TAMC,marcas,TAMM,clientes,TAMCL)==1)
                {
                    printf("La modificacion del auto ha sido exitosa\n");
                }
                else
                {
                    printf("Hubo un problema al realizar la modificacion del auto\n");
                }
            }
            else
            {
                printf("\nPrimero deberias dar de alta un auto.\n\n");
            }
            break;

        case 3:
            if(hayAutosActivos(autos,TAMA)!=0)
            {
                if(bajaAuto(autos,TAMA,colores,TAMC,marcas,TAMM,clientes,TAMCL)==1)
                {
                    printf("\nLa baja del auto ha sido exitosa\n\n");
                }
                else
                {
                    printf("\nHubo un problema al realizar la baja del auto\n\n");
                }
            }
            else
            {
                printf("\nPrimero deberias dar de alta un auto.\n\n");
            }

            break;
        case 4:
            if( hayAutosActivos(autos,TAMA)!=0)
            {
                if(mostrarAutos(autos,TAMA,marcas,TAMM,colores,TAMC,clientes,TAMCL)==1)
                {
                    ordenarAutos(autos,TAMA,marcas,TAMM,colores,TAMC,clientes,TAMCL);
                }
                else
                {
                    printf("Ocurrio un error al mostrar la lista de autos\n");
                }
            }
            else
            {
                printf("\nPrimero deberias dar de alta un auto.\n\n");
            }
            break;


        case 5:

            if(mostrarMarcas(marcas,TAMM)==1)
            {
                printf("\nMuestra exitosa de marcas\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra de las marcas\n\n");
            }
            break;


        case 6:
            if(mostrarColores(colores,TAMC)==1)
            {
                printf("Muestra exitosa de colores\n");
            }
            else
            {
                printf("Hubo un problema al realizar la muestra de los colores\n");
            }
            break;
        case 7:
            if(mostrarServicios(servicios,TAMS)==1)
            {
                printf("\nMuestra exitosa de servicios\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra de servicios\n\n");
            }
            break;
        case 8:
            if(hayAutosActivos(autos,TAMA)!=0)
            {
                if(altaTrabajo(trabajos,TAMT,servicios,TAMS,autos,TAMA,marcas,TAMM,colores,TAMC,&nextIdTrabajo,clientes,TAMCL)==1)
                {
                    printf("Alta de trabajo exitosa\n");

                }
                else
                {
                    printf("Hubo un problema al realizar el alta del trabajo\n");
                }
            }
            else
            {
                printf("\nPrimero deberias dar de alta un auto.\n\n");
            }


            break;

        case 9:
            if(hayAutosActivos(autos,TAMA)!=0){
            if(mostrarTrabajos(trabajos,TAMT,servicios,TAMS)==1)
            {
                printf("\nMuestra exitosa de trabajos\n\n");
            }
            else
            {
                printf("\nHubo un problema al realizar la muestra de trabajos\n\n");
            }
            }else{
            printf("\nPrimero deberias dar de alta un auto.\n\n");
            }
            break;

            case 10:
            if(hayAutosActivos(autos,TAMA)!=0){
            if(menuInformes(autos,TAMA,colores,TAMC,marcas,TAMM,servicios,TAMS,trabajos,TAMT,clientes,TAMCL)==1)
            {
                //printf("\nMuestra exitosa de informes\n\n");
            }
            else
            {
                printf("\nHubo un problema al mostrar los informes\n\n");
            }
            }else{
            printf("\nPrimero deberias dar de alta un auto.\n\n");
            }
            break;


        case 11:
            printf("\nPara confirmar salida ingrese s de lo contrario n: ");
            fflush(stdin);
            scanf("%c", &salir);

            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
    }
    while(salir=='n');


    return 0;
}


void menu()
{
    system("cls");
    printf("\n------------------------\n");
    printf("        AUTOS ABM         " );
    printf("\n------------------------\n\n");
    printf("1.  Alta auto\n");
    printf("2.  Modificar auto\n");
    printf("3.  Baja auto\n");
    printf("4.  Listar autos\n");
    printf("5.  Listar marcas\n");
    printf("6.  Listar colores\n");
    printf("7.  Listar servicios\n");
    printf("8.  Alta trabajo\n");
    printf("9.  Listar trabajos\n");
    printf("10. Informes\n");
    printf("11. Salir\n");
    printf("\n------------------------\n\n");
}
