#include <iostream>
#include <stdio.h>
#include <chrono>


#define ARMA_PRINT_EXCEPTIONS

#include "Adapters/Matf_.h"

//revise auto associative memory.(outer product)

/*
Report: operators are not working properly. it has been declered and defined\
but yet to function properly..

TO WORK ON NEXT: dev branch build fails when cloned;

*/


int main()
{
	
	Matf w3{ {1,1},{1,1} };
	Matf idt{ {1,0},{0,1} };
	//w2.print("weight02");
	Matf w4 = w3;



	w3.print("matrix w3");
	w4.print("matrix w4 copy-w3");
	Matf w5 = std::move(w3);
	
	w5.print("matrix w5 move-w3");

	(idt - idt).print("diff idt ");

	(idt + idt).print("sum idt");
	(idt * idt).print("mul idt");

	//w3.print("w3 after moved");// this will trigger error as w3 has been moved to w5;

	
	
	
	

	return 0;
}