
#include "Matf_.h"
/*
-need to implement the following..
- copy constructor.
- operators =,/,%,-,\*
- need to take care of ownership and check for dangling pointers 
issue
- implement interface necceary for building neural networks
- also a way to use raw eigen object and load into interface when required.
- memory management and optimization will be the last this has to be well thought with operators

*/


Matf::Matf()
{
	impl = new Eigenadapter;
}



Matf::Matf(Matf& obj)
{

	//std::cerr << "\nmatf copy constructor";
	impl = new Eigenadapter(*obj.impl);
}


// this is where I was working on..I was working on implementing move constructor for matf
Matf::Matf(Matf&& obj)
{
	//The goal of a move consytructor shall be to perform complete owner
	//ship of adapter and trasnfer to target.
	//here ownership is a pointer to 

	//std::cerr << "\nMatf Move constructor";
	this->impl = obj.impl;
	obj.impl = nullptr;
	return; 
}


Matf::Matf(Eigenadapter obj,bool move)
{
	move = true;
	switch (move)
	{
	case false:
	{
		impl = new Eigenadapter(obj);
		break;
	}
	case true:
	{

		//Eigenadapter tmp=std::move(obj)
		impl = new Eigenadapter(std::move(obj));//? how to solve this?
		break;
	}
	}
	return;
	
}


Matf::Matf(size_t row, size_t col)
{
	impl = new Eigenadapter(row, col);
}



Matf::Matf(std::initializer_list<std::initializer_list<float>>list)
{
	impl = new Eigenadapter(list);
	
}

Matf::~Matf()
{
	
	// maft allocates adapter in heap. so matf cleans adapter responsibly
	//adapter allocates matrix in heap. adapter cleans matrix responsible
	delete impl;
	impl = nullptr;
}


void Matf::t()
{
	impl->t();
	return;
}

void Matf::debug()
{
	std::cout<<"\n constructors called "<< impl->get().first;
	std::cout <<"\n Destructors called "<<impl->get().second;
}


void Matf::print(std::string msg)
{
	checkfor(impl != nullptr, "Matf maybe moved or deleted");
	impl->print(msg);
}


Matf  Matf::operator*(Matf &second)
{ 
	//this will trigger * operator of eigen adapter and will return and multiplied eigen adapter.
	

	// It can be moved later..in later work.
	//What to do here?? How can I pass adapter to mat f without giving a way
	// to initialize matf with adapter...this is what I dont want to expose.

	return std::move((	 (*impl) * (*(second.impl)	)));
}


//void Matf::operator=(Matf second)
//{
//	*impl = *second.impl;
//}




void Matf::operator=(Matf& second)
{
//	std::cerr << "\n Matf copy assign";
	*impl = *second.impl;
	 
}


void Matf::operator=(Matf&& second)
{
	//std::cerr << "\n Matf move assign";
	this->impl = second.impl;
	second.impl = nullptr;
	return;
}



Matf Matf::operator-(Matf& second)
{

	return std::move(Matf((*impl)	-	(*(second.impl))));
}




Matf Matf::operator+(Matf& second)
{
	//std::cerr << "\n Matf + operator";
	return   std::move(	Matf((*impl) + (*(second.impl)	))); //the Matf is initialized with a new adapter of that has sum
}


