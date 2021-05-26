#include "fecha.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED


typedef struct{
int id;
char patente[20];
int idServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;



#endif // TRABAJO_H_INCLUDED
/** \brief Indica que todas las posiciones están vacías.
 Esta función pone la bandera (isEmpty) en VERDADERO en en todas las posiciones del array
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int largo del array de trabajos
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int inicializarTrabajos(eTrabajo trabajos[],int tam);
/** \brief Permite dar de alta un nuevo trabajo
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int largo del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo del array de servicios
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo de array de marcas
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param id int* puntero al ID del nuevo trabajo
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int altaTrabajo(eTrabajo trabajos[],int tam, eServicio servicios[],int tamS, eAuto autos[],int tamA, eMarca marcas[],int tamM,eColor colores[],int tamC, int *id,eCliente clientes[],int tamCl);
/** \brief verifica si se trata de una fecha valida
 *
 * \param fecha eTrabajo fecha del trabajo a ser evaluda
 * \return int Devuelve (-1) si no es una fecha valida - (1) si es una fecha valida
 *
 */
int validarFechaTrabajo(eTrabajo fecha);
/** \brief encuentra un espacio vacío y devuelve el índice
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tam int largo del array de trabajos
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (indice) si está todo bien
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[],int tam);

/** \brief muestra un trabajo
 *
 * \param trabajo eTrabajo trabajo que se mostrara
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo del array de servicios
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarTrabajo(eTrabajo trabajo, eServicio servicios[],int tamS);
/** \brief imprime el contenido del array de trabajos
 *
 * \param trabajo[] eTrabajo array de trabajos
 * \param tam int largo de array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo de array de servicios
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarTrabajos(eTrabajo trabajo[],int tam,eServicio servicios[],int tamS);
