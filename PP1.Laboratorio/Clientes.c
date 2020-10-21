#include "Clientes.h"
#include "stdio.h"
#include "string.h"
#define FALSE 0
#define TRUE 1

int harcodeo_cliente(eCliente clientes[])
{
    int iddclientes=2000;
    char Nombre_data[5][20]={"Sofia","Ignacio","Mateo","Nicolas","Aylen"};
    char Sexo_data[5]={'f','m','m','m','f'};
    int retorno = -1;
    if(clientes != NULL)
    {
        retorno=FALSE;
        for(int i =0; i< 5; i++)
        {
            clientes[i].idCliente=iddclientes;
            strcpy(clientes[i].Nombre,Nombre_data[i]);
            clientes[i].sexo=Sexo_data[i];
            iddclientes++;
        }
    }
    return retorno;
}
void mostrar_ClienteS(eCliente clientes[])
{
    printf("----------------------- CLIENTES------------------------\n\n");
    printf("ID CLIENTE            NOMRBRE              SEXO         \n\n");
    for(int i=0;i<5;i++)
    {
            mostrar_Cliente(clientes[i]);
    }
}
void buscar_cliente(eCliente clientes[],int id)
{
    char auxnombre[20];
    for(int i=0;i<5;i++)
    {
        if(clientes[i].idCliente==id)
        {
            strcpy(auxnombre,clientes[i].Nombre);
        }
    }
    printf("%7s       ",auxnombre);
}
void mostrar_Cliente(eCliente clientes)
{
    printf("%d              %10s                     %10c   \n",clientes.idCliente,clientes.Nombre,clientes.sexo);
}
