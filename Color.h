#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED



#endif // COLOR_H_INCLUDED
//ESTRUCTURA DE COLORES
typedef struct
{
    int idColor;
    char nombreColor[20];
}eColor;

//DOXYGEM Y PROTOTIPOS DE COLORES
/** \brief hardcordea los colores
 *
 * \param colores[] eColor el vector donde se guardan
 * \return int retorna 1 si es valido
 *
 */
int hardcoreo_Color(eColor colores[]);
/** \brief muestra toda la lista de colores
 *
 * \param Colores[] eColor vector donde estan guardados
 * \return void
 *
 */
void mostrar_Colores(eColor Colores[]);
/** \brief muestra un color en especifico
 *
 * \param Colores[] eColor vector donde se guardan
 * \return void
 *
 */
void mostrar_Color(eColor Colores);

