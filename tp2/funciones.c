#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
/** \brief muestra el menu de opciones
 * \param menuTexto es el texto del menu a ser mostrado
 * \param errorTexto es el mensaje de error a ser mostrado
 * \param desde limite inferior a validar
 * \param hasta limite superior a validar
 * \return return retorna la opcion seleccionada del menu
 */

int menu (char menuTexto[],char errorTexto[],int desde,int hasta)
{
        int respuesta,opcion;
        printf("%s",menuTexto);
        scanf("%d",&opcion);
        if(opcion<=hasta && opcion>=desde)
        {
            respuesta = opcion;
        }
        else
        {
            printf("%s\n",errorTexto);
            system("pause");
        }
    return respuesta;

}
/** \brief Inicializacion inicial de la estructura 0 vacio 1 lleno
 * \param  estructura a inicializar
 * \param  cantidad de estructuras a inicializar
 */
void inicializar(ePersona* persona, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        persona[i].estado=0; //0 = vacio
    }
}
/** \brief Obtiene el primer indice libre del array.
 * \param lista el array
 * \param tamaño del array
 * \return devuelve el primer inidice disponible, caso contrario devuelve un -1.
 */
int espVacio(ePersona* persona, int tam)
{
    int i, aux = -1;

        for(i=0;i<tam;i++)
        {
            if(persona[i].estado==0)
            {
                aux=i;
                break;
            }
        }
        if(aux== -1)
        {
            printf("No se puede ingresar mas personas, espacio lleno.\n");
            system("pause");
        }

    return aux;
}
/** \brief Solicita al usuario los datos a ingresar en la estructura
 * \param Array de estructura
 * \param Posicion del array donde se cargaran los datos
 * \param Tamaño del array de estructura
 */
void agregarPersona(ePersona* persona,char* buffer,int pos,int tam)
{
    int i=0;
    int id;
    int seguir=1;

    if(getString("Ingrese nombre: ",buffer, 50))
    {
        strcpy(persona[pos].nombre,buffer);
    }
    else { seguir=0; }

    system("cls");
    fflush(stdin);

    if(seguir==1)
    {
        if(getInt("Ingrese DNI: ",buffer,1000,99999999))
        {
            persona[pos].dni= atoi(buffer);
        }
        else { seguir=0; }
    }
    system("cls");
    fflush(stdin);

    if(seguir==1)
    {
        if(getInt("Ingrese edad: ",buffer,1,100))
        {
            persona[pos].edad = atoi(buffer);
        }
        else { seguir=0; }
    }

    system("cls");
    if(seguir==1)
    {
        persona[pos].estado = 1; //pongo estado lleno el array.
    }
    return seguir;
}
/**
 * Valida un dato entero.
 * param mensaje para mostrar.
 * param buffer auxiliar donde ingresa el usuario.
 * param opcion minimo del menu.
 * param opcion maxima del menu.
 * return entero ingresado ingresada
 */
