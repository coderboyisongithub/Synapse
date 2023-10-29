#pragma once

#include <armadillo>
#include "types.h"
namespace synp
{


	namespace hebbs
	{
		/// <summary>
		/// implements hebbs update over weight and bias
		/// </summary>
		/// <param name="X">input  matrix</param>
		/// <param name="W">weight matrix</param>
		/// <param name="B">Bias matrix</param>
		/// <param name="k">learning coeffecient=1 for bipolar hebbs learning?=variable if using perceptron</param>
		void learn(Matf X,Matf W,Matf B, coeffecient k = 1)
		{

			W += k * (W % X); //elementwise multiplication
			B += k * X;
			
		}
	 }
}