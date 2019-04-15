/*
 * Author: Alex Hiller
 * Year: 2019
 *
 * Program Description: 
 *    Implementation of the Jacobi, Gauss-Siedel and relaxation parameter
 *    algorithm for approaching solutions for x of Ax=b ⇒ x = A^-1 b
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


enum {JACOBI, GAUSS_SIEDEL, PARAMETER};
enum {CONTINUE, STOP};

/* Params for tuning the approximation */
#define INITIAL_GUESS   {0,0,0}
#define ITERS           1000
/* #define OMEGA           0.1 */
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
    float zeros[3] = INITIAL_GUESS;
    float A[3][3] = {{1,0,-1},{1,2,-1},{2,-1,3}};
    float b[3] = {-4, 4, 18};
    
    int iter; /* Iteration number */
    int i; 
    int j;

    /* FIXME: Not working */
    float OMEGA; /* Make a variable for tuning */
    for (OMEGA=0.1; OMEGA<0.9; OMEGA+=0.1) {
        printf("ω = %f\n", OMEGA);
        copyMat(zeros, x_k);
        copyMat(zeros, x_km1);
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
                printf("Stopped on iteration: %i for ω = %f\n", i, OMEGA);
                break;
            /* Copy over results from this iteration */
            copyMat(x_k, x_km1);
        }
    }

    return 0;
}


/* Return true if algorithm should stop. */ 
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
        printf("[STOPPING]\nRelative precision of %f has been reached.\n", 
                EPSILON);
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
        if (max < arr[i])
            max = arr[i];
    }
    return max;
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
