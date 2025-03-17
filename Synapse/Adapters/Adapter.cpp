#include "Adapter.h"


Eigenadapter::Eigenadapter()
{


	impl = eigenptr(new Eigen::MatrixXf(2, 2));
	Eigen::MatrixXf* obj = &impl->derived(); //its highly confusing ..have to fix this
	*obj << 1.0f, 2.0f, 3.0f, 4.0f;



}
Eigenadapter::Eigenadapter(Eigen::MatrixXf mtx)
{
	impl = eigenptr(new Eigen::MatrixXf(mtx));
}

Eigenadapter::Eigenadapter(std::initializer_list<std::initializer_list<float>> ilist)
{

	impl = eigenptr(new Eigen::MatrixXf(ilist));

}
void Eigenadapter::t() const 
{



	printf("\n transpose of matrix\n");
	using namespace std;
	{
		Eigen::MatrixXf obj = impl->derived();
		cout << obj.transpose();

	}


	return;

}

void Eigenadapter::print(std::string msg) const
{
	std::cerr<<"\n"<<msg<<"->\n" << impl->derived();
}

Eigenadapter Eigenadapter::operator*(Eigenadapter second)
{
	 //the tmp variable will go out of scope and ptr will be left dangling. To tackle this r-val ref.right now create a copy...for now
	return ( Eigenadapter(Eigen::MatrixXf(impl->derived() * second.impl->derived())));

}