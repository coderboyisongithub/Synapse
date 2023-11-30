#pragma once
#include <math.h>

namespace synp
{
	//using scoped enum to avoid decl conflicts.
	enum class Activatortype
	{
		linear=0,
		sigmoid,
		bipolar,
		bipolar_sigmoid,
		relu
	}; 

	float sigmoid(float x) { return (1 / (1 + exp2f(-x))); }
	float linear(float x) { return x; }
	float bipolar(float x) { return (x >= 0 ? 1 : -1); }
	float bipolar_sigmoid(float x) { return 0; }
	float relu(float x) { return (x>=0?x:0); }

#ifdef INLINE_ACTIVATORS_FUNCTIONS


	inline float sigmoid(float x) { return (1 / (1 + exp2f(-x))); }
	inline float linear(float x) { return x; }
	inline float bipolar(float x) { return (x >= 0 ? 1 : -1); }
	inline float bipolar_sigmoid(float x) { return 0; }
	inline float relu(float x) { return (x >= 0 ? x : 0); }

#endif
	

}