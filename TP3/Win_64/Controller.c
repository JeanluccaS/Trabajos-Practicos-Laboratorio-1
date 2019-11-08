#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno=-1;
    int estaVacio=0;
    pArchivo = fopen(path,"rb");

    if(pArchivo!=NULL)
    {
        estaVacio=ll_isEmpty(pArrayListEmployee);
        if(estaVacio==1)
        {
            retorno=parser_EmployeeFromText(pArchivo,pArrayListEmployee);

        }
        else
        {
            retorno=2;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno=-1;
    int estaVacio=0;
    pArchivo=fopen(path,"rb");

    if(pArchivo!= NULL && pArrayListEmployee !=NULL)
    {
        estaVacio=ll_isEmpty(pArrayListEmployee);
        if(estaVacio==1)
        {
            retorno=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        }
        else
        {
            retorno=2;
        }
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
    int respuesta;
    int retorno=-1;
    Employee* unEmpleado = employee_new();

    if(pArrayListEmployee!=NULL)
    {

        id=dameMayorId(pArrayListEmployee);
        id++;
        employee_setId(unEmpleado,id);
        pedirString("Ingrese el nombre del empleado ",nombre,"Error, sobrepaso el limite de caracteres (50)");
        employee_setNombre(unEmpleado,nombre);
        horasTrabajadas = pedirEntero("Ingrese las horas trabajadas del Empleado ");
        employee_setHorasTrabajadas(unEmpleado,horasTrabajadas);
        sueldo=pedirEntero("Ingrese el sueldo del empleado ");
        employee_setSueldo(unEmpleado,sueldo);
        respuesta=pedirCaracter("quiere cargar el empleado? 's' para si");
        if(respuesta=='s')
        {
            ll_add(pArrayListEmployee,unEmpleado);
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* unEmpleado=NULL;
    Employee* auxEmpleado;
    int flag=0;
    int retorno=-1;
    int id;
    int respuesta;
    int opcion;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id=pedirEntero("Ingrese el ID del empleado que desea modificar: ");
        unEmpleado=controller_getEmpleadoPorId(pArrayListEmployee,id);
        if(unEmpleado!=NULL)
        {
            auxEmpleado=unEmpleado;
            do
            {
                opcion = pedirEntero("1)Modificar Nombre.\n2)Modificar horas trabajadas.\n3)Modificar sueldo.\n4)Salir.\n");
                switch(opcion)
                {
                case 1:
                    pedirString("Ingrese el nuevo nombre: ",nombre,"Error, se excedio el limite de caracteres (50)");
                    employee_setNombre(auxEmpleado,nombre);
                    flag=1;
                    break;
                case 2:
                    horasTrabajadas=pedirEntero("Ingrese la nueva cantidad de horas trabajadas: ");
                    employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas);
                    flag=1;
                    break;
                case 3:
                    sueldo=pedirEntero("Ingrese el nuevo sueldo: ");
                    employee_setSueldo(auxEmpleado,sueldo);
                    flag=1;
                    break;
                case 4:
                    printf("saliendo..\n");
                    break;
                default:
                    printf("Error, ingrese una opcion valida: \n");
                }
            }
            while(opcion!=4);
            if(flag==1)
            {
                printf("El empleado se va a quedar de la siguiente manera: ");
                mostrarEmpleado(auxEmpleado);
                respuesta=pedirCaracter("Desea guardar los cambios? Presione 's' para guardar.");
                if(respuesta=='s')
                {
                    unEmpleado=auxEmpleado;
                    retorno=1;
                }
                else
                {
                    retorno=2;
                }
            }
            else
            {
                retorno=3;
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* unEmpleado;
    int retorno;
    int id;
    int respuesta;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id=pedirEntero("Ingrese el ID del empleado que desea eliminar: ");

        unEmpleado=controller_getEmpleadoPorId(pArrayListEmployee,id);

        mostrarEmpleado(unEmpleado);
        if(unEmpleado!=NULL)
        {
            mostrarEmpleado(unEmpleado);
            respuesta=  pedirCaracter("Desea Dar de baja este empleado? Presione 's' para darlo de baja.");

            if(respuesta == 's')
            {
                ll_remove(pArrayListEmployee,id);
                retorno=1;
            }
            else
            {
                retorno=-1;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    int retorno=-1;
    Employee* unEmpleado=NULL;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        printf("%4s%15s%4s%8s\n","Id","Nombre","Horas Trabajadas","Sueldo");
        for(i=0; i<len; i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            mostrarEmpleado(unEmpleado);
            if(i!=0 && i%250 == 0)
            {
                system("pause");
            }
        }
        retorno=1;
    }
    return retorno;;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    int orden;

    if(pArrayListEmployee!=NULL)
    {
        do
        {
            opcion=pedirEntero("Ingrese el criterio de Ordenamiento.\n 1) Ordenar por nombre.\n2) Ordenar por ID.\n3) Ordenar por horas trabajadas.\n4) Ordenar por sueldo.\n5)Salir.");
            switch(opcion)
            {
            case 1:
                orden=pedirEntero("Ingrese '1' para ordenar de manera descendete o '2' para ordenarlo de manera ascendente");
                ll_sort(pArrayListEmployee,compararPorNombre,orden-1);
                break;
            case 2:
                orden=pedirEntero("Ingrese '1' para ordenar de manera descendete o '2' para ordenarlo de manera ascendente");
                ll_sort(pArrayListEmployee,compararPorLegajo,orden -1);
                break;
            case 3:
                orden=pedirEntero("Ingrese '1' para ordenar de manera descendete o '2' para ordenarlo de manera ascendente");
                ll_sort(pArrayListEmployee,compararPorHorasTrabajadas,orden-1);
                break;
            case 4:
                orden=pedirEntero("Ingrese '1' para ordenar de manera descendete o '2' para ordenarlo de manera ascendente");
                ll_sort(pArrayListEmployee,compararPorSueldo,orden-1);
                break;
            case 5:
                printf("Saliendo");
                break;
            default:
                printf("Opcion incorrecta");
            }
        }
        while(opcion!=5);
        retorno=1;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivo;
    Employee* unEmpleado;
    int i;
    int len;
    pArchivo=fopen(path,"w");
    int id;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    if(pArchivo!=NULL && pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        fprintf(pArchivo,"%s,%s,%s,%s\n","Id","nombre","horas","sueldo");

        for(i=0; i<len; i++)
        {
            unEmpleado =(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(unEmpleado,&id);
            employee_getNombre(unEmpleado,nombre);
            employee_getSueldo(unEmpleado,&sueldo);
            employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);
            fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);

        }
        fclose(pArchivo);
        retorno=1;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;

    int retorno=-1;
    Employee* unEmpleado;
    int len;
    int i;
    pArchivo=fopen(path,"wb");

    if(pArrayListEmployee!=NULL && pArchivo !=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(unEmpleado,sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
        retorno=1;
    }
    return retorno;
}

int dameMayorId(LinkedList* pArrayListEmployee)
{
    int flag=0;
    int len;
    int retorno=-1;
    int idMayor=0;
    int i;
    Employee* unEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=25; i<len; i++)
        {
            unEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            if(flag == 0 || unEmpleado->id > idMayor)
            {
                idMayor=unEmpleado->id;
                retorno=idMayor;
                flag=1;
            }
        }
    }
    return retorno;
}

void* controller_getEmpleadoPorId(LinkedList* pArrayListEmployee,int id)
{
    int i;
    int len;
    Employee* unEmpleado=NULL;

    len=ll_len(pArrayListEmployee);
    for(i=0; i<len; i++)
    {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
        if(unEmpleado->id==id)
        {
            return unEmpleado;
            break;
        }
    }
    return unEmpleado;
}



