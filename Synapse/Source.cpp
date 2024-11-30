#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS
#include "Perceptron.h"
#include <assert.h>
#include "Auto_associator.h"

#include "point generator/generator.h"



void conv2D(Matf signal, Matf kernel)
{
	
	//signal.insert_cols(0, 1);

	// signal=arma::fft(signal,128);
	signal.print("padded signal");

	row_space response(signal.n_cols+kernel.n_cols,signal.n_rows+kernel.n_rows);



	response.print("response");

	
	


	return;
}



int main()
{





	synp::AutoAssociator mem(4, signalType::BIPOLAR);

std::vector<row_space> signals;
//
	//synp::perceptron mlp(1024, 1024, 10);




	
	

	signals.push_back({ 1, 1,1,-1});

	mem.memorize(signals[0]);
	
	mem.recall({ -1,-1,0,1 }).print("recall");

	mem.getWeight().print("weight");

	
	row_space signal{ 1,2,3,4,5,6 }, kernel{ 1,2,2,1 } ;

	signal.print("signal");
	kernel.print("kernel");


	printf("hello");

	float a = kernel[3];






//ftconv1D(signal, kernel);




		return 0;;
}