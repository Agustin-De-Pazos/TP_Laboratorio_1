#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    setbuf(stdout, NULL);
    int options = 0;
    char path[50];
    int flag = 0;
    int nextId = 1000;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No se pudo crear el linkedlist\n");
        exit(1);
    }
    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText(path , listaEmpleados))
                {
                    printf("Datos cargados con exito");
                    flag = 1;
                }
                system("pause");
                break;
            case 2:
                controller_loadFromBinary(path,listaEmpleados);
                system("pause");
                break;
            case 3:
                printf("%d", nextId);
                if(flag == 1)
                {
                   controller_addEmployee(listaEmpleados, &nextId);
                   printf("alta empleado\n");
                   system("pause");
                }
                break;
            case 4:
            	if(flag == 1)
            	{
                	if(!controller_editEmployee(listaEmpleados))
                    {
                        printf("Modificar cancelado");
                    }
                    system("pause");
            	}
                break;
            case 5:
            	if(flag == 1)
            	{
                	if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Baja exitosa");
                    }
                    system("pause");
            	}
                break;
            case 6:
            	if(flag == 1)
            	{
                	if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("\n");
                    }
                    system("pause");
            	}
                break;
            case 7:
            	if(flag == 1)
            	{
                	controller_sortEmployee(listaEmpleados);
                    system("pause");
            	}
                break;
            case 8:
            	if(flag == 1)
            	{
                	if(controller_saveAsText(path, listaEmpleados))
                    {
                        printf("\n Guardado con exito\n");
                    }
            	}
                system("pause");
                break;
            case 9:
            	if(flag == 1)
            	{
                	if(controller_saveAsBinary(path,listaEmpleados))
                    {
                        printf("\nGuardado Completado\n");
                    }
                    system("pause");
            	}

                break;
            case 10:
                printf("Confirma salida 10 para salir si desea continuar presione otra tecla ?: ");
                fflush(stdin);
                scanf("%d", &options);
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");

        }
    }while(options != 10);
    return 0;
}
