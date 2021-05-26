#include "auto.h"
#include "trabajo.h"
#include "cliente.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief muestra menu de informes
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo de array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo del array de servicios
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int menuInformes(eAuto autos[], int tamA, eColor colores[],int tamC, eMarca marcas[], int tamM,eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT, eCliente clientes[],int tamCl);
/** \brief muestra los autos por marca
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarAutosPorMarca(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM, eCliente clientes[],int tamCl);
/** \brief muestra el/los autos mas viejos
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarAutosMasViejos(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[], int tamCl);
/** \brief muestra los autos del color seleccionado
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarAutosColorSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[], int tamCl);
/** \brief muestra los autos de la marca seleccionada
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarAutosMarcaSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[],int tamCl);
/** \brief cuenta los autos del color y marca que se ha selecionado
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int contarAutosColorMarcaSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM);
/** \brief muesta la marca mas seleccionada
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarMarcaMasSeleccionada(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM);

/** \brief muestra trabajos por auto seleccionado
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo de array de autos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int largo de array de trabajos
 * \param colores[] eColor array de colores
 * \param tamC int largo de array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo de array de marcas
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo de array de servicios
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int trabajosPorAuto(eAuto autos[],int tamA, eTrabajo trabajos[], int tamT, eColor colores[],int tamC, eMarca marcas[], int tamM, eServicio servicios[], int tamS,eCliente clientes[],int tamCl);


/** \brief muestra importe total del trabajo en un auto
 *
 * \param autos[] eAuto array de autos
 * \param tamA int largo de array de autos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int largo de array de trabajos
 * \param colores[] eColor array de colores
 * \param tamC int largo de array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo de array de marcas
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo de array de servicios
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int importesPorAuto(eAuto autos[],int tamA, eTrabajo trabajos[], int tamT, eColor colores[],int tamC, eMarca marcas[], int tamM, eServicio servicios[], int tamS, eCliente clientes[],int tamCl);

/** \brief pide un servicio y muestra los autos a los cuales se le realizo ese servicio con la fecha
 * \param autos[] eAuto array de autos
 * \param tamA int largo de array de autos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamT int largo de array de trabajos
 * \param colores[] eColor array de colores
 * \param tamC int largo de array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo de array de marcas
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo de array de servicios
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int serviciosPorAuto(eAuto autos[],int tamA, eTrabajo trabajos[], int tamT, eColor colores[],int tamC, eMarca marcas[], int tamM, eServicio servicios[], int tamS,eCliente clientes[],int tamCl);

/** \brief muestra los servicios realizados en la fecha ingresada
 *
 * \param trabajos[] eTrabajo array de trabajo
 * \param tamT int largo de array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tamS int largo de array de servicios
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int serviciosPorFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS);

#endif // INFORMES_H_INCLUDED

