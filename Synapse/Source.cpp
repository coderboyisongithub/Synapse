#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS

#include "Adapters/Matf_.h"

//revise auto associative memory.(outer product)

int main()
{

	Matf w1{ {1,2},{3,4} }, w2{ {0,0},{0,0} };

	w1.print("weight1");
	w2.print("weight2");

	w1* w2;
	

	return 0;
}