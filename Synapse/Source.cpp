#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS
#include "Perceptron.h"


int main()
{


	synp::perceptron net(2, 2, 1);
	Matf dataset(
		{{0,0,1},
		{0,1,0},
		{1,0,0},
		{1,1,1} }
	);

	Matf target = dataset.col(2);

	net.train(dataset.cols(arma::span(0, 1)), dataset.col(2));

	return 0;
}