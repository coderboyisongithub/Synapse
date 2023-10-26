#pragma once
#include <math.h>

namespace synp
{

	enum Activatortype
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

	

}