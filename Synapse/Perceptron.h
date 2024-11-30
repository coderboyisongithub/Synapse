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





/*
                  _________
	         ____/_________\_____
			   /              \  
			  /  ___     ___   \
			  |  \_/     \_/   |
		   \\\|	     'f'       |////
		    \\\\\            //////
			 \\/ \ __---___ / \\\/
			  \/ 			   \/
			 //    \\\///   *  \\
			///    ///\\\      \\\
		   /////             \\\\\\
		  ////////////\\\\\\\\\\\\\\
		 ////////////  \\\\\\\\\\\\\\
		/////////\\\\??/////\\\\\\\\\\
	   ////////\\\\\\\////////\\\\\\\\\
	  ///////   \\\\\\///////  \\\\\\\\\
	 /////       \\\\\//////       \\\\\\
				  {}      {}
			 }{{}}}{}}  {}}{}{{}{


*/