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
    int opcion;
    int respuesta;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
            system("cls");
        opcion=printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                respuesta= controller_loadFromText("data.csv",listaEmpleados);

                if(respuesta==1)
                {
                    printf("Se cargaron los Empleados correctamente.\n");
                    flag=1;
                 }else
                {
                    printf("No se pudieron cargar los empleados.");
                }
                system("pause");
                break;
            case 2:
                system("cls");
                if(flag!=1)
                {
                    respuesta= controller_loadFromBinary("data.bin",listaEmpleados);
               if(respuesta==1)
                {
                    printf("Se cargaron los Empleados correctamente.\n");
                }else
                {
                    printf("No se pudieron cargar los empleados.");
                }
                system("pause");
                }else
                {
                    printf("No es posible cargar en binario, cuando se cargo previamente en texto.");
                }

                break;
            case 3:
                 system("cls");
                controller_addEmployee(listaEmpleados);
                system("pause");
                break;
            case 4:
                if(flag=1)
                {
                     system("cls");
                controller_editEmployee(listaEmpleados);
                system("pause");
                }else
                {
                    printf("Deben haber empleados cargados previamente.");
                }

                break;
            case 5:
                if(flag = 1)
                {
                     system("cls");
                controller_removeEmployee(listaEmpleados);
                system("pause");
                }else
                {
                    printf("Deben haber empleados cargados previamente.");
                }

                break;
            case 6:

                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
            case 7:
                 system("cls");
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;
            case 8:
                 system("cls");
                controller_saveAsText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 9:
                 system("cls");
                controller_saveAsBinary("data.bin",listaEmpleados);
                system("pause");
                break;
            case 10:
                system("cls");
                printf("Saliendo.\n");
                system("pause");
                break;
            default:
                printf("Opcion incorrecta\n");
        }
    }while(opcion != 10);

    return 0;
}

