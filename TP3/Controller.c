#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        printf("ingrese path (data.csv): ");
        fflush(stdin);
        gets(path);
        f = fopen(path, "r");

        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                todoOk = 1;
            }
        }
    }
    printf("%d", ll_len(pArrayListEmployee));

    return todoOk;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path ,LinkedList* pArrayListEmployee)
{
    int isOkey = 0;
    FILE* f = NULL;
    char confirma;

    printf("ingrese Path: ");
    fflush(stdin);
    gets(path);
    f = fopen(path, "rb");

    if(f==NULL && path != NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            printf("Cuidado se van a sobreescribir los empleados");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                ll_clear(pArrayListEmployee);
                if(parser_EmployeeFromBinary(f, pArrayListEmployee))
                {
                    isOkey = 1;
                }
            }
        }
    }
    fclose(f);
    return isOkey;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
	int id;
	int isOkey=0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmp = NULL;
    id = *pId;
    if(pArrayListEmployee != NULL)
    {
        printf("ALTA EMPLEADO \n\n");
        auxEmp = employee_new();
        printf("Ingrese Nombre del Empleado: ");
        fflush(stdin);
        gets(nombre);
        while(!employee_setNombre(auxEmp, nombre))
        {
            printf("\nNombre invalido. Reingrese nombre: ");
            fflush(stdin);
            gets(nombre);
        }
        printf("Ingrese horas trabajadas: ");
        scanf("%d", &horasTrabajadas);
        while(!employee_setHorasTrabajadas(auxEmp, horasTrabajadas))
        {
            printf("\nNombre invalido. Reingrese horas trabajadas: ");
            fflush(stdin);
            scanf("%d", &horasTrabajadas);
        }
        printf("Ingrese sueldo: ");
        scanf("%d", &sueldo);
        while(!employee_setSueldo(auxEmp, sueldo))
        {
            printf("\nNombre invalido. Reingrese horas trabajadas: ");
            fflush(stdin);
            scanf("%d", &sueldo);
        }
        id++;
        employee_setId(auxEmp, id);
        ll_add(pArrayListEmployee, auxEmp);
        isOkey=1;
    }
    return isOkey;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = NULL;
    int isOkey =1;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int id;
    char confirma;

    printf(" *******       MODIFICAR EMPLEADO      *******\n");
    printf("Ingrese id del empleado a modificar:\n ");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d", &id);
    for(int i =0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
        if(auxEmp->id ==id)
        {
            printf("\n");
            mostrarEmpleado(auxEmp);
            printf("\nEste el empleado que quiere modificar: s/n\n");
            fflush(stdin);
            confirma = getchar();
            break;
        }
    }
    if(confirma == 's')
    {
        switch(menuModificar())
        {
        case 1:
            printf("Ingrese el nuevo nombre");
            fflush(stdin);
            gets(nombre);
            if(employee_setNombre(auxEmp, nombre))
            {
                printf("Nombre cargado con exito\n");
                isOkey = 0;
                system("pause");
            }
            break;
        case 2:
            printf("Ingrese cantidad de horas trabajadas");
            scanf("%d",&horasTrabajadas);
            if(employee_setHorasTrabajadas(auxEmp,horasTrabajadas))
            {
                printf("Horas guardadas\n");
                isOkey = 0;
                system("pause");
            }
            break;
        case 3:
            printf("Ingrese su nuevo sueldo");
            scanf("%d",&sueldo);
            if(employee_setSueldo(auxEmp,sueldo))
            {
                printf("Sueldo modificado");
                isOkey = 0;
                system("pause");
            }
            break;
        case 4:
            printf("Desea salir");
            break;
        default: printf("Opcion invalida");
                 system("pause");
            break;

        }
    }
    return isOkey;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = NULL;
    int id;
    int isOkey = 0;
    int empleado;
    char confirma;

    if(pArrayListEmployee != NULL)
    {

        printf("******BAJA EMPLEADO******\n\n");
        printf("Ingrese ID:\n ");
        controller_ListEmployee(pArrayListEmployee);
        scanf("%d", &id);
        for(int i =0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
            if(auxEmp->id ==id)
            {
                printf("\n");
                mostrarEmpleado(auxEmp);
                printf("\nEste el empleado que quiere eliminar: s/n\n");
                fflush(stdin);
                empleado = i;
                confirma = getchar();
                break;
            }
        }
        if(confirma == 's')
        {
            ll_remove(pArrayListEmployee,empleado);
            isOkey = 1;
        }
    }
    return isOkey;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = NULL;
    int isOkey = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("Id   Nombre    Horas Trabajadas   Sueldo\n");
        for(int i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            if(mostrarEmpleado(auxEmp))
            {
                printf("\n");
                isOkey = 1;
            }
        }
        if(isOkey == 0)
        {
            printf("No hay empleados cargados");
        }
        printf("\n\n");

    }
    return isOkey;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int criterio;
    int isOkey = 0;

    switch(menuSort())
    {
    case 1:
        printf("Ordenar de forma decendente 0 o ascente 1. Elija opcion\n");
        scanf("%d", &criterio);
        ll_sort(pArrayListEmployee, employee_SortId, criterio);
        break;
    case 2:
        printf("Ordenar de forma decendente 0 o ascente 1. Elija opcion\n");
        scanf("%d", &criterio);
        ll_sort(pArrayListEmployee, employee_SortHoras, criterio);
        break;
    case 3:
        printf("Ordenar de forma decendente 0 o ascente 1. Elija opcion\n");
        scanf("%d", &criterio);
        ll_sort(pArrayListEmployee, employee_SortSueldo, criterio);
        break;
    case 4:
        printf("Ordenamiento cancelado por el usuario\n");
        break;
    default:
        printf("Opcion incorrecta");
        system("pause");
        break;
    isOkey = 1;

    }
    return isOkey;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    FILE* f;
    Employee* aux = NULL;

    if(pArrayListEmployee!= NULL && path != NULL )
    {
        printf("Ingrese path (data.csv) ");
        fflush(stdin);
        gets(path);
        f = fopen(path,"w");
        if(f == NULL)
        {
            printf("No se logro crear un archivo");
        }
        else
        {
            fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                if(employee_getId(aux, &id)
                    && employee_getNombre(aux, nombre)
                    && employee_getHorasTrabajadas(aux, &horasTrabajadas)
                    && employee_getSueldo(aux, &sueldo))
                {
                    cant = fprintf(f,"%d,%s,%d,%d\n",id ,nombre,horasTrabajadas,sueldo);
                }

                if(cant < 1)
                {
                    break;
                }
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    int isOkey = 0;
    char confirma = 's';
    Employee* auxEmp = NULL;
    FILE* f = NULL;
    fflush(stdin);
    printf("ingrese Path: ");
    gets(path);
    f = fopen(path, "rb");

    if(f != NULL)
    {
        printf("Cuidado el archivo existe y se va a sobrescribir\n");
        fflush(stdin);
        scanf("%c", &confirma);
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path, "wb");
        if(f == NULL)
        {
            printf(" No se pudo abrir el archivo");
        }
        else
        {
            for(int i = 0; i< ll_len(pArrayListEmployee); i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                fwrite(auxEmp, sizeof(Employee), 1,f);
                isOkey = 1;
            }
        }
        fclose(f);
    }
    return isOkey;
}