int getInt(char mensaje[],char buffer[],int minimo, int maximo)
{
    int retorno=0;
    char seguir='s';
    int auxiliar;
    do
    {   fflush(stdin);
        printf("%s",mensaje);
        gets(buffer);
        if(esNumerico(buffer))
        {
            auxiliar=atoi(buffer);
            if(verificarRangoInt(auxiliar, minimo, maximo))
            {
                retorno=1;
                seguir='n';
            }
            else
            {
                printf("Desea continuar?s/n: ");
                gets(&seguir);
            }
        }
        else
        {
            printf("Dato ingresado incorrecto. Desea continuar? s/n: ");
            gets(&seguir);
        }
    }
    while(seguir=='s');

    return retorno;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 0 si esta mal 1 si esta bien
 */
int getString(char mensaje[],char buffer[], int longitud)
{
    char seguir='s';
    int retorno=0;

    do
    {
        system("cls");
        printf("%s", mensaje);
        scanf ("%s", buffer);
        if(strlen(buffer) <= longitud && isalpha(buffer)!= 0)
        {
            retorno=1;
            seguir='n';
        }
        else
        {
            printf("Dato ingresado incorrecto. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }
    while(seguir=='s');

    return retorno;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica el rango de un entero
 * \param dato a examinar
 * \param minimo del rango a examinar
 * \param maximo del dato a examinar
 * \return 1 si es correcto y 0 si no es correcto
 */
int verificarRangoInt(int auxiliar, int minimo, int maximo)
{
    char seguir='s';
    int retorno=0;

        if(auxiliar>=minimo && auxiliar<=maximo)
        {
            retorno=1;
            seguir = 'n';
        }
        else
        {
            printf("Dato ingresado fuera del rango.");
        }
    return retorno;
}
/**
 * \brief Da de baja a una persona
 * \param array de estructura
 * \param valor de baja
 * \param cantidad de estructuras
 * \param cabuffer de datos
 */
void eliminar (ePersona* persona,int baja, int CANT,char* buffer[])
{
    int idAbonado = 0,pos=0;
    listar (persona,CANT);
                    if(getInt("Ingrese el DNI de la persona al que desea eliminar: ",buffer,1,99999999))
                    {
                        idAbonado=atoi(buffer);
                        pos = buscarId (persona, CANT, idAbonado);
                        if(pos >= 0)
                        {
                            system("cls");
                            persona[pos].estado=baja;
                            printf("Persona eliminada con exito!!\n");
                            system("pause");
                        }
                    }
                    else {
                        printf("error al eliminar\n");
                        system("pause");
                        }
}
/**
 * \brief Lista los usuarios cargados
 * \param array de estructura
 * \param Cantidad de estructuras
 */
void listar (ePersona* persona, int C)
{
    int i;
    printf("Nombre     Edad     DNI\n");
    for(i=0;i<C;i++)
    {
        if(persona[i].estado==1)
            printf("%s     %d     %d    \n",persona[i].nombre, persona[i].edad, persona[i].dni);
    }
}
/**
 * \brief busca un dato en las estructuras
 * \param estructura a buscar
 * \param cantidad de estructuras
 * \param dato a buscar en las estructuras
 * \return devuelve la posicion del array donde encontro el dato, sino devuelve -1.
 */
int buscarId (ePersona* persona,int CANT,int idAbonado)
{
    int i=0;
    int pos=-1;
    for(i=0;i<CANT;i++)
    {
        if(persona[i].estado==1 && idAbonado==persona[i].dni)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        printf("El DNI ingresado no corresponde a una persona.\n");
        system("pause");
    }

    return pos;
}
/** \brief ordena los nombres alfabeticamente y los mustra en pantalla
 * \param array de estructura.
 * \param tamaño del array
 * \return retorna -1 si hay error o 0 si se realizo el swap
 */
int ordenarNombre(ePersona* persona,int tam)
{
    ePersona aux;
    int i;
    int j;
    int ret=-1;
    if (persona != NULL  && tam > 0)
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(stricmp(persona[i].nombre,persona[j].nombre) >0)
                {
                    aux=persona[i];
                    persona[i]=persona[j];
                    persona[j]=aux;
                }
            }
        }
        ret=0;
    }
    printf("Nombre     Edad     DNI\n");
    for(i=0;i<tam;i++)
    {
        if(persona[i].estado==1)
            printf("%s     %d     %d    \n",persona[i].nombre, persona[i].edad, persona[i].dni);
    }
    return ret;
}
/** \brief Genera un grafico de barras.
 *
 * \param rango de edaddes <18
 * \param rango de edaddes entre 19 y 35
 * \param rango de edaddes >35
 *
 */
void grafico(int hasta18,int de19a35,int mayorDe35)
{
int i, flag=0, mayor;

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
    system("pause");

}
/** \brief cuenta la cantidad de estructuras con el rango de edades a buscar
 * \param array a examinar
 * \param tamaño de la estructura
 * \param rango minimo a evaluar
 * \param rango maximo a evaluar
 * \return retorna la cantidad encontrada
 *
 */
int contador(ePersona* persona, int c, int min, int max)
{
    int i;
    int cont=0;

        for(i=0;i<c;i++)
        {
            if(persona[i].estado==1 && (persona[i].edad>=min && persona[i].edad<=max))
            {
                cont++;
            }
        }

    return cont;
}
