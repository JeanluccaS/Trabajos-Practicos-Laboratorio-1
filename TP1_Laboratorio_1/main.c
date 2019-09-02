#include "prototipos.h"
int main()
{
   int opcion;
   int numero1=0;
   int numero2=0;
   int resultadoSuma;
   int resultadoResta;
   int resultadoMultiplicacion;
   int resultadoDivision;

    do{
        printf("\n1. Ingresar el primer numero: \n2. Ingresar el segundo numero: \n3.Calcular todas las operaciones (suma, resta, multiplicacion, division)\n4. Mostrar resultados\n5. Salir\n Seleccione una opcion. \n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                numero1= pedirNumero("Ingrese el primer numero\n");
                printf("%d",numero1);
                break;
            case 2:
                numero2=pedirNumero("Ingrese el segundo numero\n");
                printf("\n%d",numero2);
            case 3:
                printf("Se realizaran las siguientes operaciones: suma, resta, multiplicacion y division.\n");
                resultadoSuma=sumar(numero1,numero2);
                resultadoResta=restar(numero1,numero2);
                resultadoMultiplicacion=multiplicar(numero1,numero2);
                resultadoDivision=dividir(numero1,numero2);
                break;
            case 4:
                printf("El resultado de la suma entre:  %d y %d es: %d",numero1,numero2,resultadoSuma);
                printf("El resultado de la resta entre: %d y %d es: %d",numero1,numero2,resultadoResta);
                printf("El resultado de la Multiplicacion entre: %d y %d es: %d",numero1,numero2,resultadoMultiplicacion);
                printf("El resultado de la Division entre: %d y %d es: %d",numero1,numero2,resultadoDivision);
                break;
            case 5:
                printf("Saliendo...");
                break;




        }







    }while(opcion !=5);




    return 0;
}


