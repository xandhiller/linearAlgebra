#ifndef STD_HEADERS_H
#define STD_HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#endif

struct matrix {
  int rows;
  int columns;
  int nbElements;
  double* array;    /* Pointer to array. Used due to variable dimensions.   */
};
typedef struct matrix matrix_t;

void testMatrix(const matrix_t* m);  
void testMatrixElmAddress(const matrix_t* m);
matrix_t* matrixInit(int r, int c);
void printMatrix(const matrix_t m);
