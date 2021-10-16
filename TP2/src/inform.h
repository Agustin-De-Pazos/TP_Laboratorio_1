#ifndef INFORM_H_INCLUDED
#define INFORM_H_INCLUDED
#include "employee.h"


#endif // INFORM_H_INCLUDED
/** \brief shows an employee from the list
*
* \param list Employee*
* \param length int
* \return void
*/
void printEmployee(eEmployee oneEmployee);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(eEmployee list[],int len);
/** \brief calculates the average salary of all employees and shows the number
of employees the total average and how many are above the average
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int totalAverageSalary(eEmployee* list, int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee list[], int len, int order);
/** \brief report menu switch
*
* \param list Employee*
* \param len int
*/
void reports(eEmployee* list, int len);
