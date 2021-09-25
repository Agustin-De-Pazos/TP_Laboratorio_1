#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int menu()
{
    int opcion;

    printf("\n   *** Menu Calculadora *** \n\n");
    printf("1.Ingresar 1er operando (A=x)\n");
    printf("2.Ingresar 2do operando (B=y)\n");
    printf("3 Realizar todos los Calculos \n");
    printf("  a. Calcular Suma (A+B)\n");
    printf("  b. Calcular resta (A-B)\n");
    printf("  c. Calcular division (A/B)\n");
    printf("  d. Calcular la multiplicacion (A*B)\n");
    printf("  e. Calcular factoreal (A!)\n");
    printf("4 Informar resultados\n");
    printf("5.Salir\n");
    printf("\n ingrese opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;

}

int getNum(char mensaje[])
{
    int numero;

    printf("%s", mensaje);
    while(!scanf("%d", &numero))
    {
        fflush(stdin);
        printf("Error reingrese numero: ");
    }
	return numero;
}
