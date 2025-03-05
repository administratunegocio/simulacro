#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila calificaciones;
    inicpila (&calificaciones);

    /**Ejercicio 1: ingresar*/
    int respuesta = 1;
    int contador = 1;


    printf("Como queres ingresar las calificaciones? \n 1(manual)     /        0(automatico)");
    fflush(stdin);
    scanf("%i", &respuesta);

    if(respuesta==1){
        while(contador <= 20)
        {
            leer(&calificaciones);
            if(tope(&calificaciones)<=10 && tope(&calificaciones)>0)
            {
                contador += 1;

            }
            else
            {
                printf("ingresa una nota mayor a 0 y menor o igual a 10 \n");
                desapilar(&calificaciones);
                /** mostrar(&calificaciones); verificacion de < o >*/
            }
        }
    }
    else
    {
        /** automatico */
    }


    /**ejercicio 2: promedios*/
    Pila aux_promedio;
    inicpila (&aux_promedio);

    int suma = 0;

    while(!pilavacia(&calificaciones)){
        suma += tope(&calificaciones);
        apilar(&aux_promedio, desapilar(&calificaciones));
    }



    float promedio = suma/20;
    printf("Promedio de notas = %f \n", promedio);

    while(!pilavacia(&aux_promedio)){
        apilar(&calificaciones, desapilar(&aux_promedio));
    }

    /** ejercicio 3: calificacion mas alta y mas baja */

    Pila aux_baja_alta;
    inicpila (&aux_baja_alta);
    int baja = 11;
    int alta = 0;


    /**mas baja*/
    while(!pilavacia(&calificaciones)){
        if(baja<tope(&calificaciones)){
            baja = baja;
            apilar(&aux_baja_alta, desapilar(&calificaciones));
        }
        else{
            baja = tope(&calificaciones);
            apilar(&aux_baja_alta, desapilar(&calificaciones));
        }
    }

    printf("Nota mas baja = %d \n", baja);
    while(!pilavacia(&aux_baja_alta)){
        apilar(&calificaciones, desapilar(&aux_baja_alta));
    }


    /**mas alta*/

    while(!pilavacia(&calificaciones)){
        if(alta>tope(&calificaciones)){
            alta = alta;
            apilar(&aux_baja_alta, desapilar(&calificaciones));
        }
        else{
            alta = tope(&calificaciones);
            apilar(&aux_baja_alta, desapilar(&calificaciones));
        }
    }

    printf("Nota mas alta = %d \n", alta);
    while(!pilavacia(&aux_baja_alta)){
        apilar(&calificaciones, desapilar(&aux_baja_alta));
    }



    /**ejercicio 4: aprobados y desaprobados*/
    Pila aprobados;
    Pila desaprobados;

    inicpila (&aprobados);
    inicpila (&desaprobados);

    int aprobados_n = 0;
    int desaprobados_n = 0;

    while(!pilavacia(&calificaciones)){
        if(tope(&calificaciones)>=6){
            aprobados_n += 1;
            apilar(&aprobados, desapilar(&calificaciones));
        }
        else{
            desaprobados_n += 1;
            apilar(&desaprobados, desapilar(&calificaciones));
        }
    }

    /** printf("Aprobaron: %d \n Desaprobaron: %d \n", aprobados_n, desaprobados_n); chequeo si realmente funciona*/


    /** ejercicio 5: operaciones */
    /** porcentaje */
    int porcentaje_aprobados = (aprobados_n*100)/20;
    int porcentaje_desaprobados = (desaprobados_n*100)/20;

    printf("Porcentaje aprobado = %d \n", porcentaje_aprobados);
    printf("Porcentaje desaprobado = %d \n", porcentaje_desaprobados);


    /** busqueda */
    int nota_buscada = 0;
    int encontrada = 0;
    int rta = 0;


    do
    {
        printf("Que nota quiere buscar? Recuerde que es entre 1 y 10 \n");
        fflush(stdin);
        scanf("%d", &nota_buscada);

        if(nota_buscada >=6){
            while(!pilavacia(&aprobados)){
                if(nota_buscada == tope(&aprobados)){
                    encontrada += 1;
                    apilar(&calificaciones, desapilar(&aprobados));

                }
                else
                {
                    encontrada += 0;
                    apilar(&calificaciones, desapilar(&aprobados));
                }
            }
        }
        else{
            while(!pilavacia(&desaprobados)){
                    if(nota_buscada == tope(&desaprobados)){
                        encontrada += 1;
                        apilar(&calificaciones, desapilar(&desaprobados));

                    }
                    else
                    {
                        encontrada += 0;
                        apilar(&calificaciones, desapilar(&desaprobados));
                    }
                }
        }

        if(pilavacia(&aprobados)){
            while(!pilavacia(&calificaciones)){
            apilar(&aprobados, desapilar(&calificaciones));
            }
        }else{
            while(!pilavacia(&calificaciones)){
                apilar(&desaprobados, desapilar(&calificaciones));
                }
        }

        /** */
        if(encontrada>0){
            printf("Se encontro %d veces \n", encontrada);
            rta = 0;
        }
        else{

                printf("No se encontro la nota \n Queres buscar otra? \n 1(si) // 0(no)");
                scanf("%d", &rta);

        }
    }while(rta==1);



    return 0;
}
