#include "servicios.h"
#include "stdio.h"
#include "string.h"
//DESARROLLO DE LAS FUNCIONES DE SERVICIOS
int hardcoreo_Servicio(eServicios servicios[])
{
    int iddservicio=20000;
    char Servicios_data[4][25]={"Limpieza","Parche","Centrado","Cadena"};
    float precios[4]={250,300,400,350};
    int retorno = -1;
    if(servicios != NULL)
    {
        retorno=0;
        for(int i =0; i< 4; i++)
        {
            servicios[i].idServicio=iddservicio;
            strcpy(servicios[i].descripcion,Servicios_data[i]);
            servicios[i].precios=precios[i];
            iddservicio++;
        }
    }
    return retorno;
}
void mostrar_ServicioS(eServicios servicios[])
{
    printf("---------SERVICIOS DE BICIS---------\n\n");
    printf("ID SERVICIO     SERVICIOS      PRECIOS\n\n");
    for(int i=0;i<4;i++)
    {
        mostrar_Servicio(servicios[i]);
    }
}
void mostrar_Servicio(eServicios servicios)
{
    printf("%d        %5s          %5.2f\n",servicios.idServicio,servicios.descripcion,servicios.precios);
}

