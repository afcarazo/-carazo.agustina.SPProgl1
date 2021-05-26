#include "auto.h"
#include "fecha.h"
#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
int id;
char descripcion[25];
float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
/** \brief Muestra un servicio
 *
 * \param servicio eServicio servicio a mostrar
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);
/** \brief imprime el contenido del array de servicios
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int largo de array de servicios
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarServicios(eServicio servicios[], int tam);
/** \brief permite saber si se trata de un ID valido o no
 *
 * \param id int ID que se buscara
 * \param servicios[] eServicio array de servicios
 * \param tam int largo del array de servicios
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO-ID no existe] - (1) si está todo bien y es valido
 *
 */
int buscarIdSevicio(int id,eServicio servicios[],int tam);
/** \brief permite cargar el nombre del servicio deseado
 *
 * \param id int ID del servicios del cual se necesita el nombre
 * \param servicios[] eServicio array de servicios
 * \param tam int largo del array de servicios
 * \param descripcionServicio[] char nombre del servicio deseado
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[],int tam,char descripcionServicio[]);
