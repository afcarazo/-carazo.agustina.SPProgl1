#include "auto.h"
#include "trabajo.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

/** \brief hardcodea el array de autos
 *
 * \param lista[] eAuto array de autos
 * \param tam int largo del array de autos
 * \param cantidad int cantidad de autos hardcodeados
 * \param id int* puntero al ID de autos
 * \return int devuelve la cantidad que pudo cargar
 *
 */
int hardcodearAutos(eAuto lista[],int tam, int cantidad, int* id);
/** \brief hardcodea array de trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int largo del array de trabajos
 * \param cantidad int cantidad de trabajos hardcodeados
 * \param id int* puntero al ID de trabajos
 * \return int devuelve la cantidad de autos que pudo cargar
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[],int tam,int cantidad, int* id);
#endif // DATAWAREHOUSE_H_INCLUDED

