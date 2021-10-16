/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "menu.h"
#include "inform.h"

#define LEN 1000

int main(void) {

	setbuf(stdout, NULL);

    eEmployee employee[LEN];
    if(initEmployees(employee, LEN)==-1)
    {
       printf("ERROR\n");
    }
    int idE = 1;
    char salir = 'n';
    do
    {
        switch(menu())
        {
        case 1:
            if(addEmployees(employee, LEN, &idE)== 0)
            {
                printf("\nHigh Successful\n");
            }
            else
            {
                printf("\nThere is no space\n");
            }
            break;
        case 2:
            if(ModifyEmployee(employee, LEN)==-1)
            {
                printf("\nERROR\n");
            }
            break;
        case 3:
            if(removeEmployee(employee, LEN)== 0)
            {
                printf("\nget off successfully\n");
            }
            else
            {
                printf("ERROR\n");
            }
            break;
        case 4:
            reports(employee, LEN);
            break;
        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c",&salir);
            break;
            default:
            printf("Opcion invalida \n");
        }
        system("pause");
    }while(salir == 'n');
	return EXIT_SUCCESS;
}
