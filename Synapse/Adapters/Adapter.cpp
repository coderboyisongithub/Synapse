#include "Adapter.h"


Eigenadapter::Eigenadapter()
{


	impl = eigen(new Eigen::MatrixXf(2, 2));
	Eigen::MatrixXf* obj = &impl->derived(); //its highly confusing ..have to fix this
	*obj << 1.0f, 2.0f, 3.0f, 4.0f;



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