#include "marca.h"
#include "color.h"
#include "input.h"
#include "cliente.h"
#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{
int id;
char patente[20];
int idMarca;
int idColor;
int modelo;
int isEmpty;
int idCliente;
}eAuto;

#endif // AUTO_H_INCLUDED

/** \brief Indica que todas las posiciones están vacías.
 Esta función pone la bandera (isEmpty) en VERDADERO en en todas las posiciones del array
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int inicializarAutos(eAuto lista[], int tam);
/** \brief encuentra un espacio vacío y devuelve la posicion
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (indice) si está todo bien
 *
 */
int buscarLibre(eAuto lista[], int tam);
/** \brief Permite dar de alta un nuevo auto
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param marcas[] eMarca  array de marcas
 * \param tamM int largo del array de marcas
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param id int*  puntero al ID del nuevo auto
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int altaAuto(eAuto lista[], int tam,eMarca marcas[], int tamM,eColor colores[],int tamC, int* id,eCliente clientes[],int tamCl);
/** \brief encuentra un auto por su patente para devolver la posición
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param patente[] char patente a buscar
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (indice) si está todo bien
 *
 */
int buscarAuto(eAuto lista[], int tam, char patente[]);
/** \brief imprime el contenido del array de autos
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl);
/** \brief Muestra un auto
 *
 * \param unAuto eAuto auto que se mostrara
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarAuto(eAuto unAuto,eColor colores[],int tamC, eMarca marcas[],int tamM, eCliente clientes[],int tamCl);
/** \brief Permite modificar un auto
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int modificarAuto(eAuto lista[],int tam, eColor colores[],int tamC, eMarca marcas[], int tamM, eCliente clientes[],int tamCl);
/** \brief muestra menu de modificaciones y realiza la modificacion
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param indice int indice del auto a modificar
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int modificarMenu(eAuto lista[], int tam, int indice, eColor colores[], int tamC);
/** \brief permite ordenar la lista de autos
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param marca[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int ordenarAutos(eAuto lista[],int tam, eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl);
/** \brief Ordena los elementos en el array de autos alfabeticamente por marca,
en caso de que la marca se repita se ordena por patente de forma ascendente o descendente segun lo indicado
 * \param autos[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param ascendenteDescendente int opcion ascendente / descendente
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int organizarAutos(eAuto autos[],int tam,int ascendenteDescendente, eMarca marcas[],int tamM);
/** \brief permite dar de baja un auto
 *
 * \param autos[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param colores[] eColor array de colores
 * \param tamC int largo del array de colores
 * \param marcas[] eMarca array de marcas
 * \param tamM int largo del array de marcas
 * \param clientes[] eCliente array de clientes
 * \param tamCl int largo del array de clientes
 * \return int  Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int bajaAuto(eAuto autos[],int tam, eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[],int tamCl);
/** \brief permite cargar el nombre de la patente deseada
 *
 * \param id int ID del auto del cual se necesita el nombre de la patente
 * \param autos[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param nombrePatente[] char nombre de la patente deseada
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int cargarPatenteAuto(int id, eAuto autos[],int tam,char nombrePatente[]);
/** \brief verifica si hay algun auto cargado en el sistema
 *
 * \param autos[] eAuto array de autos
 * \param tam int largo del array de autos
 * \return int  Devuelve (0) sino hay ningun auto activo y (1) si hay algun auto activo
 *
 */
int hayAutosActivos(eAuto autos[], int tam);

/** \brief obtiene id del auto por su patente
 *
 * \param autos[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param patente[] char patente a buscar
 * \param pId int* puntero a donde se dejara el id del auto con la patente deseada
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int obtenerIdPorPatente(eAuto autos[], int tam,char patente[], int *pId);
