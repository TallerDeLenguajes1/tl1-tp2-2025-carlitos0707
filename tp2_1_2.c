#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
int main(){ 
    int i;
    srand(time(NULL));
    double vt[N];
    double* pvt;
    pvt = vt;
    for(i = 0;i<N; i++)
    {
        vt[i]=1+rand()%100;
        printf("    %.2f    ", pvt[i]);
    }
}