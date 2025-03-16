
#include <Eigen/Core>
#include <iostream>
#include <stdio.h>
class interface
{
public:

	virtual void t() const = 0;

};




class Eigenadapter :public interface
{

	typedef std::unique_ptr<Eigen::EigenBase<Eigen::MatrixXf>> eigen;
	eigen impl;

public:

	Eigenadapter();
	void t() const override;


};


