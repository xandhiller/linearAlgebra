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


enum {JACOBI, GAUSS_SIEDEL, PARAMETER};


#define INITIAL_GUESS   {0,0,0}
#define ITERS           1000
#define OMEGA           1
#define STOP            1
#define CONTINUE        0
#define EPSILON         0.00001
#define METHOD          GAUSS_SIEDEL


float* copyMat(float* val, float* store);
void printMat1d(float* mat);
float supNorm(float* arr, int arrLen);
int stopCriterion(float* current, float* prev, int arrlen);


int
main (int argc, char *argv[]) {
    float x_k[3]   = INITIAL_GUESS;
    float x_km1[3] = INITIAL_GUESS;

    float A[3][3] = {{1,0,-1},{1,2,-1},{2,-1,3}};
    float b[3] = {-4, 4, 18};
    
    int iter; /* Iteration number */
    int i; 
    int j;


    switch(METHOD) {
        /* Method 1: Relaxation parameter method */  
        case(PARAMETER):
            for (iter=0; iter<ITERS; iter++) {
                for (i = 0; i<3; i++) {
                    float sum1=0, sum2=0;
                    for (j=0; j<i; j++) {
                        sum1 += A[i][j]*x_k[j];
                    }
                    for (j=i; j<4; j++) {
                        sum2 += A[i][j]*x_k[j];
                    }
                    x_k[i] += (OMEGA/(A[i][i]))*(b[i] - sum1 - sum2);
                }
                printf("x_(%i):\n", iter);
                printMat1d(x_k);
                printf("\n");
                if (stopCriterion(x_k, x_km1, 3))
                    break;
                /* Copy over results from this iteration */
                copyMat(x_k, x_km1);
            }
            break;

        /* Method 2: Jacobi iteration */
        case(JACOBI):
            for (iter=0; iter<ITERS; iter++) {
                for (i = 0; i<3; i++) {
                    float sum = 0;
                    for (j=0; j<3; j++) {
                        if (j == i)
                            continue;
                        sum += A[i][j]*x_km1[j];
                    }
                    x_k[i] = (1/(A[i][i]))*(b[i] - sum);
                }
                printf("x_(%i):\n", iter);
                printMat1d(x_k);
                printf("\n");
                if (stopCriterion(x_k, x_km1, 3))
                    break;
                /* Copy over results from this iteration */
                copyMat(x_k, x_km1);
            }
            break;

        /* Method 3: Gauss-Siedel */ 
        case(GAUSS_SIEDEL):
            for (iter=0; iter<ITERS; iter++) {
                for (i = 0; i<3; i++) {
                    float sum1=0, sum2=0;
                    for (j=0; j<i; j++) {
                        sum1 += A[i][j]*x_k[j];
                    }
                    for (j=i+1; j<3; j++) {
                        sum2 += A[i][j]*x_k[j];
                    }
                    x_k[i] = (1/(A[i][i]))*(b[i] - sum1 - sum2);
                }
                printf("x_(%i):\n", iter);
                printMat1d(x_k);
                printf("\n");
                if (stopCriterion(x_k, x_km1, 3))
                    break;
                /* Copy over results from this iteration */
                copyMat(x_k, x_km1);
            }
            break;
    }
    
    
    return 0;
}


/* Return true if stop algorithm should stop. */ 
int
stopCriterion(float* current, float* prev, int arrlen) {
    float difference[arrlen];
    int i;
    for (i=0; i<arrlen; i++)
        difference[i] = current[i]-prev[i];

    float num = supNorm(difference, 3);
    float den = supNorm(current, 3);
    float calc = fabs(num)/fabs(den);
    printf("relative precision w/ supremum norm is: %f\n\n\n", calc);
    if (calc < EPSILON) {
        printf("[STOPPING]\nRelative precision of %f has been reached.\n", EPSILON);
        return STOP;
    }
    else 
        return CONTINUE;

    return 2;
}

float 
supNorm(float* arr, int arrlen) {
    int i;
    float max = (arr[0]);
    for (i=0; i<arrlen; i++) {
        if (max < (arr[i]))
            max = (arr[i]);
    }
    return (max);
}

void 
printMat1d(float* mat) {
    printf("%.6f\t\t\t%.6f\t\t\t%.6f\n", mat[0], mat[1], mat[2]);
}

float* 
copyMat(float* val, float* store) {
    int i;
    for (i=0; i<3; i++) 
        store[i] = val[i];
    return store;
}
