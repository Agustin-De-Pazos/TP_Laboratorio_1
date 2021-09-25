/*
 * operaciones.h
 *
 *  Created on: 25 sept. 2021
 *      Author: Agustin
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef OPERACIONES_H_
#define OPERACIONES_H_
/** \brief Recibe 2 numeros por parametro y los suma
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int suma(int x, int y);

/** \brief Recibe 2 numeros por parametro y los resta
 *
 * \param x int Primer numero ingresado
 * \param y int Segundo numero ingresado
 * \return int Retorna resultado
 *
 */
int resta(int x, int y);

/** \brief Recibe 2 numeros por parametro los castea a flotante y se realiza la division x/y. El divisor no puede ser 0
 *
 * \param x int Primer numero ingresado
 * \param y int Segundo numero ingresado
 * \return int Retorna el resultado
 *
 */
float division(int x, int y);


/** \brief Recibe 2 numeros por parametro los castea a flotante y realiza la multiplicacion
 *
 * \param x int Primer operando
 * \param y int Segundo operando
 * \return float devuelve el resultado de la multiplicacion
 *
 */
float multiplicacion(int x, int y);

/** \brief Recibe por parametro un numero y realiza el factoreal
 *
 * \param c int valor del operando
 * \return int  Retorna 0 si no realiza el factoreal por ser muy grande el numero a factorear
                Retorna el resultado del factoreal si es valido
 *
 */
int factorial(int n);

/** \brief Recibe el resultado de la suma y lo muestra.
 *
 * \param c int valor de la suma
 * \return void  Retorna 0 Si el numero a factorear es mayor a 16
                 Retorna el resultado si el factoreal es valido
 *
 */
void sumaPrint(int c);


/** \brief Recibe el resultado de la resta y lo muestra
 *
 * \param c int valor del resultado
 * \return void no devuelve nada
 *
 */
void restaPrint(int c);

/** \brief Recibe por parametro el resultado y lo muesta. Si el resultado es 0 es porque no se realiza ninguna division valida
 *
 * \param c float valor de la division
 * \return void no devuelve nada
 *
 */
void divPrint(float c);


/** \brief Recibe por parametro el resultado de la multiplicacion y la muestra
 *
 * \param c float valor de la multipliacion
 * \return void no devuelve nada
 *
 */
void multiplicacionPrint(float c);


/** \brief Recibe por parametro el resultado del factoreal del primer operando y lo muestra
 *
 * \param c int valor del factoreal del primer operando
 * \return void no devuelve nada
 *
 */
void factPrintUno(int c);

/** \brief Recibe por parametro el resultado del factoreal del segundo operando y lo muestra
 *
 * \param c int valor del segundo operando
 * \return void no devuelve nada
 *
 */
void factPrintDos(int c);


#endif /* OPERACIONES_H_ */
