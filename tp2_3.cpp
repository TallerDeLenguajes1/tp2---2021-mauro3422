#include <stdio.h>
#include <stdlib.h>

//Para crear numeros aleatorios
#include <ctime>
const int Filas=15;
void detNumPares(int **PMatriz,int Columnas,int *arreglo);
void genVector(int *Arr,int num,int fila);
int main(void){
    //Para crear numeros aleatorios
    srand(time(NULL));
    //Declaro columnas e inicializo en algun numero aleatorio entre 5 y 15
    int Columnas= rand()%(15-5+1)+5;


    //Declaro la fila Dinamica de la matriz.
    int **Matriz=(int **) malloc(sizeof(int)*Filas);

    for (int i = 0; i <Filas; i++)
    {
        //Declaro  las columnas.
      Matriz[i]=(int *) malloc(sizeof(int)*Columnas);
      for (int j = 0; j < Columnas; j++)
      {
          Matriz[i][j]=rand()%(999-100+1)+100;
          printf("Arreglo[%d][%d]=%d\t",i+1,j+1,Matriz[i][j]);
      }
      printf("\n");
        
    }

    //Declaro un arreglo dinamico.
    int *vector=(int *) malloc(sizeof(int)*(Filas));

    //Mando la direccion de la matriz, la variable columnas y la direccion del vector.
    detNumPares(Matriz,Columnas,vector);


    for (int i = 0; i < Filas; i++)
    {
        printf("[%d]=[%d]\t",i+1,vector[i]);
    }
    
    free(vector);
    free(Matriz);

    getchar();
    return 0;
}

//Determino los numeros pares en esta funcion.
void detNumPares(int **PMatriz,int Columnas, int *arreglo){
    int cantPares=0;
    //recorro el arreglo de matrices.
    for (int i = 0; i < Filas; i++)
    {
        for (int j = 0; j < Columnas; j++)
        {   

            if (PMatriz[i][j]%2 == 0)
            {
                //Cada vez que se detecta que hay un numero que es par, el contador se suma.
                cantPares++;
                
            }
        }
        //mando la cantidad de numeros pares que se encontro en la fila. el arreglo donde se guardaran, y el indice.
        genVector(arreglo,cantPares,i);
        cantPares=0;
    }
    
}
//Guardo los numeros pares.
void genVector(int *Arr,int num,int fila){
    //guardo el dato.
    Arr[fila]=num;
    

}