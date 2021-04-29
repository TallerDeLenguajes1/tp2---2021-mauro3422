#include <stdio.h>
#include <stdlib.h>
#include <ctime>
const int Filas=15;
void detNumPares(int **PMatriz,int Columnas,int *arreglo);
void genVector(int *Arr,int num,int fila);
int main(void){
    srand(time(NULL));
    //Declaro columnas e inicializo en algun numero aleatorio entre 5 y 15
    int Columnas= rand()%(15-5+1)+5;



    int **Matriz=(int **) malloc(sizeof(int)*Filas);

    for (int i = 0; i <Filas; i++)
    {
      Matriz[i]=(int *) malloc(sizeof(int)*Columnas);
      for (int j = 0; j < Columnas; j++)
      {
          Matriz[i][j]=rand()%(999-100+1)+100;
          printf("[%d][%d]=%d\t",i+1,j+1,Matriz[i][j]);
      }
      printf("\n");
        
    }


    int *vector=(int *) malloc(sizeof(int)*(Filas));


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
void detNumPares(int **PMatriz,int Columnas, int *arreglo){
    int cantPares=0;
    
    for (int i = 0; i < Filas; i++)
    {
        for (int j = 0; j < Columnas; j++)
        {
            if (PMatriz[i][j]%2 == 0)
            {
                cantPares++;
                
            }
        }
        genVector(arreglo,cantPares,i);
        cantPares=0;
    }
    
}
void genVector(int *Arr,int num,int fila){

    Arr[fila]=num;
    

}