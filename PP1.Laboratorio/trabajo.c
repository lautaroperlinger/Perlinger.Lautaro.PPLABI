#include "trabajo.h"
#include "stdio.h"
#include "string.h"

//DESARROLLO DE LAS FUNCIONES DE TRABAJO
int alta_trabajo(eTrabajo trabajos[],eBicicleta Bicis[],eServicios servicios[],eCliente clientes[],int len_trabajos,int idtrabajos,int len_bicis)
{
    int error=-1;
    int indice;
    eTrabajo Nuevotrabajo;
    indice=Libre_Trabajo(trabajos,len_trabajos);
    if(trabajos!=NULL &&  len_trabajos>0)
    {
        printf("-----------------Alta de trabajos-------------------\n\n");
        if(indice!=-1)
        {
            Nuevotrabajo.id=idtrabajos;
            mostrar_BicicletaS(Bicis,len_bicis,clientes);
            printf("ingrese ID de la bicicleta.\n");
            fflush(stdin);
            scanf("%d",&Nuevotrabajo.idBici);
            mostrar_ServicioS(servicios);
            printf("ingrese el id del Servicio:\n");
            fflush(stdin);
            scanf("%d",&Nuevotrabajo.idServicio);
            printf("Ingrese ID del servicio.\n");
            while(Validacion_Servicio(servicios,Nuevotrabajo.idServicio)!=TRUE)
            {
                scanf("%d",&Nuevotrabajo.idServicio);
                printf("error,reingrese servicio.\n");
            }
            scanf("%d",&Nuevotrabajo.fechas.dia);
            while(Validacion_fecha(Nuevotrabajo.fechas)!=TRUE)
            {
                printf("error,reingrese dia.\n");
                scanf("%d",&Nuevotrabajo.fechas.dia);
            }
            printf("Ingrese mes.\n");
            scanf("%d",&Nuevotrabajo.fechas.mes);
            while(Validacion_mes(Nuevotrabajo.fechas)!=TRUE)
            {
                printf("error,reingrese mes.\n");
                scanf("%d",&Nuevotrabajo.fechas.mes);
            }
            printf("Ingrese anio.\n");
            scanf("%d",&Nuevotrabajo.fechas.anio);
            while(Validacion_anio(Nuevotrabajo.fechas)!=TRUE)
            {
                printf("error,reingrese anio.\n");
                scanf("%d",&Nuevotrabajo.fechas.anio);
            }
            Nuevotrabajo.isEmpty=TRUE;
            trabajos[indice]=Nuevotrabajo;
            error=FALSE;
        }
        else
        {
            printf("no hay memoria.\n");

        }
    }
    return error;

}
int Libre_Trabajo(eTrabajo trabajos[],int len_trabajos)//pone true en la bandera isEmpty
{
    int ver=-1;

    for(int i=0;i<len_trabajos;i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            ver=i;
        }
    }
    return ver;
}
void mostrar_trabajoS(eTrabajo trabajos[],int len_trabajos)
{
    printf("------------------TRABAJOS DE BICIS----------------------\n\n");
    printf("ID TRABAJO    ID BICICLETA    ID SERVICIO     FECHA      \n\n");
    for(int i=0;i<len_trabajos;i++)
    {
        if(trabajos[i].isEmpty==TRUE)
        {
            mostrar_trabajo(trabajos[i]);
        }
        else
        {
            printf("**************************************************************\n\n");
        }
    }
}
void mostrar_trabajo(eTrabajo trabajos)
{
    printf("%d         %5d                %5d          %5d|%5d|%5d \n",trabajos.id,trabajos.idBici,trabajos.idServicio,trabajos.fechas.dia,trabajos.fechas.mes,trabajos.fechas.anio);

}
