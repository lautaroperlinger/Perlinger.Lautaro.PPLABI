#include "Color.h"
#include "stdio.h"
#include "string.h"
#define FALSE 0
#define TRUE 1
//DESARROLLO DE LAS FUNCIONES DE COLOR
int hardcoreo_Color(eColor colores[])
{
    int iddcolor=5000;
    char Colores_data[5][20] ={"Gris","Negro","Blanco","Azul","Rojo"};
    int retorno = -1;
    if(colores != NULL)
    {
        retorno=FALSE;
        for(int i =0; i< 5; i++)
        {
            colores[i].idColor=iddcolor;
            strcpy(colores[i].nombreColor,Colores_data[i]);
            iddcolor++;
        }
    }
    return retorno;

}
void mostrar_Colores(eColor colores[])
{
    printf("---------COLOR DE BICICLETAS---------\n\n");
    printf("ID COLOR    COLOR\n\n");
    for(int i=0;i<5;i++)
    {
        mostrar_Color(colores[i]);
    }

}
void mostrar_Color(eColor colores)
{
    printf("%d        %3s \n",colores.idColor,colores.nombreColor);
}

