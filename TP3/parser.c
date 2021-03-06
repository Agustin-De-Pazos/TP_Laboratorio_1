#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
//
// brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
//
//param path char*
//param pArrayListEmployee LinkedList*
//return int*
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    char buffer[4][50];
    Employee* auxEmp = NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);
    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3]);
        if(cant == 4)
        {
            auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(auxEmp != NULL)
            {
                ll_add(pArrayListEmployee,auxEmp);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

// \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
//
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int isOkey = 0;
    Employee* auxEmp = NULL;
    int cant;
    while(!feof(pFile))
    {
        auxEmp = employee_new();
        if(auxEmp != NULL)
        {
            cant = fread(auxEmp, sizeof(Employee),1,pFile);
            if(cant < 1)
        {
            break;
        }
        ll_add(pArrayListEmployee, auxEmp);
        isOkey = 1;
    }
}
    return isOkey;
}

