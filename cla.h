#ifndef STD_HEADERS_H
#define STD_HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#endif


/* TODO: Variable data types for matrices. */
/*enum dataType { */
/*  INT8, */
/*  INT16, */
/*  INT32, */
/*  INT64, */
/*}; */


struct matSize {
  int rows;
  int columns;
  int depth;
  int numElements;
};
typedef struct matSize matSize_t;

struct matrix {
  matSize_t size;   /* Size of array for user and iteration purposes.       */ 
  double* array;    /* Pointer to array. Used due to variable dimensions.   */
};
typedef struct matrix matrix_t;


matrix_t* matrixInit(int r, int c, int d) {
  matrix_t* m = (matrix_t*) malloc(sizeof(matrix_t *));    
      
  m->size.numElements = r*c*d;
  m->array = (double*)calloc(m->size.numElements, sizeof(double));   
  m->size.rows     = r;
  m->size.columns  = c;
  m->size.depth    = d;


  /* zero the elements */

  return m;
}

void printMatrix(const matrix_t* m) {  
  int i, j, k, p, q;
  q=1;
  for(p=0, k = 0; k < m->size.depth; k++) {
    printf("Frame %d:\n", k+1);

    for(i = 0; i < m->size.rows; i++) {  
      for(j = 0; j < m->size.columns; j++) {  
        m->array[i+j+p] = q;
        q++;
        printf("%.2lf\t", m->array[i+j+p]);  
      } 
    p = p + m->size.columns; 
    printf("\n");  
    } 
  
  } 
}
