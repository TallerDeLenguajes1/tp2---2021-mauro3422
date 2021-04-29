#include <stdio.h>
#define N 4
#define M 5


int main(void){
int f,c;
double mt[N][M];

for(f = 0;f<N; f++)
{
    for(c = 0;c<M; c++)
    {
        printf("%lf\t",mt[f][c]);
    }
    printf("\n");
}

getchar();
return 0;
}