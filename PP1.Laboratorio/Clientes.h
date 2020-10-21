#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED



#endif // CLIENTES_H_INCLUDED

typedef struct
{
    int idCliente;
    char Nombre[20];
    char sexo;
}eCliente;

int harcodeo_cliente(eCliente[]);
void buscar_cliente(eCliente clientes[],int id);
void mostrar_ClienteS(eCliente clientes[]);
void mostrar_Cliente(eCliente clientes);
