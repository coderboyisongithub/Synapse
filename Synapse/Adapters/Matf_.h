#include "Adapter.h"

class Matf
{
	/*
	* This class is warper to implementation of eigen adapter. 
	 "impl" is pointer to Eigenadapter. The adapter has uniq_ptr to eigenbase
	*/
	 Eigenadapter* impl;
public:
	Matf();
	Matf(std::initializer_list<std::initializer_list<float>> list);
	void t();
	void print(std::string msg = { "" });
	Matf operator*(Matf second);
};