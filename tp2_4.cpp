#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Para crear numeros aleatorios
#include <ctime>

typedef struct compu{
    int velocidad;
    int anioFab;
    int cant_nuc;
    char *tipo_cpu;
} pc;
char tipos[6][10]={"intel","AMD","Celeron","Athlon","Core","Pentium"};


void CargarDatosPun(pc *item, int cant);

void MostrarDato(pc *item);

pc cargarDatoRetorno(pc item);

void MostrarInventario(pc *item,int cant);

void compVieja(pc *item,int cant);

void compMvelocidad(pc *item,int cant);
int main(void){
    //Para crear numeros aleatorios
    srand(time(NULL));
    
    int cant;
    pc * inventario,obj;
    
    //Punto a(g)
    printf("Ingresa la cantidad de computadoras  a guardar:");
    scanf("%d",&cant);
    inventario=(pc *)malloc(cant*sizeof(pc));

    //Crear una funcion que devuelva(retorne) la estructura.
    printf("Primera estructura, cargada por argumento.\n");
    obj= cargarDatoRetorno(obj);
    //Muestro solo una estructura.
    MostrarDato(&obj);

    //Cargo la estructura enviando la direccion de memoria, un puntero.
    CargarDatosPun(inventario,cant);

    //Muestro todas las estructuras del arreglo Inventario.
    MostrarInventario(inventario,cant);
    
    //Busco la computadora mas antigua.

    compVieja(inventario,cant);

    //Busco la computa mas veloz.
    compMvelocidad(inventario,cant);


    //Debugear en el getchar();, no se porque se cierra automaticamente el ejecutable.
    getchar();

    free(inventario);
    return 0;
}

//Cargo los datos aleatoriamente por el puntero.
void CargarDatosPun(pc *item, int cant){
    
    //Esto se repetira las veces que el usuario pidio.
    for (int i = 0; i < cant; i++)
    {
        int j;
        //Como es un puntero se trabaja con el operador "->"
        item->velocidad=rand()%(3-1+1)+1;
        item->anioFab=rand()%(2017-2000+1)+2000;
        item->cant_nuc=rand()%(4-1+1)+1;
        //Eligo un indice aleatorio para seleccionar un string.
        j=rand()%(5-0+1)+0;
        item->tipo_cpu=(char *) malloc(10*sizeof(char));
        strcpy(item->tipo_cpu,tipos[j]);

        //Hago que el puntero avanze a la siguiente estructura.
        item++;
    }
}
//Cargo una estructura por argumento, retornando la variable struct.
pc cargarDatoRetorno(pc item){
    int j;
    //Como no es una direccion de memoria se trabaja con el operador "."
    item.velocidad=rand()%(3-1+1)+1;
    item.anioFab=rand()%(2017-2000+1)+2000;
    item.cant_nuc=rand()%(4-1+1)+1;
    j=rand()%(5-0+1)+0;
    item.tipo_cpu=(char *) malloc(10*sizeof(char));
    strcpy(item.tipo_cpu,tipos[j]);
    return item;
}
//Muestro una estrucutra..
void MostrarDato(pc *item){
    printf("Tipo de procesador:%s\n",item->tipo_cpu);
    printf("Anio de fabricacion:%d\n",item->anioFab);
    printf("Cantidad de nucleos:%d\n",item->cant_nuc);
    printf("Velocidad:%d\n",item->velocidad);
}

//Muestro el inventario completo.
void MostrarInventario(pc *item,int cant){
    for (int i = 0; i < cant; i++)
    {
        printf("------------Computadora numero [%d]------------\n",i+1);
        MostrarDato(item);
        //Avanza el puntero
        item++;
    }
    
}

//Busco cual es la computadora mas vieja y muestro sus datos.
void compVieja(pc *item,int cant){
    //Incializo.
    int temp=3000,j;
    //Creo un puntero temporal asi se guarda la direccion de memoria de la pc mas antigua.
    pc *pTemp;
    for (int i = 0; i < cant; i++)
    {
        if (item->anioFab<temp)
        {
            temp=item->anioFab;
            pTemp=item;
            j=i;
        }
        //Avanza el puntero
        item++;
    }



    printf("-----------------La PC mas ANTIGUA  es la computadora [%d]-------------------\n",j+1);
    MostrarDato(pTemp);
}

//Busco la computadora mas veloz y muestro sus datos.
void compMvelocidad(pc *item,int cant){
    //Incializo.
    int temp=0,j;
    //Creo un puntero temporal asi se guarda la direccion de memoria de la pc mas rapida.
    pc *pTemp;
    for (int i = 0; i < cant; i++)
    {
        if (item->velocidad>temp)
        {
            temp=item->velocidad;
            pTemp=item;
            j=i;
        }
        //Avanza el puntero
        item++;
    }



    printf("-----------------La PC mas RAPIDA es la computadora [%d]-------------------\n",j+1);
    MostrarDato(pTemp);
}