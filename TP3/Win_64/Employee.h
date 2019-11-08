#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva espacio en memoria para un Empleado
 *
 * \return Employee* Un puntero a Empleado
 *
 */
Employee* employee_new();
/** \brief Reserva espacio en memoria para un empleado, pasandole como parametros los atributos que este va a tener.
 *
 * \param idStr char* Id del empleado
 * \param nombreStr char* Nombre del Empleado
 * \param horasTrabajadasStr char* Horas trabajadas del Empleado
 * \param sueldoStr char* Sueldo del Empleado
 * \return Employee* Retorna un puntero a empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Libera el espacio en memoria reservado para ese empleado
 *
 * \param unEmpleado Employee* un Empleado
 * \return void
 *
 */
void employee_delete(Employee* unEmpleado);

/** \brief Asigna un ID a un empleado
 *
 * \param this Employee* Un empleado
 * \param id int El id a asignar
 * \return int retorna si pudo o no asignar el ID
 *
 */
int employee_setId(Employee* this,int id);
/** \brief Obtiene el ID de un empleado
 *
 * \param this Employee* Un empleado
 * \param id int* El id a obtener
 * \return int El Id del empleado en caso de que lo haya encontrado. sino, Retorna 0
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Asigna El nombre a un Empleado
 *
 * \param this Employee* Un empleado
 * \param nombre char* El nombre a asignar
 * \return int si pudo o no asignar el nombre
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Obtiene El nombre de un Empleado
 *
 * \param this Employee* Un empleado
 * \param nombre char* El nombre a obtener
 * \return int si pudo o no obtener el nombre
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Asigna las horas trabajadas de un Empleado
 *
 * \param this Employee* Un Empleado
 * \param horasTrabajadas int las horas trabajadas a asignar
 * \return int si pudo o no asignar las horas trabajadas
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief  obtiene las horas trabajadas de un Empleado
 *
 * \param this Employee* Un empleado
 * \param horasTrabajadas int* Las horas trabajadas a obtener
 * \return int si pudo o no Obtener las horas trabajadas de un Empleado
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Asigna el sueldo a un Empleado
 *
 * \param this Employee* Un Empleado
 * \param horasTrabajadas int El sueldo a asignar
 * \return int si pudo o no asignar las El sueldo a un Empleado
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief  obtiene el sueldo de un Empleado
 *
 * \param this Employee* Un empleado
 * \param horasTrabajadas int* El sueldo a obtener
 * \return int Si pudo o no obtener el sueldo de un empleado
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara en este caso dos empleados
 *
 * \param void* el primer empleado
 * \param void* el segundo empleado
 * \return int 0 si los empleados son iguales o 1 si el primero es mayor al segundo
 *
 */
int compararPorLegajo(void*,void*);
/** \brief Compara en este caso dos empleados
 *
 * \param void* el primer empleado
 * \param void* el segundo empleado
 * \return int 0 si los empleados son iguales o 1 si el primero es mayor al segundo
 *
 */
int compararPorSueldo(void*,void*);
/** \brief Compara en este caso dos empleados
 *
 * \param void* el primer empleado
 * \param void* el segundo empleado
 * \return int 0 si los empleados son iguales o 1 si el primero es mayor al segundo
 *
 */
int compararPorNombre(void*,void*);
/** \brief Compara en este caso dos empleados
 *
 * \param void* el primer empleado
 * \param void* el segundo empleado
 * \return int 0 si los empleados son iguales o 1 si el primero es mayor al segundo
 *
 */
int compararPorHorasTrabajadas(void*,void*);
/** \brief Muestra un Empleado
 *
 * \param emp Employee* Un empleado
 * \return void
 *
 */
void mostrarEmpleado(Employee* emp);

#endif // employee_H_INCLUDED
