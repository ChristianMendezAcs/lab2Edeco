/*
    Christian Mendez Acosta
    20220627-1
    Laboratorio numero 2
    A-1
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
    TDA Artistas
*/
typedef struct artista artista;
struct artista{
    int idArtista;
    char *nombreArtista;
    artista *sig;
};
//Creador
/*
    e:numero,nombre
    s:artista
    o:crear un nuevo artista
 */
artista* crearArtista(int id,char* nombre){
    artista *aux;
    aux=(artista*)malloc(sizeof(artista));
    aux->idArtista=id;
    aux->nombreArtista=nombre;
    aux->sig=NULL;
    return aux;
}
/*TDA COLA ARTISTA*/
typedef struct colaArtista colaArtista;
struct colaArtista{
  artista* ini;
  artista* fin;
};
/*
    e:vacio
    s:cola
    o:crear el espacio necesario para una cola
 */
colaArtista crearColaArtista(){
    colaArtista *aux;
    aux=(colaArtista *)malloc(sizeof(colaArtista));
    aux->ini= NULL;
    aux->fin= NULL;
    return *aux;
}
/*
    e:cola,id,nombre
    s:vacio
    o:agregar un artista al principio de la cola de artistas
 */
void encolarArtista(colaArtista* Q,int id, char* nombre){
    artista* nuevo;
    nuevo=crearArtista(id,nombre);
    if(Q->fin == NULL){
        Q->ini=nuevo;
        Q->fin=nuevo;
    }
    else{
        Q->fin->sig=nuevo;
        Q->fin=nuevo;
    }
    
}
/*
    e:cola artistas
    s:vacio
    o:mostrar la cola de los artistas
 */
void mostrarColaArtista(colaArtista *Q){
	
	artista *aux;	
	printf("Cola Inicio:\n");
	aux = Q->ini;
	while(aux != NULL){
		printf("%d,%s\n",aux->idArtista,aux->nombreArtista);
		aux = aux->sig;
	}
	printf("Cola Fin:\n\n");
}
//Selector
/*
    e:artista
    s:id del artista
    o:retorna el id de un artista
*/
int getIdArtista(artista* artistaA){
    return artistaA->idArtista;
}
/*
    e:artista
    s:nombre de un artista
    o:retorna el nombre de un artista
*/
char* getNombreArtista(artista* artistaA){
    return artistaA->nombreArtista;
}
/*Otras operaciones*/
/*
    e:cola
    s:vacio
    o:añadir los artista del archivo a una cola
 */
void leerArchivoArtista(colaArtista *Q){
    FILE *archivo;
    artista* aux=Q->ini;
    int largoArchivo,idAux;
    archivo=fopen("artistas.in","r");
    fscanf(archivo,"%d",&largoArchivo);
    
    for(int i=0;i<largoArchivo;i++){
        char *nombre=(char*)malloc(sizeof(char)*20);
        fscanf(archivo,"%d %s",&idAux,nombre);
        encolarArtista(Q,idAux,nombre);
    }
    mostrarColaArtista(Q);
    fclose(archivo);
}

/*
 TDA Generos
 */
 typedef struct genero genero;
 struct genero{
    int idGenero;
    char *nombreGenero;
    genero* sig;
 };
 //Crear
 /*
    e:vacio
    s:nuevo genero
    o:reserva espacio para un nuevo genero
  */
genero* crearGenero(int id,char* nombre){
    genero* aux;
    aux=(genero*)malloc(sizeof(genero));
    aux->idGenero=id;
    aux->nombreGenero=nombre;
    aux->sig=NULL;
    return aux;
}
 //Selector
 /*
    e:genero
    s:id del genero
    d:retorna el id de un genero
 */
 int getIdGenero(genero* generoA){
     return generoA->idGenero;
 }
 /*
    e:genero
    s:nombre del genero
    d:retorna el nombre de un genero
 */
char* getNombre(genero* generoA){
     return generoA->nombreGenero;
}
/*TDA COLA GENERO*/
typedef struct colaGenero colaGenero;
struct colaGenero{
    genero* ini;
    genero* fin;
};
/*
    e:vacio
    s:nueva cola
    o:crear una nueva cola
 */
colaGenero crearColaGenero(){
    colaGenero *aux;
    aux=(colaGenero *)malloc(sizeof(colaGenero));
    aux->ini= NULL;
    aux->fin= NULL;
    return *aux;
}
/*
    e:cola genero,id,nombre
    s:vacio
    o:encolar genero
 */
void encolarGenero(colaGenero* Q,int id, char* nombre){
    genero* nuevo;
    nuevo=crearGenero(id,nombre);
    if(Q->fin == NULL){
        Q->ini=nuevo;
        Q->fin=nuevo;
    }
    else{
        Q->fin->sig=nuevo;
        Q->fin=nuevo;
    }
}

