#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//C function
double dotProductC(double vectorA, double vectorB, double vectorsize) {
	double output = 0.0;
	for (int i=0;i<vectorsize;i++) {
		output = output + vectorA * vectorB;
		vectorA += 0.001;	//next element of A is +0.001
		vectorB += 0.1;		//next element of B is +0.1
	}
	return output;			//return dotProduct
}

//extern ASM function
extern double asmDotProduct();

int main() {

	//init vector values
	double vecA = 0.001;			//A 1st vector element; increments by 0.001 for next element (i.e. vecA = {0.001, 0.002, 0.003, ...})
	double vecB = 0.1;				//B 1st vector element; increments by 0.1 for next element   (i.e. vecB = {0.1, 0.2, 0.3, ...})
	double n = 1048576;			//vector size (choose: 2^20 = 1048576 | 2^24 = 16777216 | 2^30 = 1073741824)
	
	double sdot; 
	
	//Start measure time
	clock_t start, stop;
	start = clock();

	//Call C or ASM (choose 1)
	//sdot = dotProductC(vecA, vecB, n);	//C
	sdot = asmDotProduct(vecA, vecB, n);	//ASM
	
	//End measure time
	stop = clock();

	//Test C or ASM (choose 1)
	//printf("C Output (size %.0lf) = %lf\n", n, sdot);		//C
	printf("ASM Output (size %.0lf) = %lf\n", n, sdot);		//ASM

	//Time elapsed
	printf("\n\nTime measured: %.5f seconds\n\n", (double)(stop-start)/CLOCKS_PER_SEC);

	return 0;
}