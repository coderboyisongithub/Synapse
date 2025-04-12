#include "Adapter.h"
#include <typeinfo>

// working on row,col constructor


Eigenadapter::Eigenadapter()
{
	uptr = eigenptr(new Eigen::MatrixXf(2, 2));
}



Eigenadapter::Eigenadapter(Eigenadapter& obj)
{
	//std::cerr << "\n Adapter copy called";
	uptr = eigenptr(new Eigen::MatrixXf(obj.uptr->derived()));
}


Eigenadapter::Eigenadapter(Eigenadapter&& obj)
{
	//std::cerr << "\n Adapter move called";
	uptr = std::move(obj.uptr); //what will this move?? pointer only or whole matrix ownership 
	//..its a unique ptr..If I move then obj will have to be nullified otherwise its not unique

}




Eigenadapter::Eigenadapter(size_t row, size_t col)
{
	uptr = eigenptr(new Eigen::MatrixXf(row,col));
	uptr->derived().Random();
	this->print();

}


Eigenadapter::Eigenadapter(Eigen::MatrixXf mtx)
{
	uptr = eigenptr(new Eigen::MatrixXf(mtx));
}


Eigenadapter::Eigenadapter(std::initializer_list<std::initializer_list<float>> ilist)
{

	uptr = eigenptr(new Eigen::MatrixXf(ilist));

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
	checkfor(uptr != nullptr,"Adapter maybe moved or deleted");
	std::cerr<<"\n"<<msg<<"->\n" << uptr->derived();
}



/// Operators
//need a move operator




void Eigenadapter::operator=(Eigenadapter &second)
{
	//std::cerr << "\n adapter copy assign";

	//doee it perform eigen deep copy or shallow copy
	(*uptr).derived() = (*second.uptr).derived();
	//now what about second.uptr??
}
void Eigenadapter::operator=(Eigenadapter&& second)
{

	//std::cerr << "\n adapter move assign";
	//doee it perform eigen deep copy or shallow copy
	(*uptr).derived() = std::move((*second.uptr).derived());
	//now what about second.uptr??
}





Eigenadapter Eigenadapter::operator*(Eigenadapter& second)
{
	//the tmp variable will go out of scope and ptr will be left dangling. To tackle this r-val ref.right now create a copy...for now
   //This will call two copy constructor one for this and another for returning tmp adapter
	//std::cerr << "\noperator: *";
	Eigen::MatrixXf tmp = std::move((uptr->derived()) * (second.uptr->derived()));
	return (std::move(tmp));

}



Eigenadapter Eigenadapter::operator+(Eigenadapter &second)
{
	//std::cerr << "\n adapter + operator";

	//Now the temp results are moved to adapter pointer in matf;
	return std::move((*uptr).derived() + (*second.uptr).derived());
}




Eigenadapter Eigenadapter::operator-(Eigenadapter &second)
{
	//same need for move over copy
	return Eigenadapter((*uptr).derived() - (*second.uptr).derived());

}


//void Eigenadapter::operator/(float first)
//{
//
//	return Eigenadapter((*uptr).derived() / first);
//
//}






