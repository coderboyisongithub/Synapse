#include "Adapter.h"
#include <typeinfo>

// working on row,col constructor


Eigenadapter::Eigenadapter()
{
	impl = eigenptr(new Eigen::MatrixXf(2, 2));
}



Eigenadapter::Eigenadapter(Eigenadapter& obj)
{
	std::cerr << "\n copy called";
	impl = eigenptr(new Eigen::MatrixXf(obj.impl->derived()));
}


Eigenadapter::Eigenadapter(Eigenadapter&& obj)
{
	std::cerr << "\n move called";
	impl = eigenptr(new Eigen::MatrixXf());
}




Eigenadapter::Eigenadapter(size_t row, size_t col)
{
	impl = eigenptr(new Eigen::MatrixXf(row,col));
	impl->derived().Random();
	this->print();

}


Eigenadapter::Eigenadapter(Eigen::MatrixXf mtx)
{
	impl = eigenptr(new Eigen::MatrixXf(mtx));
}


Eigenadapter::Eigenadapter(std::initializer_list<std::initializer_list<float>> ilist)
{

	impl = eigenptr(new Eigen::MatrixXf(ilist));

}


//Member functions



void Eigenadapter::t() const 
{

	std::cerr << "work underway trannspose";
	abort();
	return;

}



void Eigenadapter::print(std::string msg) const
{
	std::cerr<<"\n"<<msg<<"->\n" << impl->derived();
}



/// Operators
//need a move operator



void Eigenadapter::operator=(Eigenadapter&& second)
{

	std::cerr << "\n move operator";
}
//void Eigenadapter::operator=(Eigenadapter &second)
//{
//
//
//	//doee it perform eigen deep copy or shallow copy
//	(*impl).derived() = (*second.impl).derived();
//	//now what about second.impl??
//}





Eigenadapter Eigenadapter::operator*(Eigenadapter& second)
{
	//the tmp variable will go out of scope and ptr will be left dangling. To tackle this r-val ref.right now create a copy...for now
   //This will call two copy constructor one for this and another for returning tmp adapter
	std::cerr << "\noperator: *";
	return (Eigenadapter(Eigen::MatrixXf(impl->derived() * second.impl->derived())));

}



Eigenadapter Eigenadapter::operator+(Eigenadapter &second)
{

	//this is using copy.. while resulted can be just moved.
	//the result will be moved only not the operand.
	return Eigenadapter((*impl).derived() + (*second.impl).derived());
}




Eigenadapter Eigenadapter::operator-(Eigenadapter &second)
{
	//same need for move over copy
	return Eigenadapter((*impl).derived() + (*second.impl).derived());

}


//void Eigenadapter::operator/(float first)
//{
//
//	return Eigenadapter((*impl).derived() / first);
//
//}






