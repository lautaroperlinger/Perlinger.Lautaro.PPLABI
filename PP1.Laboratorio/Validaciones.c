#include "Validaciones.h"
#include "stdio.h"
#include "string.h"

//DESARROLLO DE LAS FUNCIONES DE VALIDACION
int validacion_Tipo(eTipo Tipos[],int idtipo)
{

    int valido=FALSE;
    for(int i=0;i<4;i++)
    {
        if(Tipos[i].idTipo==idtipo)
        {
           valido=TRUE;
           break;
        }
    }
    return valido;
}
int validacion_Color(eColor Colores[],int idcolor)
{
    int valido=FALSE;
    for(int i=0;i<5;i++)
    {
        if(Colores[i].idColor==idcolor)
        {
           valido=TRUE;
           break;
        }
    }
    return valido;

}
int Validacion_Rodados(float auxiliar)
{
    int valido=FALSE;
    if(auxiliar==20 ||auxiliar==26 ||auxiliar== 27.5 || auxiliar==29)
    {
        valido=TRUE;
    }
    return valido;
}
int Validacion_Servicio(eServicios servicios[],int idservicio)
{
    int valido=FALSE;
    for(int i=0;i<5;i++)
    {
        if(servicios[i].idServicio==idservicio)
        {
           valido=TRUE;
           break;
        }
    }
    return valido;

}
int Validacion_fecha(eFecha fecha)
{
    int valido=FALSE;
    if(fecha.dia>0&&fecha.dia<32&&fecha.dia!=NULL)
    {
        valido=TRUE;
    }
    return valido;
}
int Validacion_mes(eFecha fecha)
{
    int valido=FALSE;
    if(fecha.mes>0&&fecha.mes<13&&fecha.mes!=NULL)
    {
        valido=TRUE;
    }
    return valido;
}
int Validacion_anio(eFecha fecha)
 {
    int valido=FALSE;
    if(fecha.anio>0&&fecha.anio!=NULL)
    {
        valido=TRUE;
    }
    return valido;
 }
