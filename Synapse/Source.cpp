#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS
#include "Perceptron.h"


int main()
{


	synp::perceptron nn(784, 64, 10);

	

	Matf data(784, 1, arma::fill::randn);

	Matf response=nn.predict(data.t());

	response.t().print();


	return 0;
}