#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
int id;
char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED


/** \brief Muestra un color
 *
 * \param color eColor color a mostrar
 * \return void
 *
 */
void mostrarColor(eColor color);
/** \brief imprime el contenido del array de colores
 *
 * \param colores[] eColor array de colores
 * \param tam int largo del array de colores
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarColores(eColor colores[], int tam);
/** \brief  permite cargar el nombre del color deseado
 *
 * \param id int ID del color del cual se necesita el nombre
 * \param colores[] eColor array de colores
 * \param tam int largo del array de colores
 * \param descripcionColor[] char nombre del color deseado
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int cargarDescripcionColor(int id, eColor colores[],int tam,char descripcionColor[]);
