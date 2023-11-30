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


	};


	AutoAssociator::AutoAssociator(int sig_dims,signalType type)
	{
		signalt = type;

		W = Matf(sig_dims, sig_dims, arma::fill::zeros); // create nxn associative weight with zero initialize

	}
	void AutoAssociator::memorize(row_space signal)
	{
		W+= signal.t() * signal; 

		W.print("associator weights");
	}
	row_space AutoAssociator::recall(row_space signal)
	{
		row_space recall_ = signal * W;
		recall_=synp::bipolar(recall_);
		//need to fix data structure conflict 
		//need to test activator functions
		return recall_;

	}
}