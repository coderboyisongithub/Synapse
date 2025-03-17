
#include <Eigen/Core>
#include <iostream>
#include <stdio.h>
class Eigenadapter;
class interface
{
	typedef std::unique_ptr<Eigen::EigenBase<Eigen::MatrixXf>> eigenptr;
public:

	virtual void t() const = 0;
	virtual void print(std::string msg = { " " }) const = 0;
	virtual Eigenadapter operator* (Eigenadapter first) = 0;


};




class Eigenadapter :public interface
{

	typedef std::unique_ptr<Eigen::EigenBase<Eigen::MatrixXf>> eigenptr;
	/*
	* impl is unique pointer to eigenbase class 
	so that the derived type like matrixXf can be accessed
	*/
	eigenptr impl;
	
public:

	Eigenadapter();
	Eigenadapter(Eigen::MatrixXf mtx);
	Eigenadapter(std::initializer_list<std::initializer_list<float>> ilist);

	void t() const override;
	void print(std::string msg = { " " }) const override;
	 
	//operators

	Eigenadapter operator* (Eigenadapter second) override; //lvalue ref or r val ref or no ref at all??

};


