#include "prototipos.h"
int main()
{
    int opcion;
    float numero1=0;
    float numero2=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float factorialNumero1;
    float factorialNumero2;
    int flag=0; /** Bandera utilizada como validacion de ingreso de numeros  */
    do
    {
        if(flag==0)
        {
            printf("1. Ingresar el primer numero:(A = x) \n2. Ingresar el segundo numero: (B = y)\n3. Calcular todas las operaciones (suma, resta, multiplicacion, division y factorial)\n4. Mostrar resultados\n5. Salir\nSeleccione una opcion.\n");
        }
        else if(flag==1)
        {
            if(numero2==0)
            {
                printf("1. Ingresar el primer numero: (A = %.2f)\n2. Ingresar el segundo numero: (B = y)\n3. Calcular todas las operaciones (suma, resta, multiplicacion, division y factorial)\n4. Mostrar resultados\n5. Salir\nSeleccione una opcion.\n",numero1);
            }
            else
            {
                printf("1. Ingresar el primer numero: (A = %.2f)\n2. Ingresar el segundo numero: (B = %.2f)\n3. Calcular todas las operaciones (suma, resta, multiplicacion, division y factorial)\n4. Mostrar resultados\n5. Salir\nSeleccione una opcion.\n",numero1,numero2);
            }
        }
        else if(flag>=2)
        {
            if(numero1==0)
            {
                printf("1. Ingresar el primer numero:(A = x) \n2. Ingresar el segundo numero:(B = %.2f) \n3. Calcular todas las operaciones (suma, resta, multiplicacion, division y factorial)\n4. Mostrar resultados\n5. Salir\nSeleccione una opcion.\n",numero2);
            }
            else
            {
                printf("1. Ingresar el primer numero:(A = %.2f) \n2. Ingresar el segundo numero:(B = %.2f) \n3. Calcular todas las operaciones (suma, resta, multiplicacion, division y factorial)\n4. Mostrar resultados\n5. Salir\nSeleccione una opcion.\n",numero1,numero2);
            }
        }
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            system("cls");
            numero1= pedirNumero("Ingrese el primer numero\n");
            flag=1;

            break;
        case 2:
            numero2=pedirNumero("Ingrese el segundo numero\n");
            flag=2;
            break;

        case 3:
            if(flag!=0)
            {
                printf("Se realizaran las siguientes operaciones: suma, resta, multiplicacion, division y factorial\n");
                resultadoSuma=sumar(numero1,numero2);
                resultadoResta=restar(numero1,numero2);
                resultadoMultiplicacion=multiplicar(numero1,numero2);
                resultadoDivision=dividir(numero1,numero2);
                factorialNumero1=factorial(numero1);
                factorialNumero2=factorial(numero2);
                flag=3;
            }
            else
            {
                printf("No se han introducido numeros para poder realizar operaciones\n");
            }
            break;
        case 4:
            if(flag==3)
            {
                printf("El resultado de la suma entre:  %.2f y %.2f es: %.2f\n",numero1,numero2,resultadoSuma);
                printf("El resultado de la resta entre: %.2f y %.2f es: %.2f\n",numero1,numero2,resultadoResta);
                printf("El resultado de la Multiplicacion entre: %.2f y %.2f es: %.2f\n",numero1,numero2,resultadoMultiplicacion);
                if(numero2==0)
                {
                    printf("Error. no se puede dividir por 0, por favor ingrese otro numero en la opcion 2");
                }
                else
                {
                    printf("El resultado de la Division entre: %.2f y %.2f es: %.2f\n",numero1,numero2,resultadoDivision);
                }
                if(numero1>=0 && numero2>=0)
                {
                    printf("El factorial de %.2f es %.2f y el factorial de %.2f es: %.2f\n",numero1,factorialNumero1,numero2,factorialNumero2);

                }
                else if(numero1>=0 && numero2<0)
                {
                    printf("El factorial de %.2f es %.2f.\nERROR. no se puede calcular el factorial de  numeros negativos (el segundo numero  = %.2f)",numero1,factorialNumero1,numero2);

                }
                else if(numero1<0 && numero2>=0)
                {
                    printf("El factorial de %.2f es %.2f.\nERROR. no se puede calcular el factorial de  numeros negativos (el primer numero = %.2f)",numero2,factorialNumero2,numero1);
                }
                else if(numero1<0 && numero2<0)
                {
                    printf("ERROR. No se puede calcular el factorial de numeros negativos. (El primer numero = %.2f -- El segundo numero = %.2f\n)",numero1,numero2);
                }
            }
            else
            {
                printf("No se han introducido numeros para poder realizar operaciones\n");
            }

            break;
        case 5:
            printf("Saliendo...\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion !=5);

    return 0;
}


