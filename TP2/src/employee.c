#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "employee.h"
#include "menu.h"
#include "inform.h"
#include "validation.h"

int initEmployees(eEmployee list[],int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len; i++)
        {
            list[i].isEmpty = FREE;
            todoOk = 0;
        }
    }
    return todoOk;
}

int addEmployees(eEmployee list[], int len, int* pId)
{
    int isOkey =-1;
    eEmployee aux;

    system("cls");
    if(list != NULL && len > 0)
    {
        printf("\n\n-------------***High employee***-------------\n\n\n");
        isOkey = 0;
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == FREE)
            {
                validacionL(aux.name, "Enter name: ", 51);
                validacionL(aux.lastName, "Enter lastName: ", 51);
                utn_getFloat(&aux.salary, "Enter salary: ", "\nERROR  ", 100, 999999999, 10);
                utn_getNumero(&aux.sector, "Enter sector: ", "\nERROR  ", 1, 100, 10);
                aux.id = *pId;
                aux.isEmpty = FULL;
                list[i] = aux;
                (*pId)++;
                isOkey = 0;
                break;
            }
        }
    }
    return isOkey;
}
int ModifyEmployee(eEmployee list[], int len)
{
    eEmployee aux;
    int index;
    int isOkey = -1;
    char confirm;
    int id;
    char exit = 's';

    if(list != NULL && len >0)
    {
        isOkey = 0;
        printf("\n\n-------------***Modify Employee***-------------\n\n\n");
        printEmployees(list, len);
        printf("Ingrese id: ");
        scanf("%d", &id);
        index = findEmployeeById(list,len, id);

        if(index == -1)
        {
            printf("\nThere is no client registered with the id");
        }
        else
        {
            printEmployee(list[index]);
            printf("\nThis is the client you want to modify s/n?: ");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm == 's')
            {
                do
                {
                    switch(menuModify())// menu modificar
                    {
                    case 1:
                        validacionL(aux.name, "Change name: ",40);
                        strcpy(list[index].name,aux.name);
                        printf("Name changed successfully\n\n");
                        system("pause");
                        break;
                    case 2:
                        validacionL(aux.lastName, "Change name: " ,40);
                        strcpy(list[index].lastName,aux.lastName);//id Nuevo
                        printf("LastName changed successfully\n\n");
                        system("pause");
                        break;
                    case 3:
                        utn_getNumero(&aux.sector, "Change Sector: ", "\nERROR",1,100,10);
                        list[index].sector = aux.sector;
                        printf("Sector changed successfully\n\n");
                        system("pause");
                        break;
                    case 4:
                        utn_getFloat(&aux.salary, "Change salary: ", "\nERROR",100,999999999,10);
                        list[index].salary = aux.salary;
                        printf("Salary changed successfully\n\n");
                        system("pause");
                        break;
                    case 5:
                        exit = 's';
                        break;
                    }
                }while(exit=='n');
            }
            else
            {
                printf("Modify canceled employee\n");
            }
        }
    }
    return isOkey;
}



int findEmployeeById(eEmployee list[], int len,int id)
{
    int index = -1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i< len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == FULL)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int removeEmployee(eEmployee list[],int len)
{
    char confirm = 'n';
    int isOkey =-1;
    int id;
    int index;
    system("cls");
    printf("\n\n-------------***Low employee***-------------\n\n\n");
    if(list != NULL && len > 0)
    {
        printEmployees(list, len);
        printf("\nIngrese id: ");
        scanf("%d", &id);
        index = findEmployeeById(list,len, id);

        if(index == -1)
        {
            printf("\nThere is no client registered with the entered id\n");
        }
        else
        {
            printEmployee(list[index]);
            printf("\nConfirm unsubscribe s/n?: ");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm == 's')
            {
                list[index].isEmpty = FREE;
                isOkey = 0;
            }
            else
            {
                printf("Unsubscribe canceled by the user\n");
            }
        }
    }
    return isOkey;
}
