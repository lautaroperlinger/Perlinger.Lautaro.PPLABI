#include "Tipos.h"
#include "string.h"
#include "stdio.h"
//DESARROLLO DE LAS FUNCIONES DE TIPO
int hardcoreo_Tipo(eTipo tipos[])
{
    int iddtipo=1000;
    char Tipos_data[4][20]={"Rutera","Carrera","Mountain","BMX"};
    int retorno = -1;
    if(tipos != NULL)
    {
        retorno=0;
        for(int i =0; i< 4; i++)
        {
            tipos[i].idTipo=iddtipo;
            strcpy(tipos[i].descripcion,Tipos_data[i]);
            iddtipo++;
        }
    }
    return retorno;
}
void mostrar_TipoS(eTipo tipos[])
{
    printf("---------TIPOS DE BICIS---------\n\n");
    printf("ID TIPO      TIPO\n\n");
    for(int i=0;i<4;i++)
    {
        mostrar_Tipo(tipos[i]);
    }
}
void mostrar_Tipo(eTipo tipos)
{
    printf("%d        %5s\n",tipos.idTipo,tipos.descripcion);
}

