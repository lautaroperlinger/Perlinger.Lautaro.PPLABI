#include "bicicletas.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
//DESARROLLO DE LAS FUNCIONES DE BICICLETAS
int alta_bicicleta(eBicicleta Bicis[],eTipo tipos[],eColor colores[],eCliente clientes[],int len_bicis,int id)
{
    int error=-1;
    int indice;
    float auxrodado;
    eBicicleta Nuevabici;
    indice=Lugar_Libre(Bicis,len_bicis);
    if(Bicis!=NULL && len_bicis>0)
    {
        printf("----------Alta de bicicletas----------\n\n");
        if(indice!=-1)
        {
            Nuevabici.idBici=id;
            printf("ingrese marca: \n");
            fflush(stdin);
            gets(Nuevabici.marca);
            mostrar_ClienteS(clientes);
            printf("ingrese ID del cliente:\n");
            scanf("%d",&Nuevabici.idCliente);
            mostrar_TipoS(tipos);
            printf("ingrese el ID del Tipo:\n");
            fflush(stdin);
            scanf("%d",&Nuevabici.TipoBici);
            while(validacion_Tipo(tipos,Nuevabici.TipoBici)!=TRUE)
            {
                printf("el tipo no existe. reingrese otro ID: \n");
                fflush(stdin);
                scanf("%d",&Nuevabici.TipoBici);
            }
            mostrar_Colores(colores);
            printf("ingrese el ID del Color:\n");
            fflush(stdin);
            scanf("%d",&Nuevabici.ColorBici);
            while(validacion_Color(colores,Nuevabici.ColorBici)!=TRUE)
            {
                printf("el color no existe. reingrese otro ID: \n");
                fflush(stdin);
                scanf("%d",&Nuevabici.ColorBici);
            }
            printf("ingrese el rodado: \n");
            fflush(stdin);
            scanf("%f", &auxrodado);
            while(Validacion_Rodados(auxrodado)!=TRUE)
            {
                printf("Rodados no disponibles!\n. Ingrese uno valido: ");
                fflush(stdin);
                scanf("%f",&auxrodado);
            }
            Nuevabici.rodados=auxrodado;
            Nuevabici.isEmpty=TRUE;
            Bicis[indice]=Nuevabici;
            error=FALSE;
        }
        else
        {
            printf("no hay memoria.\n");
        }

    }
    return error;

}
int modificar_bicicleta(eBicicleta Bicis[],eTipo tipos[],int len,int id)
{
    int error=TRUE;
    int auxopcion;
    int auxtipo;
    float auxrodado;
    if(Bicis[id].isEmpty==TRUE)
    {
        printf("Que quiere modificar?\n1-Tipo\n2-Rodado.\n");
        scanf("%d",&auxopcion);
        switch(auxopcion)
        {
            case 1:
                mostrar_TipoS(tipos);
                printf("ingrese el id del Tipo:\n");
                fflush(stdin);
                scanf("%d",&auxtipo);
                while(validacion_Tipo(tipos,auxtipo)==TRUE)
                {
                    printf("el tipo no existe. reingrese otro id: \n");
                    fflush(stdin);
                    scanf("%d",&auxtipo);
                }
                break;
            case 2:
                printf("ingrese el rodado: \n");
                fflush(stdin);
                scanf("%f", &auxrodado);
                while(Validacion_Rodados(auxrodado)==TRUE)
                {
                    printf("Rodados no disponibles!\n. Ingrese uno valido: ");
                    fflush(stdin);
                    scanf("%f",&auxrodado);
                }
            error=FALSE;
                break;
            default:
                printf("opcion incorrecta.");
                break;
        }

    }
    return error;
}
int baja_bicicleta(eBicicleta Bicis[],int id)
{
    int error=-1;
    if(Bicis[id].isEmpty==TRUE)
    {
        Bicis[id].isEmpty=FALSE;
        error=TRUE;
    }
    else
    {
        printf("no existe esa bici.\n");
        error=FALSE;
    }
    return error;
}
int listar_bicicletas(eBicicleta Bicis[],int len_bicis)
{
    int error=0;
    char auxchar[20];
    int auxint;
    float auxrodado;

    for(int i=0;i<len_bicis;i++)
    {
        for(int j=i+1;j<len_bicis;j++)
        {
            if(Bicis[i].isEmpty==TRUE&&Bicis[j].isEmpty==TRUE)
            {
                if(Bicis[i].TipoBici>Bicis[j].TipoBici&&Bicis[i].rodados>Bicis[j].rodados)
                {
                    auxint=Bicis[j].idBici;
                    Bicis[j].idBici=Bicis[i].idBici;
                    Bicis[i].idBici=auxint;

                    strcpy(auxchar, Bicis[i].marca);
                    strcpy(Bicis[i].marca, Bicis[j].marca);
                    strcpy(Bicis[j].marca, auxchar);

                    auxint=Bicis[j].TipoBici;
                    Bicis[j].TipoBici=Bicis[i].TipoBici;
                    Bicis[i].TipoBici=auxint;

                    auxint=Bicis[j].ColorBici;
                    Bicis[j].ColorBici=Bicis[i].ColorBici;
                    Bicis[i].ColorBici=auxint;

                    auxrodado=Bicis[j].rodados;
                    Bicis[j].rodados=Bicis[i].rodados;
                    Bicis[i].rodados=auxrodado;
                }
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}
void iniciar_Bicis(eBicicleta Bicis[],int len_bicis)
{
    for(int i=0; i<len_bicis; i++)
    {
        Bicis[i].isEmpty=0;
    }
}
int Lugar_Libre(eBicicleta Bicis[],int len_bicis)//pone true en la bandera isEmpty
{
    int ver=-1;

    for(int i=0;i<len_bicis;i++)
    {
        if(Bicis[i].isEmpty==0)
        {
            ver=i;
        }
    }
    return ver;
}
int encontrar_Bici(eBicicleta Bicis[],int len_bicis,int id)
{
    int idBici;
       for(int i=0;i<len_bicis;i++)
        {
            if(Bicis[i].idBici==id)
            {
                if(Bicis[i].isEmpty==TRUE)
                {
                    idBici=i;
                }
            }
        }
    return idBici;
}
void mostrar_BicicletaS(eBicicleta Bicis[],int len_bicis,eCliente clientes[])
{
    printf("---------------------- BICICLETAS-------------------------------\n\n");
    printf("ID       MARCA       NOMBRE    ID COLOR        ID TIPO       RODADO\n\n");
    for(int i=0;i<len_bicis;i++)
    {
        if(Bicis[i].isEmpty==TRUE)
        {
            mostrar_Bicicleta(Bicis[i],clientes);
        }
        else
        {
            printf("********************no hay bicicleta************************\n\n");
        }
    }
}
void mostrar_BicicletaS_XColores(eBicicleta Bicis[],int id_color,int len_bicis,eCliente clientes[])
{
    printf("---------------------------- BICICLETAS---------------------------\n\n");
    printf("ID       MARCA       NOMBRE    ID COLOR        ID TIPO       RODADO\n\n");
    for(int i=0;i<len_bicis;i++)
    {
        if(Bicis[i].isEmpty==TRUE)
        {
            if(Bicis[i].ColorBici==id_color)
            {
              mostrar_Bicicleta(Bicis[i],clientes);
            }

        }
        else
        {
            printf("**************************************************************\n\n");
        }
    }

}
void mostrar_BicicletaS_XTipo(eBicicleta Bicis[],int id_tipo,int len_bicis,eCliente clientes[])
{
    printf("---------------------------- BICICLETAS---------------------------\n\n");
    printf("ID       MARCA       NOMBRE    ID COLOR        ID TIPO       RODADO\n\n");
    for(int i=0;i<len_bicis;i++)
    {
        if(Bicis[i].isEmpty==TRUE)
        {
            if(Bicis[i].TipoBici==id_tipo)
            {
              mostrar_Bicicleta(Bicis[i],clientes);
            }

        }
        else
        {
            printf("**************************************************************\n\n");
        }
    }

}
void Informar_menorRodado(eBicicleta Bicis[],int len_bicis,eCliente clientes[])
{
    printf("---------------------------- BICICLETAS---------------------------\n\n");
    printf("ID       MARCA       NOMBRE    ID COLOR        ID TIPO       RODADO\n\n");
    for(int i=0;i<len_bicis;i++)
    {
        if(Bicis[i].isEmpty==TRUE)
        {
            if(Bicis[i].rodados==20)
            {
              mostrar_Bicicleta(Bicis[i],clientes);
            }

        }
        else
        {
            printf("**************************************************************\n\n");
        }
    }
}
void Informar_SeparadoTipo(eBicicleta Bicis[],eTipo tipos[],int len_bicis,eCliente clientes[])
{
    printf("---------------------------- BICICLETAS---------------------------\n\n");
    printf("ID       MARCA       NOMBRE    ID COLOR        ID TIPO       RODADO\n\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<len_bicis;j++)
        {
            if(Bicis[j].isEmpty==TRUE)
            {
                if(tipos[i].idTipo==Bicis[j].TipoBici)
                {
                    mostrar_Bicicleta(Bicis[j],clientes);
                }
            }
        }
    }
}
int Contar_color_tipo(eBicicleta Bicis[],int len_bicis,int id_color,int id_tipo)
{
    int contador=0;
    for(int i=0;i<len_bicis;i++)
    {
        if(Bicis[i].isEmpty==TRUE&&Bicis[i].ColorBici==id_color&&Bicis[i].TipoBici==id_tipo)
        {
                contador++;
        }
    }
    return contador;
}
void mostrar_Bicicleta(eBicicleta Bicis,eCliente clientes[])
{
    printf("%d   %10s  ",Bicis.idBici,Bicis.marca);
    buscar_cliente(clientes,Bicis.idCliente);
    printf("%8d      %8d       %8.2f     \n",Bicis.ColorBici,Bicis.TipoBici,Bicis.rodados);

}
int Validacion_idBici(eBicicleta Bicis[],int idbici)
{
    int valido=FALSE;
    for(int i=0;i<5;i++)
    {
        if(Bicis[i].idBici==idbici)
        {
           valido=TRUE;
           break;
        }
    }
    return valido;
}
int menu()
{
    int opcion;

    printf("------------MENU DE OPCIONES-----------\n\n");
    printf("1.Alta bicicleta.\n");
    printf("2.Modificar bicibleta.\n");
    printf("3.Baja bicicleta.\n");
    printf("4.Listar bicicletas.\n");
    printf("5.Listar tipos.\n");
    printf("6.Listar colores.\n");
    printf("7.Listar servicios.\n");
    printf("8.Alta trabajo.\n");
    printf("9.Listar trabajos.\n");
    printf("10.Salir\n\n");
    printf("ingrese opcion:\n");
    scanf("%d",&opcion);
    return opcion;
}
int menu_listar()
{
    int opcion;
    printf("---MENU DE LISTADO---------------------\n");
    printf("1-mostrar todo el listado.\n");
    printf("2-mostrar listado por color especifico.\n");
    printf("3-mostrar listado por tipo especifico.\n");
    printf("4-Informar las bicicletas con menor rodado.\n");
    printf("5-mostrar listado separados por tipos.\n");
    printf("6-Informar cuando bicicletas hay por tipo y color.\n");
    printf("eliga una opcion:\n");
    scanf("%d",&opcion);
    return opcion;
}
