#pragma once


#include <armadillo>
#include "types.h"
#include "Activators_mat.h"
namespace synp
{

	class perceptron
	{
	public:

		Matf weight_layer2;
		Matf weight_layer3;
		Matf weight_layer1;

		perceptron(unsigned int input_neurons, unsigned int hidden_neurons, unsigned int output_neurons);
		void train(Matf input, Matf target);
		Matf infer(Matf input);


	};

}


synp::perceptron::perceptron(unsigned int input_neurons, unsigned int hidden_neurons, unsigned int output_neurons)
{

	weight_layer1 = Matf(input_neurons, input_neurons, arma::fill::randn);
	weight_layer2 = Matf(input_neurons, hidden_neurons, arma::fill::randn);
	weight_layer3 = Matf(hidden_neurons, output_neurons, arma::fill::randn);
}

/// <summary>
/// perceptron learning rule :Generalized hebbs rule
/// </summary>
/// <param name="input">Bipolar or binary values</param>
/// <param name="target">Binary values</param>
void  synp::perceptron::train(Matf input,Matf target)
{
	float error = INFINITY;
	int samples = input.n_rows;
	float tolerance = 0.1;
	float learning_rate = 0.01;
	signed int epoch = 1;


	//input layer response

	for (int sample = 0; sample < input.n_rows; sample++)
	{
		//assuming single neuron output in output layer
		float response = infer(input.row(sample)).row(0)[0];
		
		float error = abs(response - target.row(sample)[0]);
			if (error > tolerance)
			{
				Matf sigma_sum = input * weight_layer1;
				Matf learning_signal = synp::identity(sigma_sum);
				for (int col_space = 0; col_space < weight_layer2.n_cols; col_space++)
				{
					weight_layer2.col(col_space) += learning_rate * (learning_signal * target.row(0)[0]);
				}

			}
		

		
	}




}

Matf synp::perceptron::infer(Matf input)
{
	Matf sigma_sum = input * weight_layer1;
	Matf response = synp::identity(sigma_sum);

	sigma_sum = response * weight_layer2;
	response = synp::binary(sigma_sum);


	sigma_sum = response * weight_layer3;
	response = synp::binary(sigma_sum);

	return response;

}
