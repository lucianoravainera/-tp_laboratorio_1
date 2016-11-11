#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 3

void inicializar(eMovie* movie,int length)
{
   int retorno=1,i;
    if(movie == NULL || length < 1)
    {
        retorno=0;
        printf("Error al inicializar");
        system("pause");
    }
    else
    {
        for(i=0; i<length ; i++)
        {
            movie[i].estado = 0;
        }
    }
    return retorno;
}

int cargarArchivo(eMovie* movie, int length)
{
    FILE* fp;
	int i=0, retorno=0;
	fp = fopen("bin.dat", "rb");
	if(fp==NULL)
    {
        retorno=-1;
	}
	if(retorno!=-1)
	{
	    while(!feof(fp))
        {
            fread(&movie[i], sizeof(eMovie), 1,fp);
                i++;
        }
        fclose(fp);
	}

	return retorno;
}

int menu(char mensaje[],char error[])
{
    int op,aux;
    printf("%s",mensaje);
    aux=scanf("%d",&op);
    fflush(stdin);
    while(aux==0 ||(op<1||op>5))
    {
        printf("%s",error);
        fflush(stdin);
        aux=scanf("%d",&op);
    }
    return op;
}
int ingresar(eMovie* movie,int length)
{
    int retorno = 1;
    eMovie aux;
    int ind;
    if(movie == NULL || length< 1)
    {
        retorno = 0;
    }
    if(retorno)
    {
        ind = BuscarID(movie,length,0);
        if(ind == -1)
        {
            printf("Archivo lleno.\n");
            retorno=0;
        }
    }
    if(retorno)
    {
        if(!getTitle(movie,length,0,aux.titulo))
        retorno=0;
    }
    if(retorno)
    {
        if(!getGenero(movie,length,aux.genero))
            retorno=0;
    }
    if(retorno)
    {
        if(!GetDesc(movie,length,0,aux.descripcion))
            retorno=0;
    }
    if(retorno)
    {
        if(!GetLink(movie,length,aux.linkImagen))
            retorno=0;
    }
    if(retorno)
    {
        if(!getTime(movie,length,0,&aux.duracion))
            retorno=0;
    }
    if(retorno)
    {
        if(!getPuntaje(movie,length,&aux.puntaje))
            retorno=0;
        else
        {
            strcpy(movie[ind].descripcion,aux.descripcion);
            strcpy(movie[ind].titulo,aux.titulo);
            strcpy(movie[ind].genero,aux.genero);
            strcpy(movie[ind].linkImagen,aux.linkImagen);
            movie[ind].duracion=aux.duracion;
            movie[ind].puntaje=aux.puntaje;
            movie[ind].estado=1;
        }
    }
    return retorno;
}

