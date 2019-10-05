#include "Prototipos.h"
#define MAX 1000
int main()
{

    eEmpleado listaDeEmpleados[MAX];
    int opcion;
    int flag=0;
    int respuestaCargar;
    int respuestaBorrar;
    int respuestaModificar;
    int respuestaMostrar;

    inicializarEmpleados(listaDeEmpleados,MAX);
    do
    {
        system("cls");
        opcion = pedirEntero("\n1.Alta\n2.Baja\n3.Modificar\n4.Informar\n5.Salir\nElija una opcion: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            respuestaCargar=cargarempleados(listaDeEmpleados,MAX);

            if(respuestaCargar==-1)
            {
                printf("No se pudo cargar un nuevo empleado");
                system("pause");
            }
            else
            {
                printf("Carga realizada con exito");

                flag=1;

                system("pause");
            }
            break;
        case 2:
            system("cls");
            if(flag== 1)
            {
                respuestaBorrar=borrarEmpleado(listaDeEmpleados,MAX);

                if(respuestaBorrar==-1)
                {
                    printf("No se pudo Borrar al empleado");
                    system("pause");
                }
                else
                {
                    printf("Empleado borrado con exito");
                    system("pause");
                }
            }
            else
            {
                printf("Error, debe tener cargado  empleados para ingresar a esta opcion. (minimo 1)");
                system("pause");
            }

            break;
        case 3:
            system("cls");
            if(flag==1)
            {
                respuestaModificar= modificarEmpleado(listaDeEmpleados,MAX);
                if(respuestaModificar==-1)
                {
                    printf("No se pudo realizar la modificacion");
                    system("pause");
                }
                else if(respuestaModificar==1)
                {
                    printf("Se cancelo la modificacion");
                    system("pause");

                }
                else
                {
                    printf("Modificacion realizada correctamente");
                    system("pause");
                }
            }
            else
            {
                printf("Error, debe tener cargado  empleados para ingresar a esta opcion. (minimo 1)");
                system("pause");
            }
            break;

        case 4:
            system("cls");
            if(flag==1)
            {
                respuestaMostrar=informarEmpleado(listaDeEmpleados,MAX);
                if(respuestaMostrar==-1)
                {
                    printf("no se pueden mostrar los empleados");
                    system("pause");
                }
            }
            else
            {
                printf("Error, debe tener cargado empleados para ingresar a esta opcion. (minimo 1)");
                system("pause");
            }

            break;
        case 5:
            system("cls");
            printf("Saliendo...");
            system("pause");
            break;
        default:
            printf("Opcion incorrecta");
            system("pause");
            break;
        }

    }
    while(opcion!=5);




    return 0;
}
