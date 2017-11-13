### C-Dynamic-Array, non generic (int) implementation
   General remarks
	 The last possible memory allocation (8GIG internall RAM) for 2^n (resize 200%
	 implementation)is: 1070000000 size integer array;
	 the last allocation for n + n / 2(resize 150% implementation - current!) is  1500000000
	 size integer array;
	 time complexity similar, only 2o more resizing: #resize 50 now, 30 for 2^n implementation.
	 C++ std:vector last allocation 1070000000 integers.
   
	
