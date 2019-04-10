/*
 * Author: Alex Hiller
 * Year: 2019
 *
 * Program Description: 
 *    Implementation of the Gauss-Siedel algorithm for approaching solutions of
 *    Ax=b ⇒ x = A^-1 b
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define INITIAL_GUESS   {0,0,0}
#define ITERS           10
#define OMEGA           0.5

float* copyMat(float* val, float* store);
void printMat1d(float* mat);

int
main (int argc, char *argv[]) {
    float x_n[3]   = INITIAL_GUESS;

    float A[3][3] = {{1,0,-1},{1,2,-1},{2,-1,3}};
    float b[3] = {-4, 4, 18};
    
    int iter; /* Iteration number */
    int i; 
    int j;
    for (iter=0; iter<ITERS; iter++) {
        for (i = 0; i<3; i++) {
            float sum1=0, sum2=0;
            for (j=0; j<i; j++) {
                sum1 += A[i][j]*x_n[j];
            }
            for (j=i; j<4; j++) {
                sum2 += A[i][j]*x_n[j];
            }
            x_n[i] += (OMEGA/(A[i][i]))*(b[i] - sum1 - sum2);
        }
        printf("Iteration %i\nx_n:\n", iter);
        printMat1d(x_n);
        printf("\n");
    }
    return 0;
}


void 
printMat1d(float* mat) {
    printf("%.2f\t\t\t%.2f\t\t\t%.2f\n", mat[0], mat[1], mat[2]);
}

float* 
copyMat(float* val, float* store) {
    int i;
    for (i=0; i<3; i++) 
        store[i] = val[i];
    return store;
}
