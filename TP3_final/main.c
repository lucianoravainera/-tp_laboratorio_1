#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 5

int main()
{
    char seguir='s';
    int opcion=0;
    eMovie datos[CANT];
    inicializar(datos,CANT);
    cargarArchivo(datos,CANT);

    while(seguir=='s')
    {
        opcion = menu("TP3 Peliculas\n1- Agregar pelicula\n2- Modificar pelicula\n3- Borrar pelicula\n4- Generar pagina web\n5- Salir\n","Error ingrese nuevamente una opcion entre 1 y 4: ");

        switch(opcion)
        {
        case 1:
           if(ingresar(datos,CANT))
                {
                    system("cls");
                    puts("Pelicula cargada!");
                }
            else
            {
                printf("No hay mas lugar disponible\n");
            }
            break;
        case 2:
            system("cls");
            modificar(datos,CANT);
            break;
        case 3:
            system("cls");
            if(deleteMovie(datos,CANT)==1)
            {
                system("cls");
                puts("Pelicula eliminada");
            }
            break;
        case 4:
            guardar(datos,CANT);
            generarPagina(datos,CANT);
            break;
        case 5:
            guardar(datos,CANT);
            seguir = 'n';
            break;
        }
    }

    return 0;
}
