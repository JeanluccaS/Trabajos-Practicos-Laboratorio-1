#include "Prototipos.h"


int inicializarEmpleados(eEmpleado* listaDeEmpleados,int tam)
{
    int i;
    int retorno;

    if(listaDeEmpleados != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            listaDeEmpleados[i].estaVacio=VACIO;
            listaDeEmpleados[i].id=0;
        }
        retorno=0;
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}

int cargarempleados (eEmpleado* listaDeEmpleados,int tam)
{

    int id;
    int salario;
    int sector;
    int retorno;
    char nombre[15];
    char apellido[15];

    if(listaDeEmpleados!= NULL && tam > 0)
    {
        retorno=dameIndiceLibre(listaDeEmpleados,tam);
        if (retorno != -1)
        {
            id=dameMayorID(listaDeEmpleados,tam);
            id++;
            pedirString("Ingrese el nombre: ",nombre,"Error, reingrese un nombre valido (limite: 50 caracteres)");
            pedirString("Ingrese el apellido: ",apellido,"Error, reingrese un apellido valido (limite: 50 caracteres)");
            salario=pedirEntero("Ingrese el salario: ");
            sector=pedirEntero("Ingrese el sector: ");
            retorno=cargarEmpleado(listaDeEmpleados,tam,id,nombre,apellido,salario,sector);
        }
    }

    return retorno;
}

int cargarEmpleado(eEmpleado* listaDeEmpleados, int tam, int id, char nombre[], char apellido[], int salario,int sector)
{
    int retorno;
    int indice;

    if(listaDeEmpleados!= NULL && tam > 0)
    {
        indice=dameIndiceLibre(listaDeEmpleados,tam);
        if (indice != -1)
        {

            listaDeEmpleados[indice].id=id;
            strcpy(listaDeEmpleados[indice].nombre,nombre);
            strcpy(listaDeEmpleados[indice].apellido,apellido);
            listaDeEmpleados[indice].salario=salario;
            listaDeEmpleados[indice].sector=sector;
            listaDeEmpleados[indice].estaVacio=OCUPADO;
            retorno = 0;
        }
    }
    else{
        retorno = -1;
    }

    return retorno;
}

int dameMayorID (eEmpleado listaDeEmpleados[],int tam)
{
    int i;
    int flag=0;
    int idMayor;
    for(i=0;i<tam;i++)
    {
        if(flag==0||listaDeEmpleados[i].id>idMayor)
        {
            idMayor=listaDeEmpleados[i].id;
            flag=1;
        }
    }
    return idMayor;

}
int listarEmpleados(eEmpleado* listaDeEmpleados,int tam)
{
    int i;
    int retorno=0;
    printf("\nID\t\tNombre\tApellido\tSalario\tSector\n");
    for(i=0; i<tam; i++)
    {
        if(listaDeEmpleados[i].estaVacio==OCUPADO)
        {
            retorno=1;
            mostrarEmpleado(listaDeEmpleados[i]);
        }
    }
    return retorno;
}

void mostrarEmpleado(eEmpleado empleado)
{
    printf ("\n%d",empleado.id);
    printf("\t\t%s",empleado.nombre);
    printf("\t\t%s",empleado.apellido);
    printf("\t\t%f",empleado.salario);
    printf("\t\t%d",empleado.sector);
}


int dameIndiceLibre(eEmpleado* listaDeEmpleados,int tam)
{
    int i;
    int indiceLibre=-1; //fuera de incide, fuerra del array
    for(i=0; i<tam; i++)
    {
        if(listaDeEmpleados[i].estaVacio==VACIO)
        {
            indiceLibre=i;
            break;
        }
    }
    return indiceLibre;

}



int buscarempleado(eEmpleado* empleados,int tam)
{
    int i;
    int numero;
    int loEncontre=-1; //fuera de indice
    numero=pedirEntero("\n\nIngrese el id a buscar: ");
    for(i=0; i<tam; i++)
    {
        if(numero==empleados[i].id && empleados[i].estaVacio==OCUPADO)
        {
            loEncontre=i;
        }
    }
    return loEncontre;
}

void pedirString (char mensaje[],char contenido[], char mensajeDeError[])
{
    char auxString[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(auxString);
    while(strlen(auxString)>50)
    {
        char auxString[100];
        printf(mensajeDeError,mensaje);
        fflush(stdin);
        gets(auxString);
    }
    strcpy(contenido,auxString);
}

int pedirEntero (char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;
}

int modificarempleado(eEmpleado* empleados,int tam)
{
    int seModifico=0; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    int salario;
    int opcion;
    char nombre[50];
    char respuesta;
    eEmpleado aux;
    index=buscarempleado(empleados,tam);
    aux = empleados[index];
    if(index!=-1)
    {
            seModifico=1;

            printf("\nEl empleado a Modificar es: \n");
            mostrarEmpleado(empleados[index]);
            opcion=pedirEntero("\n Que dato desea modificar?\n1. Nombre\n2. salario\n Ingrese una opcion: ");
            switch(opcion)
            {
            case 1:
                pedirString("Ingrese nuevo nombre: ",nombre,"Error, reingrese un nombre valido (maximo 50 caracteres)");
                strcpy(aux.nombre,nombre);
                break;
            case 2:
                salario=pedirEntero("Ingrese una nueva salario: ");
                aux.salario=salario;
                break;
            case 3:
                printf("Saliendo...");
                break;
            default:
                printf("Opcion no valida");
            }
            if(seModifico==1)
            {
                printf("\nEl empleado a modificar va a quedar de la siguiente manera: ");
                mostrarEmpleado(aux);
                printf("\nDesea guardar los cambios? 's' para guardar.");
                respuesta=getchar();
                if(respuesta=='s')
                {
                    empleados[index]=aux;
                }
                else
                {
                    printf("\nNo se realizo la modificacion");
                }
            }

    }
    return seModifico;
}

int borrarEmpleado (eEmpleado* empleados, int tam)
{

    int retorno=-1; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    index=buscarempleado(empleados,tam);
    if(index!=-1)
    {
            retorno=0;
            empleados[index].estaVacio=VACIO;
            printf("\nEl empleado a borrar es: \n");
            mostrarEmpleado(empleados[index]);
    }







    return retorno;
}

