#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define min(a,b) ((a) < (b) ? (a) : (b))

int main()
{
    int n = 300;
    int a[n][n];
    int b[n][n];
    int c[n][n];
    int i,j,k;
    clock_t tiempo_t, start_t;
    /* Llenado */
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            a[i][j] = (i+j)%3 +1;
            b[i][j] = (i+j)%3 +2;
        }
    }
    /* Multiplicacion 6-if anidados */
    int i1,j1,k1,bloques=30;
    start_t = clock();
    for(i1 = 0; i1 < n; i1+=bloques){
        for(j1 = 0; j1 < n; j1+=bloques){
            for(k1 = 0; k1 < n; k1+=bloques){
                for(i = i1; i < i1+bloques; i++){
                    for(j = j1; j < j1+bloques; j++){
                        for(k = k1; k < k1+bloques; k++)
                            c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
        }
    }
    tiempo_t = clock();
    printf("Tiempo = %ld\n", tiempo_t-start_t);
    return 0;
}
