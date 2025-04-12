#include "Adapter.h"



class Matf
{
	/*
	* This class is warper to implementation of eigen adapter. 
	 "impl" is pointer to Eigenadapter. The adapter has uniq_ptr to eigenbase
	*/

	
	Eigenadapter* impl;  //
	Matf(Eigenadapter obj, bool move = false);

public:
	
	
	Matf();
	
	
	Matf(size_t row, size_t col);
	
	Matf(Matf&& obj);
	

	
	
	Matf(std::initializer_list<std::initializer_list<float>> list);
	
	
	Matf(Matf& obj);


	void t();
	void print(std::string msg = { "" });
	
	
	
	Matf operator*(Matf &second);


	//Matf operator*(Matf&& second)
	// 
	// 
	


	void operator=(Matf& second);

	void operator=(Matf&& second);

	Matf operator-(Matf& second);


	Matf operator+(Matf& second);
};