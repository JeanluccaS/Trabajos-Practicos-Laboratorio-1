
#include "Employee.h"



int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;

    if( this != NULL && id != NULL )
    {

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* this;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(idStr))||

                    !employee_setNombre(this, nombreStr) ||

                    !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||

                    !employee_setSueldo(this, atoi(sueldoStr)))
            {
                free(this);
                this = NULL;
            }
        }
    }

    return this;
}


void mostrarEmpleado(Employee* emp)
{
    if(emp != NULL)
    {
        printf("%4d  %15s  %4d  %8d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}

int compararPorLegajo(void* e1,void* e2)
{
    int compara=-1;
    int id1;
    int id2;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2; //estos dos empleados van a servir para guardar e1,e2
    employee_getId(empleado1,&id1);
    employee_getId(empleado2,&id2);
    if( id1 > id2 ) //si el primero es mayor al segundo
    {
        compara = 1;
    }
    else
    {
        if(id1  == id2 )
        {
            compara = 0;
        }
    }
    return compara;
}

int compararPorSueldo(void* e1,void* e2)
{
    int compara=-1;
    int sueldo1;
    int sueldo2;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2; //estos dos empleados van a servir para guardar e1,e2
    employee_getSueldo(empleado1,&sueldo1);
    employee_getSueldo(empleado2,&sueldo2);
    if( sueldo1 > sueldo2 ) //si el primero es mayor al segundo
    {
        compara = 1;
    }
    else
    {
        if(sueldo1  == sueldo2 )
        {
            compara = 0;
        }
    }
    return compara;
}

int compararPorNombre(void* e1,void* e2)
{
    int compara=-1;


    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2; //estos dos empleados van a servir para guardar e1,e2

    char n1[50];
    employee_getNombre(empleado1,n1);
    char n2[50];
    employee_getNombre(empleado2,n2);


    compara=strcmp(n1,n2);
    return compara;
}

void employee_delete(Employee* unEmpleado)
{
    free(unEmpleado);
    unEmpleado=NULL;
}





