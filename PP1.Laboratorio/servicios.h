#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED



#endif // SERVICIOS_H_INCLUDED
//ESTRUCTURA DE SERVICIOS
typedef struct
{
    int idServicio;
    char descripcion[25];
    float precios;

}eServicios;

//DOXYGEM Y PROTOTIPOS DE SERVICIOS
/** \brief harcodea los servicios
 *
 * \param servicios[] eServicios vector donde se guarda los servicios
 * \return int retorna 1 si es valido
 *
 */
int hardcoreo_Servicio(eServicios servicios[]);
/** \brief muestra un servicio en especifico
 *
 * \param servicios[] eServicios vector donde se encuentra guardado
 * \return void
 *
 */
void mostrar_Servicio(eServicios servicios);
/** \brief muestra el listado de servicios
 *
 * \param servicios[] eServicios vector donde estan guardados lo servicios
 * \return void
 *
 */
void mostrar_ServicioS(eServicios servicios[]);
