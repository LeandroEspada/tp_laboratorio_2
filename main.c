#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"funciones.h"

int main()
{
    inicializarvectores(vectordepersonas,vectordepersonasauxiliar);
    int opcion;
    do
    {
        opcion=menu();
        switch (opcion)
        {
            case 1:
            {
                cargarpersona(vectordepersonas);
                fflush(stdin);
                break;
            }
            case 2:
            {
                eliminarpersona(vectordepersonas);
                fflush(stdin);
                break;
            }
            case 3:
            {
                imprimirlistaordenada(vectordepersonas,vectordepersonasauxiliar);
                fflush(stdin);
                break;
            }
            case 4:
            {
                imprimirgrafico(vectordepersonas);
                fflush(stdin);
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                system("cls");
                printf("Ingreso un valor no valido\n");
                system("pause");
                break;
            }
        }
    }while(opcion!=5);
}
