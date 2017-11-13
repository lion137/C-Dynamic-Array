// dynamic array of integers: structure definition and functions

#ifndef dynamic_array_h
#define dynamic_array_h
#include <assert.h>

// define the integer holds, dynamic array new type:

typedef struct {
	 int n;
	 int c;
	 int  * a;
	} array_int;

// functions declarations: ---------------------------------------------

void append(array_int * obj, int elem);
int nth(array_int * obj, int in);
void update(array_int * obj, int elem, int in);
int pop(array_int * obj); // pop last, O(1)
int is_empty(array_int * obj);
int size(array_int * obj);
void print(array_int * obj);
void delete(array_int * obj);
void _resize_int_array(array_int * obj, int capacity); // resize array - helper

// functions: ----------------------------------------------------------

 // constructor
array_int * array_int_init(){
	array_int * obj = (array_int *) malloc(sizeof(array_int));
	obj->n = 0;
	obj->c = 0;
	if (obj == NULL) {
		fprintf(stderr, "%s", "Int array, constructor: Malloc failed!\n");
		abort();
	}
	return obj;
	}

// add at the end
void append(array_int * obj, int elem){
	if (obj->a == NULL){
		int *tmp = malloc( 2 * sizeof(int));
		obj->a = tmp;
		obj->a[obj->n] = elem;
		++(obj->n); 
		obj->c = 2;
		obj->c = 2 * obj->c;
		}
	else{
	if (obj->n == obj->c){
		_resize_int_array(obj, 2 * obj->c); 
		obj->c = obj->c + (obj->c) / 2; 
		obj->a[obj->n] = elem;
		++(obj->n);
	}
	else{
	obj->a[obj->n] = elem;
	(obj->n)++;
		}
	}
}

 // get the nth element, abort if out of range
int nth(array_int * obj, int in){
	if (is_empty(obj)) {
		fprintf(stderr, "%s", "Int array: Peek empty array!\n");
		abort();
		}
	if ( in >= obj->n || in < 0) {
		fprintf(stderr, "%s", "Int array(get): Index  out of scope!\n");
		abort();
	}
	return obj->a[in];
}

// update n - th element
void update(array_int * obj, int elem, int in){
	if (is_empty(obj)) {
		fprintf(stderr, "%s", "Int array: Update empty array!\n");
		abort();
		}
	if ( in >= obj->n || in < 0) {
		fprintf(stderr, "%s", "Int array (set): Index  out of scope!\n");
		abort();
	}
	obj->a[in] = elem;
}
 
// remove and return the last elem, O(1)
int pop(array_int * obj){
	if (is_empty(obj)) {
		fprintf(stderr, "%s", "Int array: Pop empty array!\n");
		abort();
		}
	int out = obj->a[obj->n - 1];
	obj->a[obj->n - 1] = NULL;
	--(obj->n);
	//shrink the array
	if ( (obj->n > 0) && (obj->n) == (size(obj) / 4) )
		_resize_int_array(obj, size(obj) / 2);
	return out;
	}
	
int is_empty(array_int * obj){
	return obj->n == 0;
	}	
	
int size(array_int * obj){
	return obj->n;
	}

// delete and print: ---------------------------------------------------
	
void print(array_int * obj){
	int ctrl = obj->n;
	int index = 0;
	if (obj->n == 1) printf("[%d]", obj->a[0]);
	else{
	if (ctrl > 30) index = 30;
		else index = obj->n;
	printf("[");
	for (int i = 0; i < index; i++){
		if (i == index - 1){
			printf("%d", obj->a[i]);
			break;
			}
		printf("%d, ", obj->a[i]);
	}
	if (index == 30) {
		printf(", . . . , ");
		printf("%d, %d", obj->a[obj->n - 2], obj->a[obj->n - 1]);
		}
	printf("] Size: ");
	printf("%d", obj->n);
	}
}

void delete(array_int * obj){ // free memory
	free(obj->a);
	free(obj);
	obj->a = NULL;
	}

// helpers: ------------------------------------------------------------

void _resize_int_array(array_int * obj, int capacity){//dynamic resize and rehash via realloc
	assert(capacity >= obj->n);
	obj->a = realloc (obj->a, capacity * sizeof(int)); 
	if (obj->a == NULL) {
		fprintf(stderr, "%s", "Int array: Malloc failed!\n");
		abort();
	}
}
#endif
