#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inform.h"
#include "employee.h"
#include "menu.h"

void reports(eEmployee* list, int len)
{
    switch(menuReports())
    {
    case 1:
        if(printEmployees(list, len)==-1)
        {
            printf("ERROR\n");
        }
        break;
    case 2:
        if(totalAverageSalary(list, len)==-1)
        {
            printf("ERROR\n");
        }
        break;
    }
}
int printEmployees(eEmployee list[],int len)
{
    int order;
    int isOkey = -1;
    if(list != NULL && len > 0)
    {
        isOkey = 0;
        printf("\nchoose the sort order ascending 1 descending 0 for name: ");
        scanf("%d", &order);
        sortEmployees(list, len, order);
        printf("\n\n-------------***List Employee***-------------\n\n");
        printf("------------------------------------------------------------\n");
        printf("\nId     Name      Last Name      Salary       Sector     \n\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == FULL)
            {
                printEmployee(list[i]);
            }
        }
        printf("\n------------------------------------------------------------\n");
    }
    return isOkey;
}
void printEmployee(eEmployee oneEmployee)
{
    printf("%d     %s     %s      %.2f        %d\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}

int totalAverageSalary(eEmployee* list, int len)
{
    int isOkey=-1;
    int contador= 0;
    int contador2 = 0;
    int acumulador = 0;
    int promedioTotal;
    if(list != NULL && len >0)
    {
        isOkey = 0;
        for(int i =0; i<len; i++)
        {
            if(list[i].isEmpty == FULL)
            {
                contador++;
                acumulador = acumulador + list[i].salary;
            }
        }
        promedioTotal = (float) (acumulador / contador);
        for(int i = 0; i<len; i++)
        {
            if(list[i].isEmpty == FULL && list[i].salary > promedioTotal)
            {
                contador2++;
            }
        }
        printf("the number of employees is: %d\n", contador);
        printf("the average salary of all employees is %f\n", (float) promedioTotal);
        printf("the number of employees who exceed the average salary are %d\n", contador2);
    }
    return isOkey;
}

int sortEmployees(eEmployee list[], int len, int order)
{
    int isOkey = -1;
    eEmployee aux;
    if(list != NULL && len > 0)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i+1; j < len; j++)
            {

                if((order == 1 && list[i].sector < list[j].sector) || (order == 0 && list[i].sector > list[j].sector))
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j]= aux;
                }
                else if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j]= aux;
                }
            }
        }
    }
    return isOkey;
}
