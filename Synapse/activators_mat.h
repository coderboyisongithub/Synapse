#pragma once

#include "types.h"


namespace synp
{


	  Matf bipolar(Matf X)
	{

		
		Matf response(X.n_rows, X.n_cols);
		Matf::iterator it_response = response.begin();
		Matf::iterator it = X.begin();
		Matf::iterator end = X.end();
		
		for (it; it != end; ++it)
		{
			(*it_response) = ((*it) >= 0.0 ? 1.0 : -1.0);
			it_response++;
		}
		return response;
	}
	  Matf binary(Matf X)
	  {

		  Matf response(X.n_rows, X.n_cols);
		  Matf::iterator it_response = response.begin();
		  Matf::iterator it = X.begin();
		  Matf::iterator end = X.end();
		  for (it; it != end; ++it)
		  {
			 ( (*it_response) >= 0.5f ? 1.0f : 0.0f);
			  it_response++;
		  }
		  return response;
	  }
	  Matf identity(Matf X)
	  {
		  return X;
	  }
}
