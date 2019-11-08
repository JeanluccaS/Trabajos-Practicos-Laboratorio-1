#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Divide los campos de un archivo de texto
 *
 * \param pFile FILE* El archivo
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no dividir los campos
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Divide los campos de un archivo binario
 *
 * \param pFile FILE* El archivo
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no dividir los campos
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
