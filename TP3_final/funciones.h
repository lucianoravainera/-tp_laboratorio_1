#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[500];
    int estado;
    int id;
}eMovie;
void inicializar(eMovie* movie,int length);
int cargarArchivo(eMovie* movie, int length);
int menu(char mensaje[],char error[]);
int ingresar(eMovie* movie,int length);
int BuscarID(eMovie* movie,int length,int valor);
void getString (char message[],char entrada[]);
int getCharP(char ingreso[],int limite);
int esAlfaNumerico(char str[],int limite);
int esNumeroNatural(char numeros[],int limite);
int valInt(int x,int desde,int hasta);
char reingresar(char eMensaje[],char pregunta[]);
int getTitle(eMovie* movie,int longitud,int vacio, char input[]);
int getGenero(eMovie* movie,int longitud, char input[]);
int GetLink(eMovie* movie,int longitud, char input[]);
int getTime(eMovie* movie,int longitud,int vacio,int* input);
int GetDesc(eMovie* movie,int longitud,int vacio, char input[]);
int getPuntaje(eMovie* movie, int longitud, int* input);
int mostrarTitulos(eMovie* movie, int longitud, int ocupado);
int actualizarId(eMovie* movie,int longitud);
int buscarPorId(eMovie* movie, int longitud, int id);
int idValido(eMovie* movie, int longitud);
int modificar(eMovie* movie, int longitud);
int guardar(eMovie* movie, int longitud);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int ingresar(eMovie* movie,int length);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int deleteMovie(eMovie*, int longitud);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie movie[],int longitud);

#endif // FUNCIONES_H_INCLUDED
