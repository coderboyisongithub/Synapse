#pragma once

#include <armadillo>
#include "types.h"
#include "hebbs.h"
#include "activators_mat.h"
namespace synp
{

	class perceptron 
	{
	public:

		Matf weight_layer2;
		Matf weight_layer3;
		Matf weight_layer1;

		perceptron(unsigned int input_neurons,unsigned int hidden_neurons,unsigned int output_neurons)
		{

			 weight_layer1=Matf(input_neurons, input_neurons, arma::fill::randn);
			 weight_layer2=Matf(input_neurons, hidden_neurons, arma::fill::randn);
			 weight_layer3=Matf(hidden_neurons, output_neurons, arma::fill::randn);
		}


		void train()
		{
			
		}
	
		Matf predict(Matf input)
		{
			Matf sigma_sum = input * weight_layer1;
			Matf response = synp::bipolar(sigma_sum);

			 sigma_sum = response * weight_layer2;
			 response = synp::bipolar(sigma_sum);

			 sigma_sum = response * weight_layer3;
			 response = synp::bipolar(sigma_sum);

			return response;

		}

		
	};
}