#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWareHouse.h"
#include "fecha.h"
char nombres[10][20] = {
       "Donato",
       "Carmen",
       "Chepi",
       "Alex",
       "German",
       "Maria",
       "Damian",
       "Daniel",
       "Andrea",
       "Candela"
};

char patentes[10][20] = {
       "KJN 605",
       "FJN 705",
       "LJN 805",
       "ARN 900",
       "MMN 300",
       "DSN 100",
       "FLN 200",
       "OPK 225",
       "LPA 215",
       "LIP 025"
};


char patentes2[10][20] = {
       "FJN 705",
       "KJN 605",
       "LJN 805",
       "LPA 215",
       "MMN 300",
       "MMN 300",
       "DSN 100",
       "OPK 225",
       "FLN 200",
       "LIP 025"
};

char sexos[10] = {'m','f','f','m','m','f','m','m','f','f'};

int edades[10]={56,71,39,30,52,45,44,58,38,29};

float sueldos[10]={10000,12000,11000,13200,11500,10800,13900,12100,11500,12400};

eFecha fechas[10]=
{
      {26,4,2011},
      {19,6,2018},
      {18,10,2020},
      {11,4,2016},
      {23,3,2014},
      {13,9,2013},
      {15,12,2008},
      {2,11,2010},
      {6,3,2018},
      {19,1,2011},

};

/*
eFecha fechas2[]=
{
      {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
};*/

int legajos[] ={20000,20006,20001,20005,20007,20002,20000,20004,20001,20003,20008,20001,20006,20003,20004,20008,20005,20000,20005,20003,20007,20009,20004};
int idColores[]={5000,5003,5002,5000,5000,5004,5002,5001,5004,5003,5003,5004,5000,5002,5004,5004,5001,5001,5000,5001,5002,5002,5000};
int idMarcas[]={1000,1003,1002,1000,1000,1004,1002,1001,1004,1003,1003,1004,1000,1002,1004,1004,1001,1001,1000,1001,1002,1002,1000};
int modelos[]={1999,1998,2002,2000,2010,2004,2002,2001,2020,2003,2003,2014,2015,2016,2017,2018,2001,2003,1000,2001,2002,2002,2014};
int idSectores[10]={503,504,502,502,501,500,503,502,500,504};
int idAutos[]={3000,3003,3002,3000,3000,3004,3002,3001,3004,3003,3003,3004,3000,3002,3004,3004,3001,3001,3000,3001,3002,3002,3000};
int idClientes[]={6000,6003,6002,6001,6003,6002,6000,6001,6002,6003,6003,6004,6000,6002,6004,6004,6001,6001,6000,6001,6002,6002,6000};
int idServicios[]={2000,2003,2002,2000,2000,2001,2002,2001,2004,2003,2003,2002,2000,2002,2001,2003,2001,2001,2000,2001,2002,2002,2000};
int hardcodearAutos(eAuto lista[],int tam, int cantidad, int* id)
{
    int cantidadAutosCargados=0;

    if(lista!=NULL && tam>0 && cantidad>=0 && cantidad<=tam && id!=NULL)
    {
        for(int i=0; i<cantidad; i++)
        {
            lista[i].id= *id;
            (*id)++;
            strcpy(lista[i].patente, patentes[i]);
            lista[i].idColor=idColores[i];
            lista[i].idMarca=idMarcas[i];
            lista[i].modelo=modelos[i];
            lista[i].isEmpty=0;
            lista[i].idCliente=idClientes[i];
            cantidadAutosCargados++;
        }
    }
    return cantidadAutosCargados;
}

int hardcodearTrabajos(eTrabajo trabajos[],int tam,int cantidad, int* id){

  int cantidadDeTrabajosCargados=0;

    if(trabajos!=NULL&&tam>0&&cantidad>0&& id!=NULL)
    {
        for(int i=0; i<cantidad; i++)
        {
            trabajos[i].id= *id;
            (*id)++;
            trabajos[i].fecha=fechas[i];
            strcpy(trabajos[i].patente, patentes2[i]);
            trabajos[i].idServicio=idServicios[i];
            trabajos[i].isEmpty=0;
            cantidadDeTrabajosCargados++;
        }
    }
    return cantidadDeTrabajosCargados;
}

