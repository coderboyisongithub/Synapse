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


	std::vector<Matf> v;
	Matf w3{ {1,1},{1,1} };
	Matf idt{ {1,0},{0,1} };
	//w2.print("weight02");
	w3.print();
	idt.print();
	return 0;
}