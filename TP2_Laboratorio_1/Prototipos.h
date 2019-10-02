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

int inicializarEmpleados(eEmpleado*,int tam);

int listarEmpleados(eEmpleado[],int tam);
void mostrarEmpleado(eEmpleado);
int dameIndiceLibre(eEmpleado[],int tam);
int cargarempleados (eEmpleado* listaDeEmpleados,int tam);
void pedirString (char mensaje[],char contenido[],char mensajeDeError[]);
int pedirEntero (char mensaje[]);
int buscarEmpleado(eEmpleado[],int tam);
int borrarEmpleado(eEmpleado[],int tam);
int modificarEmpleado(eEmpleado[],int tam);
int cargarEmpleado(eEmpleado* , int tam, int id, char nombre[], char apellido[], int salario,int sector);
int dameMayorID (eEmpleado listaDeEmpleados[],int tam);
