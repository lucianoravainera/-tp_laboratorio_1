#include "funciones.h"

/** \brief muestra el menu de opciones
 * \param numeroUno es el valor del primer operando para mostrar en el menu
 * \param numeroDos es el valor del segundo operando para mostrar en el menu
 * \param menuTexto es el texto del menu a ser mostrado
 * \param errorTexto es el mensaje de error a ser mostrado
 * \param desde limite inferior a validar
 * \param hasta limite superior a validar
 * \return return retorna la opcion seleccionada del menu
 */

int menu (float numeroUno,float numeroDos ,char menuTexto[],char errorTexto[],int desde,int hasta)
{
        int respuesta,opcion;
        printf("1- Ingresar 1er operando (A= %.2f)\n2- Ingresar 2do operando (B= %.2f)\n",numeroUno,numeroDos);
        printf("%s",menuTexto);
        scanf("%d",&opcion);
        if(opcion<=hasta && opcion>=desde)
        {
            respuesta = opcion;
        }
        else {
        printf("%s",errorTexto);
        getch ()!='\n';
        }
    return respuesta;

}

/**
* \brief Solicita un numero flotante al usuario y lo valida
* \param numero Se carga el numero ingresado
*
*/

void getFloat(float* numero)
{
    float auxiliar;
    int scanfNumero;
    printf("Ingrese el Operando:");
    scanfNumero =scanf("%f",&auxiliar);
    if(scanfNumero==0)
        {
        printf("Dato Inavlido\n");
        getch ()!='\n';
        }
    else {
        *numero=auxiliar;
        //return 0;
        }
}

/** \brief toma dos numeros y los suma
 * \param numerouno toma el primer numero
 * \param numeroDos toma el segundo numero
 */

void suma (float numerouno,float numeroDos)
{
    float resultadoSuma;
    resultadoSuma = numerouno + numeroDos;
    printf("El resultado de la suma es: %f\n",resultadoSuma);
}

/** \brief toma dos numeros y los resta
 * \param numerouno toma el primer numero
 * \param numeroDos toma el segundo numero
 */

void resta (float numerouno,float numeroDos)
{
  float resultadoResta;
  resultadoResta = numerouno - numeroDos;
  printf("El resultado de la resta es: %f\n",resultadoResta);
}

/** \brief toma dos numeros y los divide
 * \param numerouno toma el primer numero
 * \param numeroDos toma el segundo numero
 */

void division (float numerouno,float numeroDos)
{
    float resultadoDivision;
        if(numeroDos==0)
        {
            resultadoDivision = -1;
            printf("no se puede dividir por 0.");
        }
        else
        {
        resultadoDivision = numerouno/numeroDos;
        }
        printf("el resultado de la division es: %f\n",resultadoDivision);
    //return resultadoDivision;
}

/** \brief toma dos numeros y los multiplica
 * \param numerouno toma el primer numero
 * \param numeroDos toma el segundo numero
 */

void multiplicacion (float numerouno,float numeroDos)
{
    float resultadoMultiplicacion;
    resultadoMultiplicacion = numerouno * numeroDos;
    printf("El resultado de la multiplicacion es: %f\n",resultadoMultiplicacion);
}

/** \brief toma un numero y saca su factorial
 * \param numerouno toma el numero
 * \return devuelve el resultado de la operacion factorial
 *
 */


int factorial (int numerouno)
    {
    int resultadoFactorial;

    if(numerouno==0)  //por definicion el factorial de 0 es 1
        {
        resultadoFactorial = 1;
        }
        else{
    resultadoFactorial = numerouno * factorial(numerouno-1);
        }

    return resultadoFactorial;

    }

/** \brief toma un numero, lo envia a la funcion factorial y muestra el resultado
 * \param numerouno numero a calcular
 */


void mostrarFact (int numerouno)
{
  int resultadoFactoriala =factorial(numerouno);
  printf("El factorial del primer operando es: %d\n",resultadoFactoriala);

}
