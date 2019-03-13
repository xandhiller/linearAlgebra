/*
 * Author: Alex Hiller
 * Year: 2019
 * Program Description: C Linear Algebra
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "cla.h"

void testMatrixElmAddress(const matrix_t* m) {  
  int i, j, k, q;
  q=0;
  for(i = 0; i < m->rows; i++) {  
    for(j = 0; j < m->columns; j++) {  
      m->array[i+j] = q;
      q++;
      printf("%p\t", &(m->array[i+j]));  
    } 
  printf("\n");  
  } 
}

void testMatrix(const matrix_t* m) {  
  int i, j, k, q;
  q=0;
  for(i = 0; i < m->rows; i++) {  
    for(j = 0; j < m->columns; j++) {  
      m->array[i+j] = q;
      q++;
      printf("%.2lf\t", m->array[i+j]);  
    } 
  printf("\n");  
  } 
}

matrix_t* matrixInit(int r, int c) {
  matrix_t* m = (matrix_t*) malloc(sizeof(matrix_t *));    
  m->nbElements = r*c;
  m->array = (double*)calloc(m->nbElements, sizeof(double));   
  m->rows     = r;
  m->columns  = c;
  return m;
}


void printMatrix(const matrix_t m) {
  int i, j, k;
  for(i = 0; i < m.rows; i++) {  
    for(j = 0; j < m.columns; j++) {  
      printf("%.2lf\t", m.array[i+j]);  
    } 
  printf("\n");  
  } 
}


/********* MAIN *********/
int main (int argc, char *argv[]) { 
  matrix_t* testM = matrixInit(3,3);
  printMatrix(*testM);
  return 0;
}
