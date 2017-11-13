#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "dynamic_array.h"
#include "tests.h"

int main(){
	 array_int * ar1 = array_int_init();
	assert(ar1 != NULL);
	assert(ar1->a == NULL);
	 
	for (long i = 0; i<1070000000;i++){  
		append(ar1, 1);   								 
		}
	//print(ar1);
	//printf("\n");
	delete(ar1);
	ar1 = NULL;
	//tests();
	return 0;
	}
