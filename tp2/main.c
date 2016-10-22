#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <conio.h>
#define TAM 20
#define BAJA 0
#define ALTA 1
int main()
{
    char seguir='s';
    int opcion=0, aux;
    char menuTexto [] = "Estructura persona:Ravainera\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir\n";
    char errorTexto [] = "Opcion Invalida.";
    char buffer[500];
    int desde =1,hasta=5; //menu
    ePersona persona[TAM];

    inicializar(persona, TAM); // estado inicial
    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);
        opcion = menu (menuTexto,errorTexto,desde,hasta);
        switch(opcion)
        {
            case 1:// agregar una persona
                aux = espVacio(persona, TAM);
                if(aux != -1)
                {
                    if(agregarPersona(persona,&buffer,aux,TAM) == -1)
                    {
                        printf("Error al agregar persona\n");
                        system("pause");
                    }
                }
                break;
            case 2:// Baja de una persona
                system("cls");
                eliminar (persona,BAJA,TAM,&buffer);
                break;
            case 3: // imprimir listado ordenado por nombre
                system("cls");
                printf("Listado de personas ordenadas por nombre:\n");
                ordenarNombre(persona,TAM);
                system("pause");
                break;
            case 4: // inprimir grafico
                system("cls");
                grafico(contador(persona,TAM,1,18),contador(persona,TAM,19,35),contador(persona,TAM,36,100));
                break;
            case 5: // salir
                seguir = 'n';
                break;
        }
    }

    return 0;
}
