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
		Matf predict(Matf input);


	};

}


synp::perceptron::perceptron(unsigned int input_neurons, unsigned int hidden_neurons, unsigned int output_neurons)
{

	weight_layer1 = Matf(input_neurons, input_neurons, arma::fill::randn);
	weight_layer2 = Matf(input_neurons, hidden_neurons, arma::fill::randn);

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
	while (epoch < 10)
	{
		for (int sample = 0; sample < samples; sample++)
		{
			Matf response = predict(input.row(sample));
			error = target.row(sample)[0] - response.row(0)[0];
			printf("\n error: %f", error);
			if (error > tolerance)
			{
				weight_layer2 += learning_rate * (input.t() * target);

			}

		}
		puts("\n\n");
		epoch++;
	}




}

Matf synp::perceptron::predict(Matf input)
{
	Matf sigma_sum = input * weight_layer1;
	Matf response = synp::bipolar(sigma_sum);

	sigma_sum = response * weight_layer2;
	response = synp::bipolar(sigma_sum);

	return response;

}
