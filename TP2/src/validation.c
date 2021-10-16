#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"

int validacionL(char cadena[], char mensaje[],int tam)
{
    int i = 0;
    int todoOk;
    char buffer[400];
    int contador = 0;
    if(cadena != NULL)
    {
        do
        {
            i=0;
            printf("%s",mensaje);
            fflush(stdin);
            gets(buffer);
            while(buffer[i] != '\0')
            {
                if((buffer[i] != ' ' && (buffer[i] < 'A' || buffer[i] > 'Z'))
                &&(buffer[i] < 'a' || buffer[i] > 'z'))
                {
                    todoOk = 1;
                    break;
                }
                todoOk = 0;
                if(buffer[i] == ' ')
                {
                    contador++;
                }
                if(contador > 1 || buffer[0] == ' ')
                {
                    todoOk = 1;
                    break;
                }
                i++;
            }
            if(i>=tam)
            {
                printf("\nError cadena muy extensa tamanio maximo: %d\n", tam);
            }
            if(todoOk == 1)
            {
                printf("Reingre nombre sin numeros\n");
            }
        }while(todoOk==1 || i >= tam);
    }
    strcpy(cadena,buffer);
    return todoOk;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt; //espacio de intercambio con el usuario
	int retorno;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && pResultado && minimo <= maximo && reintentos>=0 )
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >=0);
	}
	return retorno;
}


int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float bufferInt; //espacio de intercambio con el usuario
	int retorno;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && pResultado && minimo <= maximo && reintentos>=0 )
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%f",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