void mostrarColaGenero(colaGenero *Q){
	
	genero *aux;	
	printf("Cola Inicio:\n");
	aux = Q->ini;
	while(aux != NULL){
		printf("%d,%s\n",aux->idGenero,aux->nombreGenero);
		aux = aux->sig;
	}
	printf("Cola Fin:\n\n");
}
/*
    e:cola genero
    s:vacio
    o:registra en una cola los generos del archivo
 */
void leerArchivoGenero(colaGenero *Q){
    FILE *archivo;
    genero* aux=Q->ini;
    int largoArchivo,idAux;
    archivo=fopen("generos.in","r");
    fscanf(archivo,"%d",&largoArchivo);
    for(int i=0;i<largoArchivo;i++){
        char *nombre=(char*)malloc(sizeof(char)*20);
        fscanf(archivo,"%d %s",&idAux,nombre);
        encolarGenero(Q,idAux,nombre);
    }
    mostrarColaGenero(Q);
    fclose(archivo);
}
/*
    TDA Canciones
*/
typedef struct cancion cancion;
struct cancion{
    char *nombreCancion;
    char *duracionString;
    int duracion;
    int codigoArtista;
    int codigoGenero;
    int popularidad;
    cancion *sig;
};
/*
    e:nombre,duracion,id artista, id genero, popularidad, segundos
    s:nueva cancion
    o:crear una nueva cancion
 */
cancion* crearCancion(char* nombre,char* duracion,int idArtista,int idGenero,int popularidad,int segundos){
    cancion* aux;
    aux=(cancion*)malloc(sizeof(cancion));
    aux->nombreCancion=nombre;
    aux->duracionString=duracion;
    aux->codigoArtista=idArtista;
    aux->codigoGenero=idGenero;
    aux->popularidad=popularidad;
    aux->duracion=segundos;
    aux->sig=NULL;
    return aux;
}
/*
    e:cancion
    s:duracion de una cancion
    d:retorna la duracion de una cancion
*/
int getDuracionCancion(cancion *cancionA){
    return cancionA->duracion;
}
/*
    e:cancion
    s:codigo del artista de una cancion
    d:retorna el id del artista de una cancion
*/
int getCodigoArtistaCancion(cancion *cancionA){
    return cancionA->codigoArtista;
}
/*
    e:cancion
    s:codigo del genero de la cancion
    d:retorna el codigo del genero de la cancion
*/
int getCodigoGeneroCancion(cancion *cancionA){
    return cancionA->codigoGenero;
}
/*
    e:cancion
    s:popularidad de una cancion
    o:retorna la popularidad de una cancion
*/
int getPopularidadCancion(cancion *cancionA){
    return cancionA->popularidad;
}
/*
    e:cancion
    s:nombre de una cancion
    o:retorna el nombre de una cancion
*/
char* getNombreCancion(cancion *cancionA){
    return cancionA->nombreCancion;
}
/*
    e:cancion
    s:duracion de una cancion en string
    o:retornar la duracion de una cancion en string
*/
char* getDuracionString(cancion *cancionA){
    return cancionA->duracionString;
}
/*TDA COLA CANCIONES*/
typedef struct colaCanciones colaCanciones;
struct colaCanciones{
    cancion* ini;
    cancion* fin;
};
/*
    e:vacio
    s:nueva cola
    o:crea una nueva cola
 */
colaCanciones crearColaCanciones(){
    colaCanciones *aux;
    aux=(colaCanciones *)malloc(sizeof(colaCanciones));
    aux->ini= NULL;
    aux->fin= NULL;
    return *aux;
}
/*
    e:cola de canciones, nombre, duracion, id del artista, id del genero, popularidad, segundos
    s:vacio
    o:encola una nueva cancion
 */
void encolarCancion(colaCanciones* Q,char* nombre,char* duracion,int idArtista,int idGenero,int popularidad,int segundos){
    cancion* nuevo;
    nuevo=crearCancion(nombre,duracion,idArtista,idGenero,popularidad,segundos);
    if(Q->fin == NULL){
        Q->ini=nuevo;
        Q->fin=nuevo;
    }
    else{
        Q->fin->sig=nuevo;
        Q->fin=nuevo;
    }
}

void mostrarColaCanciones(colaCanciones *Q){
	
	cancion *aux;	
	printf("Cola Inicio:\n");
	aux = Q->ini;
	while(aux != NULL){
		printf("%s %s %d %d %d,%d\n",getNombreCancion(aux),getDuracionString(aux),getCodigoArtistaCancion(aux),getCodigoGeneroCancion(aux),getPopularidadCancion(aux),getDuracionCancion(aux));
		aux = aux->sig;
	}
	printf("Cola Fin:\n\n");
}
/*
    e:duracion(string)
    s:duracion en segundos
    o:transformar la duracion de string a numero en segundos
 */
