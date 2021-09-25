/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "operaciones.h"

int main(void) {

	setbuf(stdout, NULL);
	// NO FUNCIONA EL SYSTEM("CLS")
    int operandoUno = 0;
    int segundoOperando = 0;
    char salir;
    int sumar;
    float rest;
    float div;
    float multi;
    float factUno;
    float factDos;
    int flag1 = 0;
    int flag2 = 0;

    salir = 'n';
    do
    {
        system("cls");
    	printf("Primer operando (A=%d)\n",operandoUno);
        printf("Segundo operando  (B=%d)\n", segundoOperando);
        switch(menu())
        {
            case 1:
                operandoUno = getNum("Ingrese operando  (A=X) ");
                flag1 = 1;
                break;
            case 2:
                if(flag1==1)
                {
                    segundoOperando = getNum("Ingrese segundo operando (B=Y) ");
                    flag2 = 1;
                }
                else
                {
                    printf("primero debe ingresar en la opcion 1");
                    system("pause");
                }
                break;
            case 3:
                if(flag1 == 1 && flag2 == 1)
                {

                    sumar = suma(operandoUno,segundoOperando);//guardo el valor del retorno en sumar
                    rest = resta(operandoUno,segundoOperando);
                    div = division(operandoUno, segundoOperando);//Guardo el valor de la division si el divisor es 0 no realiza la division y retorna 0
                    multi = multiplicacion(operandoUno,segundoOperando);
                    factUno = factorial(operandoUno);//Si el factorial es mayor a 14 No realiza el factoreal y retorna 0
                    factDos = factorial(segundoOperando);//Si el factorial es mayor a 14 No realiza el factoreal y retorna 0
                    printf("Calculos Realizados \n");
                    system("pause");
                    flag1=2;
                    flag2=2;
                }
                else
                {
                    printf("Tiene que utlizar la opcion 1 y 2 antes \n");
                    system("pause");
                }
                break;
            case 4:
                if(flag1 == 2 && flag2 == 2)
                {
                    sumaPrint(sumar);
                    restaPrint(rest);
                    divPrint(div);
                    multiplicacionPrint(multi);
                    factPrintUno(factUno);
                    factPrintDos(factDos);
                    flag1 = 0;//reseteo los flags
                    flag2 = 0;
                    operandoUno = 0;//reseteo operandos
                    segundoOperando = 0;
                    system("pause");
                }
                else
                {
                    printf("Debe ingresar las anteriores opciones \n");
                    system("pause");
                }
                break;
            case 5:
                salir = 's';
                break;
        }
    }while(salir == 'n');


	return EXIT_SUCCESS;
}
