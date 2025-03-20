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

	Matf w1{ {1,2},{3,4} }, w2{ {0,0},{0,0} }, w3{ {1,1},{1,1} };

	w1.print("weight1");
	//w2.print("weight2");

	w1=w2;

	w1.print("updated weight 1");
	

	return 0;
}