
/*
 * Author: Alex Hiller
 * Year: 2019
 *
 * Program Description: 
 *    
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


/* #define  */


/* enum {}; */


int main (int argc, char *argv[]) {
    int i;
    for (i=0; i<10; i++) {
        if (i==8) 
            continue;
        printf("%i\n", i);
    }

    return 0;
}