int BuscarID(eMovie* movie,int length,int valor)
{
    int i;
    int retorno=-1;
    for(i=0; i<length; i++)
    {
        if(movie[i].estado == valor)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void getString (char message[],char entrada[])
{
    puts(message);
    fflush(stdin);
    gets(entrada);
}

int getCharP(char ingreso[],int limite)
{
   int i=0;
   int ret=1;
   int longitud=strlen(ingreso);
   if(ret)
   {
        while(ingreso[i] != '\0' || longitud==0)
        {
           if((longitud>limite)||((ingreso[i] != ' ') && (ingreso[i] < 'a' || ingreso[i] > 'z') && (ingreso[i] < 'A' || ingreso[i] > 'Z')))
            {
                ret= 0;
                break;
            }
            i++;
        }
   }
   return ret;
}

int esAlfaNumerico(char str[],int limite)
{
   int i=0;
   int ret=1,largo;
   largo=strlen(str);
   while(str[i] != '\0' || largo==0)
   {
       if(largo>limite||((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')))
        {
            ret= 0;
            break;
        }
       i++;
   }
   return ret;
}

int esNumeroNatural(char numeros[],int limite)
{
    int i=0;
    int ret=1;
    int cantidad = strlen(numeros);
    if(ret)
    {
        while(numeros[i] != '\0'|| cantidad==0)
        {
            if((cantidad>limite)||(numeros[i] < '0' || numeros[i] > '9'))
            {
                ret= 0;
                break;
            }
            i++;
        }
    }
    return ret;
}

int valInt(int x,int desde,int hasta)
{
    int ret=1;
    if(x<desde||x>hasta)
    {
        ret=0;
    }
    return ret;
}

char reingresar(char eMensaje[],char pregunta[])
{
    char retorno;
    puts(eMensaje);
    puts(pregunta);
    retorno=getche();
    printf("\n");
    retorno=tolower(retorno);
    return retorno;
}

int getTitle(eMovie* movie,int longitud,int vacio, char input[])
{
    int retorno=1;

    system("cls");
    getString("Ingrese el Titulo de la pelicula",input);
    while(strlen(input)>20)
    {
        system("cls");
        if(reingresar("Error. debe contener solo 20 caracteres","Desea reingresar titulo? s/n\n")=='s')
        {
            system("cls");
            getString("Reingresar titulo:\n",input);
        }
        else
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int getGenero(eMovie* movie,int longitud, char input[])
{
    int retorno=1;
    if(movie==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        system("cls");
        getString("Ingresar genero",input);
        while(!getCharP(input,20))
        {
            if(reingresar("Error","Desea reingresar titulo? s/n\n")=='s')
            {
                system("cls");
                getString("Reingresar genero:",input);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
    }
    return retorno;
}

int GetLink(eMovie* movie,int longitud, char input[])
{
    int retorno=1;
    if(movie==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        system("cls");
        getString("Ingrese link de imagen de pelicula",input);
        while(strlen(input)>100||strlen(input)<1)
        {
            if(reingresar("Error","Desea reingresar titulo? s/n\n")=='s')
            {
                system("cls");
                getString("Reingressar link",input);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
    }
    return retorno;
}

int getTime(eMovie* movie,int longitud,int vacio,int* input)
{
    int retorno=1;
    char aux[256];
    if(movie==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        getString("Ingresar duracion de la pelicula ",aux);
        while(!esNumeroNatural(aux,3))
        {
            system("cls");
            if(reingresar("Error","Desea reingresar titulo? s/n\n")=='s')
            {
                getString("Ingresar duracion de la pelicula",aux);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
        if(esNumeroNatural(aux,3))
        *input=atoi(aux);
    }
    return retorno;
}

int GetDesc(eMovie* movie,int longitud,int vacio, char input[])
{
    int retorno=1;
    system("cls");
    getString("Ingrese descripcion:",input);
    while(strlen(input) > 300)
    {
        system("cls");
        if(reingresar("Error, debe tener solo 300 caracteres","Desea reingresar titulo? s/n\n")=='s')
        {
            system("cls");
            getString("Reingresar descripcion\n",input);
        }
        else
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}


int getPuntaje(eMovie* movie, int longitud, int* input)
{
    int retorno=1;
    char aux[256];
    if(movie==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        system("cls");
        getString("Ingrese puntaje:",aux);
        while(!esNumeroNatural(aux,2)||!valInt(atoi(aux),1,10))
        {
            system("cls");
            if(reingresar("Error puntaje es del 1 al 10","Desea reingresar titulo? s/n\n")=='s')
            {
                getString("Reingresar puntaje",aux);
            }
            else
            {
                system("cls");
                retorno=0;
            }
        }
        if((esNumeroNatural(aux,2))&&(valInt(atoi(aux),1,10)))
        *input=atoi(aux);
    }
    return retorno;
}

int mostrarTitulos(eMovie* movie, int longitud, int ocupado)
{
    int i;
    int retorno=1;
    if(movie==NULL||longitud<1)
    {
        retorno=0;
    }
    if(retorno)
    {
        for(i=0;i<longitud;i++)
        {
            if(movie[i].estado==ocupado)
            {
                printf("%d)- Titulo : %s\n",movie[i].id,movie[i].titulo);
            }
        }
    }
    return retorno;
}

int actualizarId(eMovie* movie,int longitud)
{
    int i,j;
    int retorno=1;
    if(movie==NULL||longitud<1)
    {
        retorno=0;
    }
    else
    {
        for(i=0,j=1;i<longitud;i++)
        {
            if(movie[i].estado==1)
            {
                movie[i].id=j;
                j++;
            }
        }
    }
    return retorno;
}

int deleteMovie(eMovie* movie, int longitud)
{
    int retorno=1;
    int indice;
    if(retorno)
    {
        indice=BuscarID(movie,longitud,1);
        if(indice==-1)
        {
            printf("No hay peliculas.");
            retorno=0;
        }
    }
    if(retorno)
    {
        actualizarId(movie,longitud);
        indice=idValido(movie,longitud);
        if(indice==-1)  retorno=0;
    }
    if(retorno)
    {
        if(reingresar("Esta seguro?","s/n")=='s')
        {
            movie[indice].estado=0;
        }
    }

    return retorno;
}

int buscarPorId(eMovie* movie, int longitud, int id)
{
    int i;
    int retorno;

        retorno=-1;
        for(i=0;i<longitud;i++)
        {
            if(movie[i].estado==0) continue;
            if(movie[i].id==id)
            {
                retorno=i;
            }
        }

    return retorno;
}

int idValido(eMovie* movie, int longitud)
{
    char aux[256];

        mostrarTitulos(movie,longitud,1);
        getString("Ingrese id",aux);
        while(!esNumeroNatural(aux,10)||(buscarPorId(movie,longitud,atoi(aux))==-1))
        {
            if(reingresar("error","Desesa continuar? S/N")=='s')
            {
                mostrarTitulos(movie,longitud,1);
                getString("Reingrese el numero que acompaña al titulo de la pelicula por favor",aux);
            }
            else
            {
                break;
            }
        }

    return buscarPorId(movie,longitud,atoi(aux));
}

int modificar(eMovie* movie, int longitud)
{
    int retorno=1;
    int indice;
    eMovie auxiliar;
    if(movie==NULL||longitud<1)
    {
        puts("Error.");
        retorno=0;
    }
    if(retorno)
    {
        indice=BuscarID(movie,longitud,1);
        if(indice==-1)
        {
            printf("No hay peliculas");
            retorno=0;
        }
    }
    if(retorno)
    {
        actualizarId(movie,longitud);
        indice=idValido(movie,longitud);
        if(indice==-1)  retorno=0;
    }
    if(retorno)
    {
        printf("Pelicula a modificar: %s",movie[indice].titulo);
        if(reingresar("continuar?","s/n")=='s')
        {
                    if(!getTitle(movie,longitud,0,auxiliar.titulo))
                    retorno=0;
                    if(retorno)
                    {
                        if(!getGenero(movie,longitud,auxiliar.genero))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!GetDesc(movie,longitud,0,auxiliar.descripcion))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!getTime(movie,longitud,0,&auxiliar.duracion))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!GetLink(movie,longitud,auxiliar.linkImagen))
                            retorno=0;
                    }
                    if(retorno)
                    {
                        if(!getPuntaje(movie,longitud,&auxiliar.puntaje))
                            retorno=0;
                        else
                        {
                            strcpy(movie[indice].descripcion,auxiliar.descripcion);
                            strcpy(movie[indice].titulo,auxiliar.titulo);
                            strcpy(movie[indice].genero,auxiliar.genero);
                            strcpy(movie[indice].linkImagen,auxiliar.linkImagen);
                            movie[indice].duracion=auxiliar.duracion;
                            movie[indice].puntaje=auxiliar.puntaje;
                        }
                    }
        }
        else
        {
            puts("cancelado!");
            retorno=0;
        }
    }
    return retorno;
}

void generarPagina(eMovie movie[],int longitud)
{
    FILE* archivo;
    int i;
        archivo=fopen("index.html","wb");
        fprintf(archivo,"<!DOCTYPE html>\n<html>\n<head>\n<title>Listado de peliculas TP3</title>\n</head>\n<body><article class='col-md-4 article-intro'>");
        for(i=0;i<longitud;i++)
        {
            if(movie[i].estado != 1)
            {
                continue;
            }
            fprintf(archivo,"<a href='#'><h3>%s</h3></a>",movie[i].titulo);
            fprintf(archivo," <img class='img-responsive img-rounded' src=' %s 'alt=''>",movie[i].linkImagen);
            fprintf(archivo,"<ul><li>Genero:%s</li>",movie[i].genero);
            fprintf(archivo,"<li>Puntaje:%d</li>",movie[i].puntaje);
            fprintf(archivo,"<li>Duracion:%d minutos</li></ul>",movie[i].duracion);
            fprintf(archivo,"<p>%s</p>",movie[i].descripcion);
        }
        fprintf(archivo,"</article></body></html>");
        fclose(archivo);
}

int guardar(eMovie* movie, int longitud)
{
	FILE* archivo;
	int i;
	archivo = fopen("bin.dat", "wb");
	if(archivo == NULL)
    {
		printf("\n No se pudo guardar el archivo");
		system("pause");
		exit(1);
		return 0;
	}
	for(i=0;i<longitud;i++)
    {
        if(movie[i].estado==1)
        {fwrite(&movie[i], sizeof(eMovie), 1, archivo);}
   }
    fclose(archivo);
	return 1;
}