int duracionSegundos(char* duracion){
    int largo=0;
    int min,seg;
    for(int i=0;i<5;i++){
        if (duracion[i] == ':'){
            break;
        }
        largo=largo+1;
    }
    if(largo == 1){
        min=(duracion[0]-'0')*60;
        seg=((duracion[2]-'0')*10)+(duracion[3]-'0');
        printf("\n%d\n",min+seg);
        return (min+seg);
        
    }
    min=(((duracion[0]-'0')*10)+(duracion[1]-'0'))*60;
    seg=((duracion[3]-'0')*10)+(duracion[4]-'0');
    printf("\n%d\n",min+seg);
    return (min+seg);
}
/*
    e:cola de canciones
    s:vacio
    o:registra en una cola las canciones del archivo 
 */
void leerArchivoCanciones(colaCanciones *Q){
    FILE *archivo;
    int largoArchivo,codigoArtista,codigoGenero,popularidad,seg;
    archivo=fopen("canciones.in","r");
    fscanf(archivo,"%d",&largoArchivo);
    for(int i=0;i<largoArchivo;i++){
        char* nombre=(char*)malloc(sizeof(char)*20);
        char* duracion=(char*)malloc(sizeof(char)*5);
        fscanf(archivo,"%s %s %d %d %d",nombre,duracion,&codigoArtista,&codigoGenero,&popularidad);
        seg=duracionSegundos(duracion);
        //printf("%s %s %d %d %d\n",nombre,duracion,codigoArtista,codigoGenero,popularidad);
        encolarCancion(Q,nombre,duracion,codigoArtista,codigoGenero,popularidad,seg);
    }
    mostrarColaCanciones(Q);
    fclose(archivo);
}
/*
    TDA Preferencias
*/
typedef struct preferencia preferencia;
struct preferencia{
    int dato;
    preferencia* sig;
};
/*
    e:vacio
    s:preferencia
    o:crear una nueva preferencia
 */
preferencia* crearPreferencia(){
    preferencia *aux;
    aux=(preferencia*)malloc(sizeof(preferencia));
    aux->sig=NULL;
    return aux;
}
/*
    e::preferencia,dato
    s:preferencia
    o:agregar una preferencia a una lista de preferencias
 */
preferencia *agregarPreferencia(preferencia *L,int dato){
    preferencia *nuevo;
    nuevo=(preferencia*)malloc(sizeof(preferencia));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    if(L == NULL){
        L=nuevo;
        return L;
    }
    preferencia* aux=L;
    while(aux->sig!=NULL){
        aux=aux->sig;
    }
    aux->sig=nuevo;
    return L;
}
void mostrarLista(preferencia *L){
    preferencia *aux=L;
    while(aux!=NULL){
        printf("%d ",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}
/*
    e:lista preferencias
    s:preferencia
    o:registrar el tiempo maximo y el orden de las preferencias
 */
preferencia* leerArchivoPreferencia(preferencia *L){
    char* duracion=(char*)malloc(sizeof(char)*7);
    char ordenPreferencias[200];
    FILE* archivo;
    archivo=fopen("preferencias.in","r");
    fgets(duracion,7,archivo);
    fgets(ordenPreferencias,200,archivo);
    printf("%s%s",duracion,ordenPreferencias);
    char* separador=strtok(ordenPreferencias," ");
    if(separador != NULL){
        while(separador != NULL){
            L=agregarPreferencia(L,atoi(separador));
            separador=strtok(NULL," ");
        }
    }
    fclose(archivo);
    return L;
}
/*
 [10,9,12,13,24] []
 [10,12,13,24] [24]
 */
void mayorPopularidad(colaCanciones*Q){
    cancion* aux;
    cancion* menor;
    int menor;
    aux=Q->ini;
    menor=getPopularidadCancion(aux);
    printf("m:%d",menor);
    while(aux!=NULL){
        if(menor > getPopularidadCancion(aux)){
            
        }
    }
}
int main(){    
    colaArtista artistas;
    colaGenero generos;
    colaCanciones canciones;
    preferencia* preferencias=NULL;
    //
    artistas=crearColaArtista();
    generos=crearColaGenero();
    canciones=crearColaCanciones();
    leerArchivoArtista(&artistas);
    leerArchivoGenero(&generos);
    leerArchivoCanciones(&canciones);
    preferencias=leerArchivoPreferencia(preferencias);
    return 0;
}
