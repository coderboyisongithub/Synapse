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
	impl = new Eigenadapter(*obj.impl); 
}


// this is where I was working on..I was working on implementing move constructor for matf
Matf::Matf(Matf&& obj)
{
	
}



Matf::Matf(size_t row, size_t col)
{
	impl = new Eigenadapter(row, col);
}



Matf::Matf(std::initializer_list<std::initializer_list<float>>list)
{
	impl = new Eigenadapter(list);
	
}




void Matf::t()
{
	impl->t();
	return;
}




void Matf::print(std::string msg)
{
	impl->print(msg);
}


Matf  Matf::operator*(Matf &second)
{ 
	//this will trigger * operator of eigen adapter and will return and multiplied eigen adapter.
	Eigenadapter tmp = std::move((*impl) * (*(second.impl)));

	// It can be moved later..in later work.
	//What to do here?? How can I pass adapter to mat f without giving a way
	// to initialize matf with adapter...this is what I dont want to expose.

	return Matf(tmp);
}


//void Matf::operator=(Matf second)
//{
//	*impl = *second.impl;
//}




void Matf::operator=(Matf second)
{
	*impl = std::move(*second.impl);
	 
}




Matf Matf::operator-(Matf second)
{

	return Matf((*impl)	-	(*(second.impl)));
}




Matf Matf::operator+(Matf second)
{
	return Matf((*impl) + (*(second.impl)));
}


