#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    start_t = clock();
    /* Multiplicacion 3-if anidados */
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    tiempo_t = clock();
    printf("Tiempo = %ld\n", tiempo_t-start_t);
    return 0;
}
