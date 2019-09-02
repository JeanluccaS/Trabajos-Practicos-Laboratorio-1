#include "prototipos.h"

int sumar (int numero1, int numero2)
{
    int resultado;
    resultado=numero1 + numero2;

    return resultado;
}
int restar(int numero1, int numero2)
{
    int resultado;
    resultado=numero1 - numero2;

    return resultado;
}
int multiplicar(int numero1, int numero2)
{
    int resultado;
    resultado=numero1 * numero2;

    return resultado;
}
int dividir (int numero1, int numero2)
{
    int resultado;
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
