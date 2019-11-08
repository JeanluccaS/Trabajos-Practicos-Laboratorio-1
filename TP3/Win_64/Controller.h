#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "pedirDatos.h"

/** \brief Carga los empleados desde un archivo de texto/csv
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int si pudo o no cargar los empleados
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los empleados desde un archivo de binario
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int si pudo o no cargar los empleados
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Agrega un empleado a la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no cargar los empleados
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Edita un Empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no editarlos
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Remueve un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int  si pudo o no editarlos
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Muestra los empleados de la lista
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si se pudo o no listar los empleados
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordena los empleados
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int si pudo o no ordenar los empleados
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los empleados en un archivo de texto
 *
* \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int si pudo o no guardar los empleados
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los empleados en un archivo binario
 *
* \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int si pudo o no guardar los empleados
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Obtiene el Mayor ID de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \return int El Mayor id
 *
 */
int dameMayorId(LinkedList* pArrayListEmployee);
/** \brief Busca y verifica que ese empleado se encuentre en la lista, si lo encuentra, lo retorna.
 *
 * \param pArrayListEmployee LinkedList* la lista de empleados
 * \param id int El id a buscar
 * \return void* Un empleado
 *
 */
void* controller_getEmpleadoPorId(LinkedList* pArrayListEmployee,int id);
