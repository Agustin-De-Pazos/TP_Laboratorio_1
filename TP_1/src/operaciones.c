#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int suma(int x, int y)
{
    return x+y;
}

int resta(int x, int y)
{
    return x-y;
}

float division(int x, int y)
{
    float valiDiv = 0;//Si no entra al if retorna 0
    if(y != 0)
    {
      valiDiv = (float) x/y;//Si entra al if retorna validDiv > 0
    }
    return (float) valiDiv;
}

float multiplicacion(int x, int y)
{
    return (float) y*x;
}

int factorial(int n)
{
    int fact = 1;

    if(n < 17)//si es mayor a 16 tira basura. Validacion
    {
        for(int i = 1; i <= n; i++)
        {
            fact *= i;
        }
    }
    else
    {
        fact--;//al no entrar al if fact va a retornar 0
    }
    return fact;
}
void sumaPrint(int c)
{
    printf("a. el resultado de A+B es: %d \n", c);
}

void restaPrint(int c)
{
    printf("b. el resultado de A-B es: %d \n", c);
}

void divPrint(float c)
{
    if(c == 0)
    {
        printf("c. No se puede divir por 0\n");
    }
    else
    {
        printf("c. el resultado de A/B es: %.3f \n", c);
    }
}

void multiplicacionPrint(float c)
{
    printf("d. el resultado de A*B es: %.1f \n", c);
}

void factPrintUno(int c)
{
    if(c == 0)
    {
        printf("e. Error el factorial de A! es muy grande\n");
    }
    else
    {
        printf("e. el resultado de A! es: %d \n", c);
    }

}

void factPrintDos(int c)
{
    if(c == 0)//Validacion
    {
        printf("e. Error el factorial de B! es muy grande\n");
    }
    else
    {
        printf("e. el resultado de B! es: %d \n", c);
    }
}
