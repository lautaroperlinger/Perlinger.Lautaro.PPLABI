#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
#include "Clientes.h"
#include "Validaciones.h"

#endif // BICICLETAS_H_INCLUDED
//ESTRUCTURA DE BICICLETAS
typedef struct
{
    int idBici;
    char marca[20];
    int idCliente;
    int TipoBici;
    int ColorBici;
    float rodados;
    int isEmpty;

 }eBicicleta;

//DOXYGEM Y PROTOTIPOS DE BICICLETAS
/** \brief da de alta una bicicleta
 *
 * \param Bicis[] eBicicleta vector donde se guarda
 * \param tipos[] eTipo muestra y valida el ingreso del Id del tipo
 * \param colores[] eColor muestra y valida el ingreso del Id del color
 * \param len int tamaño del vector donde se guarda
 * \param id int ingresa el ID de la nueva bicicleta
 * \return int retorna 0 si es valido
 *
 */
int alta_bicicleta(eBicicleta Bicis[],eTipo tipos[],eColor colores[],eCliente clientes[],int len,int id);
/** \brief modifica una bicicleta ingresada
 *
 * \param Bicis[] eBicicleta donde se encuentra guardada la bicicleta
 * \param tipos[] eTipo muestra y valida el ingreso del Id del tipo a modificar
 * \param len int tamaño del vector donde se guarda
 * \param id int ID de la bici a modificar
 * \return int retorna 0 si es valido
 *
 */
int modificar_bicicleta(eBicicleta Bicis[],eTipo tipos[],int len,int id);
/** \brief da de baja una bicicleta guardada
 *
 * \param Bicis[] eBicicleta donde se encuentra guardada la bicicleta
 * \param id int    el ID de la bicicleta a dar de baja
 * \return int  retorna 0 si es valido
 *
 */
int baja_bicicleta(eBicicleta Bicis[],int id);
/** \brief ordena laas bicicletas por tipos y rodados
 *
 * \param Bicis[] eBicicleta vector donde se guardan todas las bicis
 * \param len_bicis int tamaño del vector
 * \return int retorna  0 si es valido
 *
 */
int listar_bicicletas(eBicicleta Bicis[],int len_bicis);
/** \brief buscar un lugar disponible
 *
 * \param Bicis[] eBicicleta vector donde se va a buscar
 * \param len_bicis int tamaño del vector
 * \return int retorna el lugar disponible
 *
 */
int Lugar_Libre(eBicicleta Bicis[],int len_bicis);
/** \brief busca una bicicleta por ID
 *
 * \param Bicis[] eBicicleta vector donde se guardan las bicicletas
 * \param len_bicis int tamaño del vector donde se guardan
 * \param id int ID a buscar
 * \return int retorna la posicion de la bicicleta en el vector
 *
 */
int encontrar_Bici(eBicicleta Bicis[],int len_bicis,int id);
/** \brief valida el ID de la bicicleta
 *
 * \param Bicis[] eBicicleta vector donde se guardan las bicicletas
 * \param idbici int ID a comparar
 * \return int retorna 1 si es valido
 *
 */
int Validacion_idBici(eBicicleta Bicis[],int idbici);
/** \brief imprime todo el listado de bicicletas
 *
 * \param Bicis[] eBicicleta vector donde se guardan las bicicletas
 * \param len_bicis int tamaño del vector
 * \return void
 *
 */
void mostrar_BicicletaS(eBicicleta Bicis[],int len_bicis,eCliente clientes[]);
/** \brief muestra una bicicleta en especifico
 *
 * \param Bicis eBicicleta bicicleta a mostrar
 * \return void
 *
 */
void mostrar_BicicletaS_XColores(eBicicleta Bicis[],int id_color,int len_bicis,eCliente clientes[]);
void mostrar_BicicletaS_XTipo(eBicicleta Bicis[],int id_tipo,int len_bicis,eCliente clientes[]);
void Informar_menorRodado(eBicicleta Bicis[],int len_bicis,eCliente clientes[]);
void Informar_SeparadoTipo(eBicicleta Bicis[],eTipo tipos[],int len_bicis,eCliente clientes[]);
int Contar_color_tipo(eBicicleta Bicis[],int len_bicis,int id_color,int id_tipo);
void mostrar_Bicicleta(eBicicleta Bicis,eCliente clientes[]);
/** \brief crea espacio libre en el vector a iniciar
 *
 * \param Bicis[] eBicicleta vector que se inicia
 * \param len_bicis int tamaño del vector que se inicia
 * \return void
 *
 */
void iniciar_Bicis(eBicicleta Bicis[],int len_bicis);
/** \brief menu de opciones
 *
 * \return int retorna la opcion
 *
 */
int menu();
int menu_listar();
