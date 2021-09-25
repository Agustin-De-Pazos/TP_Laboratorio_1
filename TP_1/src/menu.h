/*
 * menu.h
 *
 *  Created on: 25 sept. 2021
 *      Author: Agustin
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
/** \brief Menu de opciones:
 *
 * \return int retorna la opcion elegida
 *
 */
int menu();

/** \brief Recibe un array de caracteres a mostrar y retorna un numero ingresado por el usuario
 *
 * \param mensaje[] array de caracteres (mensaje)
 * \return retorna el numero ingresado
 *
 */
int getNum(char mensaje[]);

#endif /* MENU_H_ */
