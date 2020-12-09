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
char* getNombreGenero(genero* generoA){
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
        Q->fin->sig = nuevo;
		Q->fin = nuevo;	
    }
}
cancion* sacar(colaCanciones *Q){
	cancion *aux;
    if(Q->ini == NULL){
        printf("cola vacia");
        return NULL;
    }
	//cola con un elemento
	if(Q->ini == Q->fin ){
		aux = Q->ini;
		Q->ini = NULL;
		Q->fin = NULL;
		return aux;
	}	
	aux = Q->ini;
	Q->ini = Q->ini->sig;
	return aux;
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
        return (min+seg);
        
    }
    min=(((duracion[0]-'0')*10)+(duracion[1]-'0'))*60;
    seg=((duracion[3]-'0')*10)+(duracion[4]-'0');
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
    //mostrarColaCanciones(Q);
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
preferencia* leerArchivoPreferencia(preferencia *L,int *tiempo){
    char* duracion=(char*)malloc(sizeof(char)*7);
    char ordenPreferencias[200];
    FILE* archivo;
    archivo=fopen("preferencias.in","r");
    fgets(duracion,7,archivo);
    *tiempo=duracionSegundos(duracion);
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
 e:cola de canciones
 s:cancion
 o:encontrar la cancion con mayor popularidad
 */
int mayorPopularidad(colaCanciones*Q){
    cancion* aux;
    int max;
    aux=Q->ini;
    max=getPopularidadCancion(aux);//PIVOTE
    if(aux->sig == NULL){ //HAY SOLO UNA CANCION
        return max;
    }
    while(aux!=NULL){ //PARA N CANCIONES
        if(max < getPopularidadCancion(aux)){
            max=getPopularidadCancion(aux);
        }
        aux=aux->sig;
    }
    return max;
}
/*
 e:cola canciones, popularidad
 s:menor duracion
 o:busca la cancion segun la menor duracion dada una popularidad
 */
int menorDuracion(colaCanciones* Q,int popularidad){
    cancion* aux;
    int min;
    aux=Q->ini;
    min=getDuracionCancion(aux);//PIVOTE
    if(aux->sig == NULL){ //HAY SOLO UNA CANCION
        return min;
    }
    while(aux!=NULL){ //PARA N CANCIONES
        if(min > getDuracionCancion(aux) && getPopularidadCancion(aux) == popularidad){
            min=getDuracionCancion(aux);
        }
        aux=aux->sig;
    }
    return min;
}
void encolarCancion_2(colaCanciones*Q,cancion* aux){
    cancion* nuevo=crearCancion(getNombreCancion(aux),getDuracionString(aux),getCodigoArtistaCancion(aux),getCodigoGeneroCancion(aux),getPopularidadCancion(aux),getDuracionCancion(aux));
    if(Q->fin == NULL){
        Q->ini=aux;
        Q->fin=aux;
    }
    else{
        Q->fin->sig=nuevo;
        Q->fin=Q->fin->sig;
        
    }
}
/*
    e:cola canciones
    s:cola canciones
    o:ordenar una cola segun su popularidad
 */
colaCanciones ordenarPopularidad(colaCanciones *Q){
    colaCanciones ordenada=crearColaCanciones();
    cancion* aux,*max;
    int mayorEncontrado=0;
    int i=0;
    while(Q->ini!=NULL && i<10){
        mayorEncontrado=mayorPopularidad(Q);
        aux=sacar(Q);
        if(mayorEncontrado == getPopularidadCancion(aux)){
            encolarCancion_2(&ordenada,aux);
        }
        else{
            encolarCancion_2(Q,aux);
        }
        i=i+1;
    }
    printf("Asi quedo Q:\n");
    mostrarColaCanciones(Q);
    printf("ordenada:\n");
    mostrarColaCanciones(&ordenada);
    return ordenada;
}
/*
 e:cola,id del artista
 s:nombre artista
 o:busca el nombre de un artista dado un id
 */
char* buscarArtista(colaArtista* Q,int id){
    artista* aux=Q->ini;
    while(aux!=NULL){
        if(getIdArtista(aux)==id){
            return (getNombreArtista(aux));
        }
        aux=aux->sig;
    }
}
/*
 e:cola canciones,cola artistas
 s:cancion
 o:determinar la cancion de orden mas bajo
 */
char* alfabetico(colaCanciones*Q,colaArtista *P,int popularidad){
    cancion* aux=Q->ini;
    cancion* primera=Q->ini;
    char* nombreAux=buscarArtista(P,getCodigoArtistaCancion(primera));
    while(aux!=NULL){
        if((strcmp(nombreAux,buscarArtista(P,getCodigoArtistaCancion(aux)))>0) && getPopularidadCancion(aux)== popularidad){
            primera=aux;
            nombreAux=buscarArtista(P,getCodigoArtistaCancion(primera));
        }
        aux=aux->sig;
    }
    return nombreAux;
}

colaCanciones ordenarAlfabetica(colaCanciones* Q){
    cancion* aux=Q->ini;
    colaCanciones temp=crearColaCanciones();
    while(aux->sig!=NULL){
        if(getPopularidadCancion(aux)==getPopularidadCancion(aux->sig)){
        }
        aux=aux->sig;
    }
}
/*
 e:cola canciones,cola artistas
 s:cola canciones
 o:ordena las canciones segun los criterios dados
 */
colaCanciones ordenarCanciones(colaCanciones *Q,colaArtista *P){
    colaCanciones ordenada=crearColaCanciones();
    cancion *aux,*max;
    int mayorEncontrado,menorEncontrado;
    char* nombreEncontrado;
    int i=0;
    while(Q->ini!=NULL && i<100){
        mayorEncontrado=mayorPopularidad(Q);
        menorEncontrado=menorDuracion(Q,mayorEncontrado);
        nombreEncontrado=alfabetico(Q,P,mayorEncontrado);
        aux=sacar(Q);
        if(mayorEncontrado == getPopularidadCancion(aux) && getDuracionCancion(aux)==menorEncontrado && strcmp(nombreEncontrado,buscarArtista(P,getCodigoArtistaCancion(aux)))==0){
            encolarCancion_2(&ordenada,aux);
        }
        else{
            encolarCancion_2(Q,aux);
        }
        i=i+1;
    }
    return ordenada;
}
/*
 e:cola de genero, id
 s:nombre genero
 o:determinar el genero dado un id
 */
char* buscarGenero(colaGenero *Q,int idGenero){
    genero* aux=Q->ini;
    while(aux!=NULL){
        if(getIdGenero(aux)==idGenero){
            return (getNombreGenero(aux));
        }
        aux=aux->sig;
    }
}
/*
 e:cola canciones
 s:vacio
 o:escribir en un archivo las canciones ordenadas
 */
void escribirArchivoSalida(colaCanciones *Q,colaArtista *P,colaGenero *M){
    cancion* aux=Q->ini;
    char* nombreArtista;
    char* genero;
    if (Q->ini == NULL){
        return;
    }
    FILE* archivo;
    archivo=fopen("salida.out","w");
    while(aux!=NULL){
        nombreArtista=buscarArtista(P,getCodigoArtistaCancion(aux));
        genero=buscarGenero(M,getCodigoGeneroCancion(aux));
        fprintf(archivo,"%d;%s;%s;%s;%s\n",getPopularidadCancion(aux),getNombreCancion(aux),getDuracionString(aux),nombreArtista,genero);
        aux=aux->sig;
    }
    fclose(archivo);
}
/*
 e:dato
 s:1,0
 o:determinar si un id se encuentra en las preferencias
 */
int estaEnPreferencias(int id,preferencia* P){
    preferencia *aux=P;
    while(aux!=NULL){
        if(id==aux->dato){
            return 1;
        }
        aux=aux->sig;
    }
    return 0;
}
int mayorPopularidadGenero(colaCanciones *Q,int genero){
    cancion *aux=Q->ini;
    int mayorTemp=0;
    while(aux!=NULL){
        if(getPopularidadCancion(aux)>mayorTemp && getCodigoGeneroCancion(aux)==genero){
            mayorTemp=getPopularidadCancion(aux);
        }
        aux=aux->sig;
    }
    return mayorTemp;
}
colaCanciones filtrarCanciones(colaCanciones* Q,preferencia* P){
    colaCanciones filtrada=crearColaCanciones();
    cancion* auxCan;
    preferencia* auxPref=P;
    int maxPopularidad;
    int i=0;
    while(auxPref!=NULL && i<30){
        while (auxCan!=NULL && i<30){
            maxPopularidad=mayorPopularidadGenero(Q,auxPref->dato);
            auxCan=sacar(Q);
            if(getCodigoGeneroCancion(auxCan)==auxPref->dato && maxPopularidad == getPopularidadCancion(auxCan)){
                cancion* nuevo=crearCancion(getNombreCancion(auxCan),getDuracionString(auxCan),getCodigoArtistaCancion(auxCan),getCodigoGeneroCancion(auxCan),getPopularidadCancion(auxCan),getDuracionCancion(auxCan));
                encolarCancion_2(&filtrada,nuevo);
               break;
            }
            else{
                encolarCancion_2(Q,auxCan);
            }
            i=i+1;
        }
        auxCan=Q->ini;
        auxPref=auxPref->sig;
        if(auxPref== NULL){
            auxPref=P;
        }
    }
    mostrarColaCanciones(&filtrada);
    return filtrada;
}
void transformarString(int segundos,char* t){
    int auxDecenas,auxUnidad,minutos=0;
    while(segundos-60>=0){
        segundos=segundos-60;
        minutos=minutos+1;
    }
    if (minutos==0 ){
        t[0]='0';
        t[1]='0';
        t[2]=':';
    }
    if(minutos<10){
        t[0]='0';
        t[1]=minutos+'0';
        t[2]=':';
    }
    if (minutos>10){
        auxDecenas=minutos/10;
        auxUnidad=minutos-auxDecenas*10;
        t[3]=auxDecenas+'0';
        t[4]=auxUnidad+'0';
    }
    if(segundos<10){
        t[3]='0';
        t[4]=segundos+'0';
        return;
    }
    auxDecenas=segundos/10;
    auxUnidad=segundos-auxDecenas*10;
    t[3]=auxDecenas+'0';
    t[4]=auxUnidad+'0';
    return;    
}
void escribirPlaylist(colaCanciones *Q,colaArtista *P,colaGenero *M,int tiempoMax){
    cancion* aux=Q->ini;
    char* nombreArtista;
    char* genero;
    int acum=0;
    if (Q->ini == NULL){
        return;
    }
    FILE* archivo;
    archivo=fopen("playlist.out","w");
    while(acum<tiempoMax){
        acum=acum+getDuracionCancion(aux);
        nombreArtista=buscarArtista(P,getCodigoArtistaCancion(aux));
        genero=buscarGenero(M,getCodigoGeneroCancion(aux));
        fprintf(archivo,"%d;%s;%s;%s;%s\n",getPopularidadCancion(aux),getNombreCancion(aux),getDuracionString(aux),nombreArtista,genero);
        aux=aux->sig;
        if(aux==NULL){
            aux=Q->ini;
        }
    }
    if(acum-tiempoMax>0){
        char t[6];
        transformarString(acum-tiempoMax,t);
        fprintf(archivo,"%s\n",t);
    }
    fclose(archivo);
}
int main(){    
    colaArtista artistas;
    colaGenero generos;
    colaCanciones canciones;
    preferencia* preferencias=NULL;
    int tiempo;
    //
    artistas=crearColaArtista();
    generos=crearColaGenero();
    canciones=crearColaCanciones();
    leerArchivoArtista(&artistas);
    leerArchivoGenero(&generos);
    leerArchivoCanciones(&canciones);
    mostrarColaCanciones(&canciones);
    preferencias=leerArchivoPreferencia(preferencias,&tiempo);
    canciones=ordenarCanciones(&canciones,&artistas);
    escribirArchivoSalida(&canciones,&artistas,&generos);
    canciones=filtrarCanciones(&canciones,preferencias);
    escribirPlaylist(&canciones,&artistas,&generos,tiempo);
    return 0;
}
