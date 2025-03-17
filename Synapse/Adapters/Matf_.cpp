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
Matf  Matf::operator*(Matf second)
{	
	// work remaining
	printf("\n multiplication operator:::: work remaining");
	return Matf();
}
