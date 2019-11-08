#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion; //variable utilizada para el menu
    int respuesta; //variable utilizada para guardar el valor de las funciones
    int flag=0; //variable de control
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");
        opcion=printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n10. Salir \nElija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            respuesta= controller_loadFromText("data.csv",listaEmpleados);

            if(respuesta==1)
            {
                printf("Se cargaron los Empleados correctamente.\n");
                system("pause");
                flag=1;
            }
            else if(respuesta==2)
            {
                printf("ERROR. La lista ya cargada.\n");
                system("pause");
            }
            else
            {

                printf("No se pudieron cargar los empleados. \n");
                system("pause");
            }

            break;
        case 2:
            system("cls");
            respuesta= controller_loadFromBinary("data.bin",listaEmpleados);
            if(respuesta==1)
            {
                printf("Se cargaron los Empleados correctamente.\n");
                flag=2;
                system("pause");
            }
            else if(respuesta==2)
            {
                printf("ERROR. La lista ya cargada.\n");
                system("pause");
            }
            else
            {
                printf("No se pudieron cargar los empleados.\n");
                system("pause");
            }

            break;
        case 3:
            system("cls");
            respuesta = controller_addEmployee(listaEmpleados);
            if(respuesta==1)
            {
                printf("Se agrego el empelados a la lista correctamente\n");
                system("pause");
            }

            break;
        case 4:
            if(flag !=1 && flag != 2)
            {
                system("cls");
                printf("Deben haber empleados cargados previamente.\n");
                system("pause");
            }
            else
            {
                system("cls");
                controller_editEmployee(listaEmpleados);
                system("pause");
            }

            break;
        case 5:
            if(flag != 1 && flag!= 2)
            {
                system("cls");
                printf("Deben haber empleados cargados previamente.\n");
                system("pause");
            }
            else
            {
                system("cls");
                controller_removeEmployee(listaEmpleados);
                system("pause");
            }

            break;
        case 6:

            if(flag != 1 && flag!= 2)
            {
                system("cls");
                printf("Deben haber empleados cargados previamente.\n");
            }
            else
            {
                system("cls");
                respuesta= controller_ListEmployee(listaEmpleados);
                if(respuesta==1)
                {
                    printf("Se han podido listar los empleados correctamente\n");
                    system("pause");
                }
                else
                {
                    printf("ERROR. No se pudieron listar los empleados\n");
                    system("pause");
                }
            }

            break;
        case 7:


            if(flag != 1 && flag!= 2)
            {
                system("cls");
                printf("Deben haber empleados cargados previamente.\n");
                system("pause");
            }
            else
            {
                system("cls");
                respuesta=controller_sortEmployee(listaEmpleados);
                if(respuesta==1)
                {
                    system("cls");
                    printf("Se han podido Ordenar los empleados correctamente\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("ERROR. No se pudieron ordenar los empleados\n");
                    system("pause");
                }

            }

            break;
        case 8:

            respuesta= controller_saveAsText("data.csv",listaEmpleados);
            if(respuesta==1)
            {
                system("cls");
                printf("Se han guardado los empleados de manera binaria en el archivo data.csv\n");
            }
            else
            {
                system("cls");
                printf("Error al guardar el archivo\n");
            }
            system("pause");
            break;
        case 9:
            system("cls");
            respuesta= controller_saveAsBinary("data.bin",listaEmpleados);
            if(respuesta==1)
            {
                printf("Se han guardado los empleados de manera binaria en el archivo data.bin\n");
                 system("pause");
            }
            else
            {
                printf("Error al guardar el archivo\n");
                system("pause");
            }

            break;
        case 10:
            system("cls");
            printf("Saliendo.\n");
            system("pause");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    }
    while(opcion != 10);

    return 0;
}

