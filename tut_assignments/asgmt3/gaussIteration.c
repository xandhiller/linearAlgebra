/*
 * Author: Alex Hiller
 * Year: 2019
 *
 * Program Description: 
 *    Implements the Gaussian algorithm for iteratively approaching solutions
 *    of for Ax=b ⇒ x = A^-1 b
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define INITIAL_GUESS   {0,0,0}
#define ITERS           40


/* void printMat2d(float* mat[3]); FIXME */
float* copyMat(float* val, float* store);
void printMat1d(float* mat);


int 
main (int argc, char *argv[]) {
    float x_n[3]   = INITIAL_GUESS;
    float x_nm1[3] = INITIAL_GUESS;

    float A[3][3] = {{1,0,-1},{1,2,-1},{2,-1,3}};
    float b[3] = {-4, 4, 18};
    
    int iter; /* Iteration number */
    int i; 
    int j;
    for (iter=0; iter<ITERS; iter++) {
        for (i = 0; i<3; i++) {
            float sum = 0;
            for (j=0; j<3; j++) {
                if (j == i)
                    continue;
                sum += A[i][j]*x_nm1[j];
            }
            x_n[i] = (1/(A[i][i]))*(b[i] - sum);
        }
        printf("Iteration %i\nx_n:\n", iter);
        printMat1d(x_n);
        printf("x_nm1:\n");
        printMat1d(x_nm1);
        printf("\n");
        copyMat(x_n, x_nm1);
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

/* FIXME 
 * void printMat2d(float** mat) { 
    int i;
    for (i=0; i<3; i++) 
        printf("%.2f\t\t\t%.2f\t\t\t%.2f\n", mat[i][0], mat[i][1], mat[i][2]);
} */
