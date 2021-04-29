#include <stdio.h>
#define N 4
#define M 5


int main(void){
int f,c;
double mt[N][M];

//Declaro un puntero
double *p;
p=&mt[0][0];


for(f = 0;f<N; f++)
{
    for(c = 0;c<M; c++)
    {
        //Uso Aritmetica de punteros.
        printf("%lf\t",*(p+f*M+c));
    }
    printf("\n");
}
getchar();
return 0;
}