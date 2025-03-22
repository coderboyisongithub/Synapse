#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS

#include "Adapters/Matf_.h"

//revise auto associative memory.(outer product)

/*
Report: operators are not working properly. it has been declered and defined\
but yet to function properly..

TO WORK ON NEXT: like assignment operator runs without error but does no change to matrix.

*/


int main()
{

	Matf w3{ {1,1},{1,1} };
	
	
	{
		Matf w1{ {1,2},{3,4} }, w2{ {0,0},{0,0} };
		w1.print("w1");
		w2.print("w2");
		w3 = w2 * w3+w1;
	}

	w3.print("w3");
	Matf w4(w3);
	(w4+w4).print("w??");
	
	
	
	//w2.print("weight2");

	return 0;
}