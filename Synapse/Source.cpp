#include <iostream>
#include <stdio.h>


#include "Perceptron.h">

int main()
{


	synp::perceptron nn(784, 64, 10);

	Matf data(784, 1, arma::fill::randn);
	
	//nn.predict(data);

	return 0;
}