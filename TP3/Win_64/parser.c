#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[20];
    char nombre[50];
    char horasTrabajadas[20];
    char sueldo[20];
    int retorno;
    Employee* unEmpleado=NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        unEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee,unEmpleado);
    }
    fclose(pFile);
    retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno;

    if(pFile != NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {


            Employee* unEmpleado;
            unEmpleado=employee_new();
                fread(unEmpleado,sizeof(Employee),1,pFile);


            if(feof(pFile))
            {
                break;
            }
            ll_add(pArrayListEmployee,unEmpleado);
        }
        fclose(pFile);
        retorno=1;
    }


    return retorno;
}
