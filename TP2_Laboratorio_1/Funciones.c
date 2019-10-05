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
    else
    {
        retorno = -1;
    }

    return retorno;
}

int dameMayorID (eEmpleado listaDeEmpleados[],int tam)
{
    int i;
    int flag=0;
    int idMayor;
    for(i=0; i<tam; i++)
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
    int retorno;
    if(listaDeEmpleados != NULL && tam > 0)
    {
        printf("\nID\t\tNombre\tApellido\tSalario\t\tSector\n");
        for(i=0; i<tam; i++)
        {
            if(listaDeEmpleados[i].estaVacio==OCUPADO)
            {
                retorno=0;
                mostrarEmpleado(listaDeEmpleados[i]);
            }
        }
    }
    else
    {
        retorno=-1;
    }




    return retorno;
}

void informarSalarios(eEmpleado* listaDeEmpleados,int tam)
{

    int opcion;
    float salarios=0;
    if (listaDeEmpleados!=NULL && tam > 0)
    {
        do
        {
            system("cls");
            opcion=pedirEntero("\n1. Informar la suma total de los salarios.\n2 .Informar el promedio de los salarios.\n3. Informar salarios mayores al promedio.\n4. Salir\nIngrese una opcion: ");
            switch(opcion)
            {
            case 1:
                system("cls");
                salarios= dameElSalarioTotal(listaDeEmpleados,tam);
                if(salarios==-1)
                {
                    printf("No fue posible mostrar el salario total\n");
                }
                else
                {
                    printf("Salario total: %.2f\n",salarios);
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                salarios= dameElPromedio(listaDeEmpleados,tam);
                if(salarios==-1)
                {
                    printf("No fue posible mostrar el promedio\n");
                }
                else
                {
                    printf("Promedio total: %.2f\n",salarios);
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                salarios= salarioMaximo(listaDeEmpleados,tam);
                if(salarios==-1)
                {
                    printf("No fue posible mostrar el salario maximo\n");
                }
                else if(salarios==1)
                {
                    printf("\nNo se encontraron empleados que superen el promedio\n");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                printf("Saliendo...");
                system("pause");
                break;
            default:
                printf("\nError, Ingrese una opcion valida.");

            }

        }
        while(opcion!=4);
    }
}

float dameElSalarioTotal (eEmpleado* listaDeEmpleado,int tam)
{
    float retorno;
    int i;
    float acumulador=0;
    if(listaDeEmpleado!=NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(listaDeEmpleado[i].estaVacio==OCUPADO)
            {
                acumulador=listaDeEmpleado[i].salario+acumulador;
                retorno=acumulador;
            }

        }
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

float dameElPromedio (eEmpleado* listaDeEmpleados,int tam)
{
    float retorno;
    float acumulador=0;
    float contadorEmpleados=0;
    float promedio=0;
    int i;
    if(listaDeEmpleados != NULL && tam > 0)
    {

        acumulador=dameElSalarioTotal(listaDeEmpleados,tam);
        for(i=0; i<tam; i++)
        {
            if(acumulador!=-1)
            {
                if(listaDeEmpleados[i].estaVacio==OCUPADO)
                {
                    contadorEmpleados++;
                }
            }
        }
        promedio=acumulador/contadorEmpleados;
        retorno=promedio;
    }
    else
    {
        retorno=-1;
    }
    return retorno;


}

int salarioMaximo(eEmpleado* listaDeEmpleados,int tam)
{
    int retorno;
    int i;
    float promedio;
    if(listaDeEmpleados!=NULL && tam > 0)
    {
        promedio=dameElPromedio(listaDeEmpleados,tam);
        if(promedio!=-1)
        {

            for(i=0; i<tam; i++)
            {
                if(listaDeEmpleados[i].estaVacio==OCUPADO)
                {

                    if(listaDeEmpleados[i].salario>promedio )
                    {

                        printf("%.2f",promedio);
                        printf("El empleado con mayor salario es: ");
                        mostrarEmpleado(listaDeEmpleados[i]);
                        retorno=0;

                    }
                    else
                    {
                        retorno=1;
                    }
                }
            }
        }

    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

int informarEmpleado (eEmpleado* listaDeEmpleados,int tam)
{
    int orden;
    int retorno;
    int opcion;
    int ordenar;
    if (listaDeEmpleados !=NULL && tam > 0)
    {
        do
        {
            opcion = pedirEntero("\n1.Listar empleados ordenados alfabeticamente por apellido.\n2 Mostrar el total, el promedio y los empleados que superan el promedio.\n3.Salir.");
            switch (opcion)
            {
            case 1:
                system("cls");
                orden=pedirEntero("\nIngrese '1' para ordenar de manera ascendente o '0' para ordenar de manera descendente.");
                ordenar=ordenarEmpleados(listaDeEmpleados,tam,orden);
                if (ordenar!=-1)
                {
                    listarEmpleados(listaDeEmpleados,tam);
                }
                else
                {
                    printf("no se pudo ordenar");
                    retorno=0;
                }
                break;
            case 2:
                system("cls");
                informarSalarios(listaDeEmpleados,tam);
                break;
            case 3:
                system("cls");
                printf("Saliendo..");

                break;

            default:
                printf("Error, ingrese una opcion valida");
            }
        }
        while(opcion == 3);
        system("pause");
    }
    else
    {
        retorno = -1;
    }



    return retorno;
}
void mostrarEmpleado(eEmpleado empleado)
{
    printf ("\n%d",empleado.id);
    printf("\t\t%s",empleado.nombre);
    printf("\t%s",empleado.apellido);
    printf("\t\t%.2f",empleado.salario);
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

char pedirCaracter (char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}

int modificarEmpleado(eEmpleado* empleados,int tam)
{
    int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    int salario;
    int opcion;
    char nombre[50];
    char apellido[50];
    int sector;
    char respuesta;
    eEmpleado aux;

    if (empleados!=NULL && tam > 0)
    {
        listarEmpleados(empleados,tam);
        index=buscarempleado(empleados,tam);
        aux = empleados[index];
        if(index!=-1)
        {

            retorno=0;

            printf("\nEl empleado a Modificar es: \n");
            mostrarEmpleado(empleados[index]);
            opcion=pedirEntero("\n Que dato desea modificar?\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\nIngrese una opcion: ");
            switch(opcion)
            {
            case 1:
                pedirString("Ingrese nuevo nombre: ",nombre,"Error, reingrese un nombre valido (maximo 50 caracteres)");
                strcpy(aux.nombre,nombre);
                break;
            case 2:
                pedirString("Ingrese nuevo apellido: ",apellido,"Error, reingrese un apellido valido (maximo 50 caracteres)");
                strcpy(aux.apellido,apellido);
                break;
            case 3:
                salario=pedirEntero("Ingrese un nuevo salario: ");
                aux.salario=salario;
                break;
            case 4:
                sector=pedirEntero("Ingrese un nuevo sector: ");
                aux.sector=sector;
                break;
            default:
                printf("Opcion no valida");

            }
            if(retorno==0)
            {
                printf("\nEl empleado a modificar va a quedar de la siguiente manera: ");
                mostrarEmpleado(aux);
                respuesta=pedirCaracter("\nDesea guardas los cambios? presione 's' para guardar");
                if(respuesta=='s')
                {
                    empleados[index]=aux;
                }
                else
                {
                    printf("\nNo se realizo la modificacion");
                    retorno=1;
                }
            }

        }
        else
        {
            retorno=-1;
        }
    }
    else
    {
        retorno=-1;
    }

    return retorno;
}

int borrarEmpleado (eEmpleado* empleados, int tam)
{

    int retorno=-1; //0 si no se pudo borrar, 1 si se pudo borrar
    int index;
    listarEmpleados(empleados,tam);
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

int ordenarEmpleados(eEmpleado* listaDeEmpleados,int tam, int orden)
{
    int retorno;
    eEmpleado aux;
    int i;
    int j;

    if(listaDeEmpleados!=NULL && tam > 0)
    {
        if(orden==1)
        {
            for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(strcmp(listaDeEmpleados[i].apellido, listaDeEmpleados[j].apellido)>0 && listaDeEmpleados[i].estaVacio == OCUPADO && listaDeEmpleados[j].estaVacio==OCUPADO) /** criterio de ordenamiento*/
                    {

                        aux=listaDeEmpleados[i];
                        listaDeEmpleados[i]=listaDeEmpleados[j];
                        listaDeEmpleados[j]=aux;

                    }
                    else if (strcmp(listaDeEmpleados[i].apellido,listaDeEmpleados[j].apellido)==0 && listaDeEmpleados[i].estaVacio == OCUPADO && listaDeEmpleados[j].estaVacio==OCUPADO)
                    {

                        aux=listaDeEmpleados[i];
                        listaDeEmpleados[i]=listaDeEmpleados[j];
                        listaDeEmpleados[j]=aux;


                    }
                }

            }

            retorno=0;
        }
        else if(orden==0)
        {
            for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(strcmp(listaDeEmpleados[i].apellido, listaDeEmpleados[j].apellido)<0 && listaDeEmpleados[i].estaVacio == OCUPADO && listaDeEmpleados[j].estaVacio==OCUPADO) /** criterio de ordenamiento*/
                    {
                        aux=listaDeEmpleados[i];
                        listaDeEmpleados[i]=listaDeEmpleados[j];
                        listaDeEmpleados[j]=aux;

                    }
                    else if (strcmp(listaDeEmpleados[i].apellido,listaDeEmpleados[j].apellido)==0 && listaDeEmpleados[i].estaVacio == OCUPADO && listaDeEmpleados[j].estaVacio==OCUPADO)
                    {
                        aux=listaDeEmpleados[i];
                        listaDeEmpleados[i]=listaDeEmpleados[j];
                        listaDeEmpleados[j]=aux;

                    }

                }
            }
        }
        retorno=0;
    }
    else
    {

        retorno=-1;
    }

    return retorno;

}

