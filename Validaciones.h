#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "Tipos.h"
#include "Color.h"
#include "servicios.h"
#include "fecha.h"
#define FALSE 0
#define TRUE 1
#endif // VALIDACIONES_H_INCLUDED

//DOXYGEM Y PROTOTIPOS DE VALIDACIONES
/** \brief valida el ID del tipo
 *
 * \param Tipos[] eTipo ingresa el vector tipos
 * \param idtipo int    ingrese el ID a comparar
 * \return int  retorna 1 si es valido
 *
 */
int validacion_Tipo(eTipo Tipos[],int idtipo);
/** \brief valido el ID del color
 *
 * \param Colores[] eColor ingresa el vector de colores
 * \param idcolor int   ID a comparar
 * \return int retorna 1 si es valido
 *
 */
int validacion_Color(eColor Colores[],int idcolor);
/** \brief compara los rodados y los valido
 *
 * \param auxiliar float rodado a comparar
 * \return int retorna 1 si es valido
 *
 */
int Validacion_Rodados(float auxiliar);
/** \brief valida el ID de servicios
 *
 * \param servicios[] eServicios ingresa el vector de servicios
 * \param idservicio int ID a comparar
 * \return int retorna 1 si es valido
 *
 */
int Validacion_Servicio(eServicios servicios[],int idservicio);
/** \brief Valida que el dia este correcta
 *
 * \param fecha eFecha ingresa el dia a comparar
 * \return int retorna 1 si es valido
 *
 */
int Validacion_fecha(eFecha fecha);
/** \brief Valida que el mes este correcto
 *
 * \param mes eFecha ingresa el mes a comparar
 * \return int retorna 1 si es valido
 *
 */
int Validacion_mes(eFecha mes);
/** \brief valida el anio
 *
 * \param anio eFecha ingresa el anio a comparar
 * \return int retorna 1 si es valido;
 *
 */
int Validacion_anio(eFecha anio);
