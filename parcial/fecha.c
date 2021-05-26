#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
int comparaFecha(eFecha fechaUno, eFecha fechaDos)
{
    int esIgual=0;

    if(fechaUno.dia==fechaDos.dia&& fechaUno.mes==fechaDos.mes&& fechaUno.anio==fechaDos.anio)
    {
        esIgual=1;
    }
    return esIgual;
}


int validarFecha(eFecha fecha)
{
    int todoOk=-1;

    if ( fecha.mes >= 1 && fecha.mes <= 12 && fecha.anio>1900 && fecha.anio<=2021 )
    {
        switch ( fecha.mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( fecha.dia >= 1 && fecha.dia <= 31)
            {
                todoOk=1;
            }
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( fecha.dia >= 1 && fecha.dia <= 30 )
            {
                todoOk=1;
            }
            break;

        case  2 :

            if( (fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0) )
            {
                if ( fecha.dia >= 1 && fecha.dia <= 29)
                {
                    todoOk=1;
                }
            }
            else if( fecha.dia >= 1 && fecha.dia <= 28)
            {
                todoOk=1;
            }
          break;

        }

    }
    return todoOk;
}
