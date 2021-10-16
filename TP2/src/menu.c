#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
int menu()
{
    int opcion;

    system("cls");

    printf("\n\n-------------***Welcome to the menu***-------------\n\n\n");
    printf("1.HIGH\n");
    printf("2.MODIFY\n");
    printf("3.Come down\n");
    printf("4.Report\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuModify()
{
    int opcion;

    system("cls");
    printf("\n\n-------------***Menu Modify Employee***-------------\n\n\n");
    printf("1. Modify Name\n");
    printf("2. Modify lastName\n");
    printf("3. Modify sector\n");
    printf("4. Modify salary\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuReports()
{
    int opcion;

    printf("\n\n-------------***Menu Reports***-------------\n\n\n");
    printf("1.List of employees sorted alphabetically by Surname and Sector.\n");
    printf("2.Total and average salaries, and how many employees exceed the average salary.\n");
    printf("Choose an option: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
