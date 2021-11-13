
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee  = (Employee*) malloc(sizeof(Employee));
    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre," ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee = employee_new();
    if(newEmployee != NULL)
    {
        if(!(employee_setId(newEmployee, atoi(idStr)) &&
           employee_setNombre(newEmployee, nombreStr) &&
           employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) &&
           employee_setSueldo(newEmployee, atoi(sueldoStr))))
           {
               free(newEmployee);
               newEmployee = NULL;
           }
    }
    return newEmployee;
}

void employee_delete(Employee* p)
{
    free(p);
}

int employee_setId(Employee* this, int id)
{
    int isOkey = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        isOkey = 1;
    }
    return isOkey;
}

int employee_getId(Employee* this,int* id)
{
    int isOkey = 0;
    if(this != NULL && id != NULL)
    {
        (*id) = this->id;
        isOkey = 1;
    }
    return isOkey;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int isOkey = 0;
    if(this != NULL && nombre != NULL && strlen(nombre)<128 && strlen(nombre) > 4)
    {
        strcpy(this->nombre, nombre);
        isOkey = 1;
    }
    return isOkey;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int isOkey = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        isOkey = 1;
    }
    return isOkey;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int isOkey = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        isOkey = 1;
    }
    return isOkey;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int isOkey = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        (*horasTrabajadas) = this->horasTrabajadas;
        isOkey = 1;
    }
    return isOkey;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int isOkey = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        isOkey = 1;
    }
    return isOkey;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int isOkey = 0;

    if(this != NULL && sueldo != NULL)
    {
        (*sueldo) = this->sueldo;
        isOkey = 1;
    }
    return isOkey;
}

int mostrarEmpleado(Employee* e)
{
    int isOkey = 0;
    int sueldo = 0;
    int horasTrabajadas = 0;
    char nombre[128];
    int id;

    if(employee_getNombre(e,nombre) && employee_getHorasTrabajadas(e, &horasTrabajadas) && employee_getId(e,&id) && employee_getSueldo(e, &sueldo))
    {
        printf("%d %10s       %5d          %5d", id, nombre, horasTrabajadas, sueldo);
        isOkey = 1;
    }
    return isOkey;
}

int employee_SortSueldo(void* item1, void* item2)
{

    int ret = -1;
    Employee* e1;
    Employee* e2;
    int sueldo1;
    int sueldo2;
    e1 = (Employee*) item1;
    e2 = (Employee*) item2;

    if(employee_getSueldo(e1, &sueldo1) &&
    employee_getSueldo(e2, &sueldo2))
    {
        if(sueldo1 > sueldo2)
        {
            ret = 1;
        }
        else
        {
            if(sueldo1 > sueldo2)
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int employee_SortHoras(void* item1, void* item2)
{

    int ret = -1;
    Employee* e1;
    Employee* e2;
    int horas1;
    int horas2;
    e1 = (Employee*) item1;
    e2 = (Employee*) item2;

    if(employee_getHorasTrabajadas(e1, &horas1) &&
    employee_getHorasTrabajadas(e2, &horas2))
    {
        if(horas1 > horas2)
        {
            ret = 1;
        }
        else
        {
            if(horas1 > horas2)
            {
                ret = 0;
            }
        }
    }

    return ret;
}

int employee_SortId(void* item1, void* item2)
{

    int ret = -1;
    Employee* e1;
    Employee* e2;
    int id1;
    int id2;
    e1 = (Employee*) item1;
    e2 = (Employee*) item2;

    if(employee_getHorasTrabajadas(e1, &id1) &&
    employee_getHorasTrabajadas(e2, &id2))
    {
        if(id1 > id2)
        {
            ret = 1;
        }
        else
        {
            if(id1 > id2)
            {
                ret = 0;
            }
        }
    }
    return ret;
}

