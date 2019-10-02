#include "Prototipos.h"
#define MAX 1000
int main()
{
    eEmpleado listaDeEmpleados[MAX];
    int opcion;
    int flag;
    int respuestaCargar;
    int respuestaBorrar;
    inicializarEmpleados(listaDeEmpleados,MAX);
    do{
    opcion = pedirEntero("\n1.Alta\n2.Baja\n3.Modificar\n4.Informar\n5.Salir\nElija una opcion: ");
    switch(opcion)
    {
    case 1:
        respuestaCargar: cargarempleados(listaDeEmpleados,MAX);
        break;
    case 2:
        respuestaBorrar: borrarEmpleado(listaDeEmpleados,MAX);
        break;
    case 4:
        listarEmpleados(listaDeEmpleados,MAX);
        break;
    default:
        printf("Opcion incorrecta");
        break;
    }

    }while(opcion!=5);




    return 0;
}
