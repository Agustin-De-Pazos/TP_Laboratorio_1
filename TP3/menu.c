#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
int menu()
{
    int option;

    system("cls");

    printf("\n   *** MENU  *** \n\n");
    printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2.Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3.Alta empleado \n");
    printf("4.Modificar datos de empleado\n");
    printf("5.Baja de empleado\n");
    printf("6.Listar empleados\n");
    printf("7.Ordenar empleados\n");
    printf("8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9.Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10.Salir\n");
    printf("\n ingrese opcion: ");
    scanf("%d", &option);
    fflush(stdin);
    return option;

}

int menuSort()
{
    int opcion;

    printf("*****  Menu Ordenar Empleados  *****\n");
    printf("1. Ordenar por id\n");
    printf("2. Ordenar por horas trabajadas\n");
    printf("3. Ordenar por Sueldo\n");
    printf("4. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("**MENU MODIFICAR***\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Horas Trabajadas\n");
    printf("3. Modificar Sueldo\n");
    printf("4. Desea salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
