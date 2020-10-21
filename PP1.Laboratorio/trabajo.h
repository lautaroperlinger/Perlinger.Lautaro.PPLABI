#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "bicicletas.h"
#endif // TRABAJO_H_INCLUDED
//ESTRUCTURAS DE TRABAJOS
typedef struct
{
    int id;
    int idBici;
    int idServicio;
    eFecha fechas;
    int isEmpty;
}eTrabajo;
//DOXYGEM Y PROTOTIPOS DE TRABAJOS
/** \brief da de alta un trabajo
 *
 * \param trabajos[] eTrabajo vector donde se va a guardar
 * \param Bicis[] eBicicleta   muestra y valida el ID de las bicis
 * \param servicios[] eServicios muestra y valida el ID de los servicios
 * \param len_trabajos int tamaño del vector donde se van a guardar las bicis
 * \param idtrabajos int ID del trabajo nuevo
 * \param len_bicis int tamaño del vector de bicicletas
 * \return int retorna 0 si es valido
 *
 */
int alta_trabajo(eTrabajo trabajos[],eBicicleta Bicis[],eServicios servicios[],eCliente clientes[],int len_trabajos,int idtrabajos,int len_bicis);
/** \brief busca un lugar libre en el vector a guardar
 *
 * \param trabajos[] eTrabajo vector a buscar el espacio libre
 * \param len_trabajos int tamaño del vector
 * \return int retorna el lugar del espacio libre
 *
 */
int Libre_Trabajo(eTrabajo trabajos[],int len_trabajos);
/** \brief imprime todo el listado de trabajos
 *
 * \param trabajos[] eTrabajo vector de trabajos a mostrar
 * \param len_trabajos int tamaño del vector
 * \return void
 *
 */
void mostrar_trabajoS(eTrabajo trabajos[],int len_trabajos);
/** \brief imprime un trabajo en especifico
 *
 * \param trabajos[] eTrabajo vector donde se guarda el trabajo
 * \return void
 *
 */
void mostrar_trabajo(eTrabajo trabajos);
