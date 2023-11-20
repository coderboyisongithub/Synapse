#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS
#include "Perceptron.h"
#include "Auto_associator.h"

int main()
{


	synp::perceptron net(2, 2, 1);
	Matf dataset(
		{{0,0,1},
		{0,1,0},
		{1,0,0},
		{1,1,1} }
	);

	synp::AutoAssociator mem(3,signalType::BINARY);


	row_space pattern({ 1,0,1 });
	pattern.print();
	mem.memorize(pattern);
	mem.recall(row_space({ 1,0,1 }));

	return 0;
}