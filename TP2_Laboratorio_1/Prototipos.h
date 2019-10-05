#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define VACIO 0
#define OCUPADO 1

typedef struct{
   int id;
   char nombre[51];
   char apellido[51];
   float salario;
   int sector;
   int estaVacio;// 0 para esta vacio, 1 para cuando esta ocupado

}eEmpleado;

/** \brief funcion que incializa el ID y el estado del array de empleados en LIBRE
 *
 * \param eEmpleado* recibe la lista de empleados
 * \param tam int recibe el largo de la lista
 * \return int 0 si se pudo o -1 si no se pudo inicializar el array.
 *
 */
int inicializarEmpleados(eEmpleado*,int tam);
/** \brief funcion utilizada para ordenar alfabeticamente los empleados del array por apellido
 *
 * \param listaDeEmpleados eEmpleado* recibe la lista de empleados
 * \param tam int el tamaño del array
 * \param orden int utilizado para elegir si se quiere ordenar de manera ascendente o descendente
 * \return int 0 si se pudo o -1 si no se pudo ordenar el array de empleados
 *
 */
int ordenarEmpleados(eEmpleado* listaDeEmpleados,int tam, int orden) ;
/** \brief muestra todos los empleados siempre y cuando esten ocupando espacio en el array.
 *
 * \param eEmpleado[] recibe la lista de empleados
 * \param tam int recibe el tamaño
 * \return int y retorna 0 si se pudo o -1 si no se pudo listar empleados
 *
 */
int listarEmpleados(eEmpleado[],int tam);
/** \brief muestra un empleado
 *
 * \param eEmpleado recibe un empleado
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado);
/** \brief funcion encargada de devolver el primer indice disponible que no este OCUPADO
 *
 * \param eEmpleado[] recibe el array de empleados
 * \param tam int recibe el tamaño del array
 * \return int -1 si no encontro espacio o retorna el indice disponible.
 *
 */
int dameIndiceLibre(eEmpleado[],int tam);
/** \brief funcion encargada de agregar un empleado al array
 *
 * \param eEmpleado recibe la lista de empleados
 * \param int tam recibe el largo del array
 * \return retorna 0 si se pudo o  -1 no cargar un empleado
 *
 */
int cargarempleados (eEmpleado* listaDeEmpleados,int tam);
/** \brief funcion utilizada para pedir una cadena de caracteres
 *
 * \param char mensaje de peticion
 * \param char array donde se va a guardar la cadena de caracteres
 * \return void
 *
 */
void pedirString (char mensaje[],char contenido[],char mensajeDeError[]);
/** \brief funcion utilizada para pedir un numero entero
 *
 * \param char mensaje de peticion
 * \return int el numero ingresado
 *
 */
int pedirEntero (char mensaje[]);
/** \brief funcion utilizada para pedir un caracter
 *
 * \param char mensaje de peticion
 * \return int el caracter ingresado
 *
 */
char pedirCaracter (char mensaje[]);
/** \brief busca un empleado en el array de empelados
 *
 * \param eEmpleado[] el array de empleados
 * \param tam int el tamaño
 * \return int -1 si no se encontro y el indice, en caso de que lo haya encontrado.
 *
 */
int buscarEmpleado(eEmpleado[],int tam);
/** \brief
 *
 * \param eEmpleado[] el array de empleados
 * \param tam int el tamaño
 * \return int -1 si no lo borro y 0, en caso de que lo haya encontrado.
 *
 */
int borrarEmpleado(eEmpleado[],int tam);
/** \brief modifica un empleado
 *
 * \param eEmpleado[] el array de empleados
 * \param tam int el tamaño
 * \return int 0 si se pudo modificar, -1 si no se pudo modificar y 1 si se cancelo la modificacion
 *
 */
int modificarEmpleado(eEmpleado[],int tam);
/** \brief funcion encargada de cargar los datos de un empleado
 *
 * \param eEmpleado* el array de empleados
 * \param tam int el tamao del array
 * \param id int el ID del empleado
 * \param nombre[] char el nombre del empleado
 * \param apellido[] char el apellido del empleado
 * \param salario int el salario de un empleado
 * \param sector int el sector del empleado
 * \return int 0 si se pudo cargar los datos en la estructura o -1 si no pudo.
 *
 */
int cargarEmpleado(eEmpleado* , int tam, int id, char nombre[], char apellido[], int salario,int sector);
/** \brief Busca el mayor ID cargado en el array
 *
 * \param eEmpleado el array de empleados de empleados
 * \param int tam el tamaño del array
 * \return El mayor id
 *
 */
int dameMayorID (eEmpleado listaDeEmpleados[],int tam);
/** \brief lista a los empleados alfabeticamente o muestra el promedio, el salario total y el/los salarios que superan el promedio
 *
 * \param eEmpleado el array de empleados
 * \param int tam el tamaño del array
 * \return 0 si se pudieron mostrar empleados o -1 si no se pudo.
 *
 */
int informarEmpleado (eEmpleado* listaDeEmpleado,int tam);
/** \brief se encarga de buscar el salario maximo
 *
 * \param listaDeEmpleado eEmpleado* el array de empleados
 * \param tam int el tamaño del array
 * \return int -1 si no se pudo encontrar el salario maximo, 1 si no hay empleados que superen el promedio y 0 si lo encontro
 *
 */
int salarioMaximo(eEmpleado* listaDeEmpleado,int tam);
/** \brief se encarga de realizar un promedio de los salarios
 *
 * \param eEmpleado el array de empleados
 * \param int tam el tamaño del array
 * \return -1  si no pudo realizar el promedio o retorna el promedio
 *
 */
float dameElPromedio (eEmpleado* listaDeEmpleados,int tam);
/** \brief se encarga de realizar una suma de los promedios cargados en el array de empelados
 *
 * \param eEmpleado el array de empleados
 * \param int tam el tamaño del array
 * \return -1 si no pudo realizar la suma de los salarios o retorna el resultado de la suma.
 *
 */
float dameElSalarioTotal (eEmpleado* listaDeEmpleado,int tam);
