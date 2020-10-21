#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#define TAMB 10
#define TAMT 20


int main()
{
    eTipo TiposBicis[4];
    eColor ColoresBicis[5];
    eServicios ServiciosBicis[4];
    eCliente ClientesBicis[5];

    eTrabajo TrabajosBicis[TAMT];
    int seguir=1;
    int idBicis=100;
    int idTrabajos=0;
    int auxid;
    int auxid_2;
    int auxcontador;
    int flag=0;
    int flag_2=0;
    eBicicleta Bicis[TAMB] = {
        {100,"toyota",2000,1001,5000,26,1},
        {101,"toyota",2001,1002,5001,27.5,1},
        {102,"Rider",2000,1001,5001,24,1},
        {103,"Rider",2002,1003,5002,20,1},
        {104,"Yamaha",2003,1000,5000,26,1},
        {105,"Yamaha",2001,1001,5001,24,1},
        {106,"Rider",2002,1002,5003,26,1},
    };

   // iniciar_Bicis(Bicis,TAMB);
    hardcoreo_Color(ColoresBicis);
    hardcoreo_Tipo(TiposBicis);
    hardcoreo_Servicio(ServiciosBicis);
    harcodeo_cliente(ClientesBicis);
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            //alta bici
            system("cls");
            if(alta_bicicleta(Bicis,TiposBicis,ColoresBicis,ClientesBicis,TAMB,idBicis)==FALSE)
            {
                system("cls");
                printf("alta existosa!!\n\n\n");
                mostrar_BicicletaS(Bicis,TAMB,ClientesBicis);
                idBicis++;
                system("pause");
                flag=1;
            }
            else
            {
               printf("error en el alta!\n\n\n");
            }
            break;
        case 2:
            //modifica bici
            system("cls");
            if(flag==1)
            {
                mostrar_BicicletaS(Bicis,TAMB,ClientesBicis);
                printf("Ingrese ID de la bici a modificar.\n");
                scanf("%d",&auxid);
                auxid=encontrar_Bici(Bicis,TAMB,auxid);
                if(modificar_bicicleta(Bicis,TiposBicis,TAMB,auxid)==FALSE)
                {
                    printf("modificacion exitosa!\n\n\n");
                }
                else
                {
                    printf("no hay ninguna bicicleta en ese ID.\n\n\n");
                }
            }
            else
            {
                printf("primero se necesita dar de alta una bicicleta.\n\n\n");
            }
            system("pause");
            break;
        case 3:
            //baja bici
            system("cls");
            if(flag==1)
            {
                mostrar_BicicletaS(Bicis,TAMB,ClientesBicis);
                printf("ingrese id de la bicicleta a dar de baja.\n");
                scanf("%d",&auxid);
                auxid=encontrar_Bici(Bicis,TAMB,auxid);
                if(baja_bicicleta(Bicis,auxid)==TRUE)
                {
                    printf("se a dado de baja exitosamente.\n\n\n");
                    system("pause");
                    break;
                }
            }
            else
            {
                printf("primero se necesita dar de alta una bicicleta.\n");
                system("pause");
            }
            break;
        case 4:
            //listar bici
            system("cls");
            switch(menu_listar())
            {
                case 1:
                    listar_bicicletas(Bicis,TAMB);
                    mostrar_BicicletaS(Bicis,TAMB,ClientesBicis);
                    break;
                case 2:
                    mostrar_Colores(ColoresBicis);
                    printf("ingrese el ID del color.\n");
                    scanf("%d",&auxid);
                    mostrar_BicicletaS_XColores(Bicis,auxid,TAMB,ClientesBicis);
                    break;
                case 3:
                    mostrar_TipoS(TiposBicis);
                    printf("ingrese el ID del tipo.\n");
                    scanf("%d",&auxid);
                    mostrar_BicicletaS_XTipo(Bicis,auxid,TAMB,ClientesBicis);
                    break;
                case 4:
                    Informar_menorRodado(Bicis,TAMB,ClientesBicis);
                    break;
                case 5:
                    Informar_SeparadoTipo(Bicis,TiposBicis,TAMB,ClientesBicis);
                    break;
                case 6:
                    mostrar_Colores(ColoresBicis);
                    printf("Ingrese ID del color al buscar:\n");
                    scanf("%d",&auxid);
                    mostrar_TipoS(TiposBicis);
                    printf("Ingrese el ID del tipo al buscar:\n");
                    scanf("%d",&auxid_2);
                    auxcontador=Contar_color_tipo(Bicis,TAMB,auxid,auxid_2);
                    printf("La cantidad de bicicletas de ese color y ese tipo es:  %d\n\n",auxcontador);
                    break;
                default:
                    printf("opcion incorrecta!\n");
                    break;
            }

            system("pause");
            break;
        case 5:
            //listar tipo
            system("cls");
            mostrar_TipoS(TiposBicis);
            system("pause");
            break;
        case 6:
            //listar colores
            system("cls");
            mostrar_Colores(ColoresBicis);
            system("pause");
            break;
        case 7:
            //listar servicios
            system("cls");
            mostrar_ServicioS(ServiciosBicis);
            system("pause");
            break;
        case 8:
            //alta trabajo
            system("cls");
            alta_trabajo(TrabajosBicis,Bicis,ServiciosBicis,ClientesBicis,TAMT,idTrabajos,TAMB);
            mostrar_trabajoS(TrabajosBicis,TAMT);
            system("pause");
            flag_2=1;

            break;
        case 9:
            //listar trabajo
            if(flag_2==1)
            {
                system("cls");
            mostrar_trabajoS(TrabajosBicis,TAMT);
            system("pause");
            }
            else
            {
                printf("primero tenes que ingresar un trabajo.\n");
            }

           break;
        case 10:
            //salir
            printf("Seguro que quiere salir.?\n 1-'no'\n 2='si'\n");
            scanf("%d",&seguir);

            break;
        default:
            printf("opcion incorrecta!\n");

            break;
        }
    }while(seguir==1);

    return 0;
}
