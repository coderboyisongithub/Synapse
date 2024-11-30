#pragma once
#include "types.h"
#include "activators_mat.h"
namespace synp
{
	class AutoAssociator
	{
		Matf src_sig; //source signal
		Matf W; //weight matrix;
		signalType signalt;

	public:
		
		AutoAssociator(int sig_dims, signalType type);
		void memorize(row_space);
		row_space recall(row_space signal);
		void print()
		{
			this->W.print("Associator weights:");
			return;

		}
		Matf getWeight();



	};


	Matf AutoAssociator::getWeight()
	{
		return W;

	}
	AutoAssociator::AutoAssociator(int sig_dims,signalType type)
	{
		signalt = type;

		W = Matf(sig_dims, sig_dims, arma::fill::zeros); // create nxn associative weight with zero initialize

	}
	void AutoAssociator::memorize(row_space signal)
	{
		W+= signal.t() * signal; 

		W.diag().zeros();


		//W.print("associator weights");
	}
	row_space AutoAssociator::recall(row_space signal)
	{
		row_space recall_ = signal * W;
		switch (signalt)
		{
			case BINARY:
			{
				recall_ = synp::binary(recall_);

				break;
			}
			case BIPOLAR:
			{
				recall_ = synp::bipolar(recall_);
			break;
			}
	
		}
		
		//need to fix data structure conflict 
		//need to test activator functions
		return recall_;

	}
}