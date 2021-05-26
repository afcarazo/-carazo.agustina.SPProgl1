#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
int id;
char nombre[20];
char sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief permite cargar el nombre de un cliente
 *
 * \param id int ID del cliente del cual se necesita el nombre
 * \param clientes[] eCliente array de clientes
 * \param tam int largo del array de clientes
 * \param nombre[] char nombre del cliente
 * \return int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int cargarNombre(int id, eCliente clientes[],int tam,char nombre[]);

/** \brief muestra un cliente
 *
 * \param cliente eCliente cliente que se mostrara
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);


/** \brief imprime el contenido del array de clientes
 *
 * \param clientes[] eCliente array de clientes
 * \param tam int largo de array de clientes
 * \return int int Devuelve (-1) si hay Error [Longitud no válida o puntero NULO] - (1) si está todo bien
 *
 */
int mostrarClientes(eCliente clientes[],int tam);
