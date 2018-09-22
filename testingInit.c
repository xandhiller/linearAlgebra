#include "cla.h"

int main (void) {

  matrix_t* mat = matrixInit(3,3,3);

  printMatrix(mat);

  printf("%lf\n", mat->array[8]);

  printf("%lf\n", mat->array[9]);


  return 0;
}
