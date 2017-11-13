#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "dynamic_array.h"
#include "tests.h"

int main(){
	//example
	array_int * ar1 = array_int_init();
	for (long i = 0; i<1000000000;i++){  
		append(ar1, 1);   								 
		}
	print(ar1);
	printf("\n")
	delete(ar1);
	ar1 = NULL;
	tests();
	return 0;
	}
