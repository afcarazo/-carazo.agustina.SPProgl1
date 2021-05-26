#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
int id;
char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED
/** \brief Muestra una marca
 *
 * \param marca eMarca marca a mostrar
 * \return void
 *
 */
void mostrarMarca(eMarca marca);
/** \brief imprime el contenido del array de marcas
 *
 * \param marcas[] eMarca array de marcas
 * \param tam int largo del array de marcas
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);
/** \brief  permite cargar el nombre de la marca deseada
 *
 * \param id int ID de la marca del cual se necesita el nombre
 * \param marcas[] eMarca array de marcas
 * \param tam int largo del array de marcas
 * \param descripcionMarca[] char nombre de la marca deseada
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int cargarDescripcionMarca(int id, eMarca marcas[],int tam,char descripcionMarca[]);

