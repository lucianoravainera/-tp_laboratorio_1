#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno=0,numeroDos=0;

        char menuTexto [] = "3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\n";
        char errorTexto [] = "Opcion Invalida.";
        int desde =1,hasta=9;

    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);
        opcion = menu (numeroUno,numeroDos,menuTexto,errorTexto,desde,hasta);
        switch(opcion)
        {
            case 1:
               getFloat(&numeroUno);
                break;
            case 2:;
                getFloat(&numeroDos);
                break;
            case 3:
                suma(numeroUno,numeroDos);
                getch ()!='\n';
                break;
            case 4:
                resta(numeroUno,numeroDos);
                getch ()!='\n';
                break;
            case 5:
                division(numeroUno,numeroDos);
                getch ()!='\n';
                break;
            case 6:
                multiplicacion(numeroUno,numeroDos);
                getch ()!='\n';
                break;
            case 7:
               mostrarFact(numeroUno);
                getch ()!='\n';
                break;
            case 8:
                suma(numeroUno,numeroDos);
                resta(numeroUno,numeroDos);
                division(numeroUno,numeroDos);
                multiplicacion(numeroUno,numeroDos);
                mostrarFact(numeroUno);
                getch ()!='\n';
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;

}
