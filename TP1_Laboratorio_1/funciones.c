#include "prototipos.h"

float sumar (float numero1, float numero2)
{
    float resultado;
    resultado=numero1 + numero2;

    return resultado;
}
float restar(float numero1, float numero2)
{
    float resultado;
    resultado=(float)numero1 - (float)numero2;

    return resultado;
}
float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1 * numero2;

    return resultado;
}
float dividir (float numero1, float numero2)
{
    float resultado;
    resultado=numero1 / numero2;

    return resultado;
}

float pedirNumero(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}

int factorial(int numero)
{
    int resultado=1;
    int i;
    for(i=numero;i>=1;i--)
    {
        resultado=resultado*i;
    }


    return resultado;


}
