#include <stdio.h>
#include <stdlib.h>
#include "../../../pila.h"

int main()
{
    Pila calificaciones;
    inicpila (&calificaciones);

    /**Ejercicio 1*/
    int respuesta = 1;
    int contador = 1;

    printf("Como queres ingresar las calificaciones? \n 1(manual)     /        0(automatico)");
    fflush(stdin);
    scanf("%d", &respuesta);

    if(respuesta==1){
        while(contador == 3)
        {
            leer(&calificaciones);
            if(tope(&calificaciones)<=10 && tope(&calificaciones)>0)
            {
                contador += 1;
            }
            else
            {
                printf("ingresa una nota mayor a 0 y menor o igual a 10");
                desapilar(&calificaciones);
            }
        }
    }
    else
    {
        printf("a");
    }
    return 0;
}
