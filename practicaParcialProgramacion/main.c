#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int aplicarAumento(int valor);


typedef struct {
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

int ordenarVacunas(eVacuna lista[], int tam);

//1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto y devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main. *
//3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura por tipo. Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main. *

int main()
{
    eVacuna lista[TAM] = {
    {5000, "vacuna1", 's', 30.40,},
    {5001, "vacuna2", 'a', 20.30},
    {5002, "vacuna3", 'a', 36.80},
    {5003, "vacuna4", 'f',90.90},
    {5004, "vacuna4", 'f',98.9}
    };
    int aumento;
    int precioOriginal = 1000;
    aumento = aplicarAumento(precioOriginal);
    printf("El precio con aumento es %d \n" , aumento);

    for(int i = 0; i< TAM; i++)
    {
        printf("  %d  %10s       %c      %2f\n", lista[i].id , lista[i].nombre, lista[i].tipo, lista[i].efectividad);
    }

    ordenarVacunas(lista, TAM);

    printf("\n\n");

    for(int i = 0; i< TAM; i++)
    {
        printf("  %d  %10s       %c      %2f\n", lista[i].id , lista[i].nombre, lista[i].tipo, lista[i].efectividad);
    }

    return 0;
}

int aplicarAumento(int valor){
int retorno;

retorno = valor +(valor * 5/100);

return retorno;
}

int ordenarVacunas(eVacuna lista[], int tam)
{
    int todoOk = 0;
    eVacuna auxVacuna;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i+1; j< tam; j++)
            {
                if((lista[i].tipo > lista[j].tipo) || (lista[i].tipo == lista[j].tipo && lista[i].efectividad < lista[j].efectividad))
                {
                    auxVacuna = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxVacuna;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
