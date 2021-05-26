#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


#endif // FECHA_H_INCLUDED

/** \brief compara si dos fechas son iguales
 *
 * \param fechaUno eFecha primer fecha a comparar
 * \param fechaDos eFecha segunda fecha a comparar
 * \return int devuelve 1 si son iguales y 0 sino lo son
 *
 */
int comparaFecha(eFecha fechaUno, eFecha fechaDos);
/** \brief valida si la fecha ingresada existe
 *
 * \param fecha eFecha fecha a ser evaluada
 * \return int Devuelve (-1) si hay Error- (1) si es una fecha valida
 *
 */
int validarFecha(eFecha fecha);
