#include <iostream>
#include <stdio.h>
#define ARMA_PRINT_EXCEPTIONS
#include "Perceptron.h"
#include "Auto_associator.h"
#include "Adapters/Adapter.h"
#include "Eigen/Dense"


//revise auto associative memory.(outer product)

int main()
{





	Eigen::Matrix3f data;

	Eigen::RowVectorX<float> r1, r2;

	data << 1.0, 2, 3,2,2,2,1,2,3;

	r1 = data.row(0);
	r2 = data.row(1);



	r1 = data.row(0);





	/*

	synp::AutoAssociator mem(4, signalType::BIPOLAR);
	synp::AutoAssociator mem2(4, signalType::BIPOLAR);



	std::vector<row_space> signals;

	//create signals 3 bit bipolar

	signals.push_back({ 1, 1,-1,-1});
	signals.push_back({ -1,1,1,-1});
	signals.push_back({ -1,1,-1,1 });
	signals.push_back({ 1,1,1,1 });
	

	
	//mem.recall(row_space{ 1, 0,1 }).print("RECALL");
	for (int idx = 0; idx < signals.size(); idx++)
	mem.memorize(signals[idx]);
	

	mem.print();
	mem.recall(row_space{1,1, -1, -1}).print("RECALL");
	
	*/
	return 0;
}