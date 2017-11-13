### C-Dynamic-Array, non generic (int) implementation    
Copyleft 2017 by lion137     

   General remarks   
     The last possible memory allocation (8GIG internall RAM) for 2^n (resize 200%
	 implementation)is: 1070000000 size integer array;
	 the last allocation for n + n / 2(resize 150% implementation - current!) is  1500000000
	 size integer array;
	 time complexity similar, only 2o more resizing: #resize 50 now, 30 for 2^n implementation.
	 C++ std:vector last allocation 1070000000 integers.    
	 
	 Usage:    
	 array_int * x = array_int_init(); // constructor    
	 functions over structure, all O(1):    
	 - append (add at the end);    
	 - pop;    
	 - size;    
	 - is_empty;  
	 - nth(obj, index) (peek the indexed element in the array);    
	 - update(obj, elem, ind) (sets the ind - th elementh in the array to elem)    
	 - print.      
	 Delete object by call delete(obj) and set obj to NULL.
   
	
