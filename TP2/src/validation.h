/*
 * validation.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Agustin
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_



#endif /* VALIDATION_H_ */

/** \brief validates the string that you cannot enter numbers and no space in the index 0 allows
you to put only 1 space and cannot exceed the size of the string
*
* \param char[] cadena
* \param char mensaje
* \param int tam
* \return int Return (0) returns 0 when validating the string
*
*/
int validacionL(char cadena[], char mensaje[],int tam);
/** \brief
Validate that only numbers can be entered and the range passed by parameters
also the message that you want to report and the message when giving error
*
* \param int* pResultado
* \param char* mensaje
* \param char* mensajeError
* \param int minimo
* \param int maximo
* \param int reintentos
* \return int Return  (-1) at the end of the validation correctly
*
*/
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/** \brief Validate that only floats can be entered and the range passed by parameters
also the message that you want to report and the message when giving error
*
* \param float* pResultado
* \param char* mensaje
* \param char* mensajeError
* \param int minimo
* \param int maximo
* \param int reintentos
* \return int Return  (-1) at the end of the validation correctly
*
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
