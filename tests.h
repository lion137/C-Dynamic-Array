// tests subroutine

#ifndef tests_h
#define tests_h

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dynamic_array.h"

void tests(){
	//constructor
	array_int * ar_test = array_int_init();
	assert(ar_test != NULL);
	assert(is_empty(ar_test)); 
	assert(size(ar_test) == 0); 
	
	//append, size and empty
	append(ar_test, 1); // append 1
	assert(size(ar_test) == 1); 
	append(ar_test, 2); // append 2
	append(ar_test, 3); // append 3
	assert(size(ar_test) == 3); 
	assert( !(is_empty(ar_test)) );
	assert(ar_test->a[0] == 1);
	assert(ar_test->a[2] == 3);
	
	//get_nth
	assert(nth(ar_test, 0) == 1);
	assert(nth(ar_test, 2) == 3);
	
	//update
	update(ar_test, 10, 0);
	assert(nth(ar_test, 0) == 10);
	update(ar_test, 12, 2);
	assert(nth(ar_test, 2) == 12);
	
	//pop, size and empty
	assert(pop(ar_test) == 12); // pop!
	assert(size(ar_test) == 2); 
	assert(pop(ar_test) == 2); // pop!
	assert(size(ar_test) == 1); 
	assert( !(is_empty(ar_test)) );
	assert(pop(ar_test) == 10); // pop!
	assert(size(ar_test) == 0); 
	assert( (is_empty(ar_test)) );
	
	//delete
	delete(ar_test);
	assert(ar_test->a == NULL);
	ar_test = NULL;
	assert(ar_test == NULL);
	printf("%s\n", "Tests Passed!");
	}

#endif
