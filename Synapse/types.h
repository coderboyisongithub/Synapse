#pragma once
#include <armadillo>
typedef arma::Mat<float> Matf;
typedef float coeffecient;
typedef arma::Col<float> col_space;
typedef arma::Row<float> row_space;

enum signalType
{
	BINARY=0,
	BIPOLAR
};