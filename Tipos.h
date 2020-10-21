#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED



#endif // TIPOS_H_INCLUDED
//ESTRUCTURA DE TIPO
typedef struct
{
    int idTipo;
    char descripcion[20];
}eTipo;

//DOXYGEM Y PROTOTIPOS DE TIPOS
/** \brief harcodea los tipos
 *
 * \param tipos[] eTipo vector a guardar los tipos
 * \return int retorna 1 si es valido
 *
 */
int hardcoreo_Tipo(eTipo tipos[]);
/** \brief muestra el listado de tipos
 *
 * \param tipos eTipo vector donde estan guardados
 * \return void
 *
 */
void mostrar_Tipo(eTipo tipos);
/** \brief muestra un tipo en especifico
 *
 * \param tipos[] eTipo vector donde esta guardado
 * \return void
 *
 */
void mostrar_TipoS(eTipo tipos[]);

