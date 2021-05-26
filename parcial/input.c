#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "input.h"


static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);
static int getInt(int* pResultado);
static int esPatente(char* cadena,int longitud);
static int getString(char* cadena, int longitud);
static int getDescripcion(char* pResultado, int longitud);
static int esLetra(char* cadena, int len);
static int getChar(char* pResultado, int len);
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
static int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        fflush(stdin);
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        fflush(stdin);
        printf("%s",mensajeError);
    }
    return retorno;
}


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
        if(	getString(buffer,sizeof(buffer))==0 &&
                esPatente(buffer,sizeof(buffer)) &&
                strnlen(buffer,sizeof(buffer))<longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es una patente valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esPatente(char* cadena,int longitud)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0) //nueve caracteres patente moderna
    {
        for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if( cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int get_patente(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}


/**
 * \brief Obtine una letra
 * \param pValor Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getChar(char* pResultado, int len)
{
    int retorno=-1;
    char bufferChar[2];

    if(pResultado != NULL && len >0)
    {
        if(	getString(bufferChar,sizeof(bufferChar))==0 && esLetra(bufferChar,sizeof(bufferChar)) && strnlen(bufferChar,sizeof(bufferChar))<len)
        {
            strncpy(pResultado,bufferChar,len);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Verifica si es una letra
 * \param pValor Puntero de caracter a ser analizado
 * \return Retorna 1 (verdadero) si es una letra, 0 (falso) si no lo es
 *
 */
static int esLetra(char* cadena, int len)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && len > 0)
    {
        for(i=0 ; cadena[i] != '\0' && i < len; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int utn_getChar(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferChar[2];
    int retorno = -1;
    if(pResultado != NULL && longitud >0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
        while(reintentos>=0)
        {
            reintentos--;
            printf("%s",mensaje);
            if(getChar(bufferChar,sizeof(bufferChar)) == 0 && strnlen(bufferChar,sizeof(bufferChar)) < longitud )
            {
                strncpy(pResultado,bufferChar,longitud);
                retorno = 0;
                break;
            }
            printf("%s",mensajeError);
        }
    return retorno;
}
