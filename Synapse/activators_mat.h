#pragma once

#include "types.h"
#include "Activators.h"

namespace synp
{

	  Matf bipolar(Matf X)
	{

		Matf::iterator it = X.begin();
		Matf::iterator end = X.end();
		for (it; it != end; ++it)
		 ((*it) >= 0.0f ? 1.0f : -1.0f);
		return X;
	}
	  Matf binary(Matf X)
	  {

		  Matf::iterator it = X.begin();
		  Matf::iterator end = X.end();
		  for (it; it != end; ++it)
			  ((*it) >= 0.0f ? 1.0f : 0.0f);
		  return X;
	  }
	  Matf identity(Matf X)
	  {
		  return X;
	  }
}
