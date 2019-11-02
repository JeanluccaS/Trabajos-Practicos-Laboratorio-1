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
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
            system("cls");
        opcion=printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                 system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");
                break;
            case 3:
                 system("cls");
                controller_addEmployee(listaEmpleados);
                system("pause");
                break;
            case 4:
                 system("cls");
                controller_editEmployee(listaEmpleados);
                system("pause");
                break;
            case 5:
                 system("cls");
                controller_removeEmployee(listaEmpleados);
                system("pause");
                break;
            case 6:
                 system("cls");
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
        }
    }while(opcion != 10);

    return 0;
}

