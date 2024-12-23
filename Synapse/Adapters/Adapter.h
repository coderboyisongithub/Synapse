#pragma once


#include "Eigen/Eigen"
#include<iostream>




#include <cstddef> // For size_t
#include <vector>



class Matf
{



	std::shared_ptr<MatfAdaptor_interface<float>>impl;
public:
	Matf()
	{
	}

	int rows();
	int cols();


	~Matf()
	{
	}


	//operators
	friend Matf operator+(const Matf a, const Matf b);
	friend Matf operator-(const Matf a, const Matf b);
	friend Matf operator*(Matf a, Matf b);
	

};

template<typename type>
class MatfAdaptor_interface 
{
public:


    virtual ~MatfAdaptor_interface() = dafault;
    // Basic operations
    virtual Eigen::Index rows() const = 0;
    virtual Eigen::Index cols() const = 0;
    virtual void resize(Eigen::Index rows, Eigen::Index cols) = 0;
    virtual void conservativeResize(Eigen::Index rows, Eigen::Index cols) = 0;

    // Element access
    virtual type& at(Eigen::Index row, Eigen::Index col) = 0;
    virtual const type& at(Eigen::Index row, Eigen::Index col) const = 0;

    // Common operations
    virtual void setZero() = 0;
    virtual void setOnes() = 0;
    virtual void setRandom() = 0;
    virtual void setIdentity() = 0;

    // Matrix operations
    virtual std::unique_ptr<MatfAdaptor_interface<type>> transpose() const = 0;
    virtual std::unique_ptr<MatfAdaptor_interface<type>> inverse() const = 0;

    // Arithmetic operations
    virtual std::unique_ptr<MatfAdaptor_interface<type>> add(const MatfAdaptor_interface<type>& other) const = 0;
    virtual std::unique_ptr<MatfAdaptor_interface<type>> subtract(const MatfAdaptor_interface<type>& other) const = 0;
    virtual std::unique_ptr<MatfAdaptor_interface<type>> multiply(const MatfAdaptor_interface<type>& other) const = 0;
    virtual std::unique_ptr<MatfAdaptor_interface<type>> multiply(const type& type) const = 0;

    // Decompositions
    virtual Eigen::LLT<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> llt() const = 0;
    virtual Eigen::LDLT<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> ldlt() const = 0;
    virtual Eigen::HouseholderQR<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> householderQr() const = 0;

    // Block operations
    virtual std::unique_ptr<MatfAdaptor_interface<type>> block(Eigen::Index startRow, Eigen::Index startCol,
        Eigen::Index blockRows, Eigen::Index blockCols) = 0;

    // Data access
    virtual type* data() = 0;
    virtual const type* data() const = 0;

    // Common computations
    virtual type norm() const = 0;
    virtual type squaredNorm() const = 0;
    virtual type sum() const = 0;
    virtual type prod() const = 0;
    virtual type mean() const = 0;
    virtual type minCoeff() const = 0;
    virtual type maxCoeff() const = 0;

    // Row and column operations
    virtual std::unique_ptr<MatfAdaptor_interface<type>> row(Eigen::Index i) = 0;
    virtual std::unique_ptr<MatfAdaptor_interface<type>> col(Eigen::Index i) = 0;

    // Utility functions
    virtual bool isZero(type precision = Eigen::NumTraits<type>::dummy_precision()) const = 0;
    virtual bool isOnes(type precision = Eigen::NumTraits<type>::dummy_precision()) const = 0;
    virtual bool isIdentity(type precision = Eigen::NumTraits<type>::dummy_precision()) const = 0;

    // Assignment operations
    virtual void assign(const MatfAdaptor_interface<type>& other) = 0;
    virtual void addAssign(const MatfAdaptor_interface<type>& other) = 0;
    virtual void subtractAssign(const MatfAdaptor_interface<type>& other) = 0;
    virtual void multiplyAssign(const type& type) = 0;

    // Matrix conversion
    virtual Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic> toEigenMatrix() const = 0;
};


#include <Eigen/Dense>

template<typename type = float>
class EigenMatrixAdapter:public MatfAdaptor_interface
{
private:
    Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic> matrix;

public:
    // Constructors
    EigenMatrixAdapter() = default;
    EigenMatrixAdapter(Eigen::Index rows, Eigen::Index cols) : matrix(rows, cols) {}
    EigenMatrixAdapter(const Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>& other) : matrix(other) {}

    // Basic operations
    Eigen::Index rows() const { return matrix.rows(); }
    Eigen::Index cols() const { return matrix.cols(); }
    void resize(Eigen::Index rows, Eigen::Index cols) { matrix.resize(rows, cols); }
    void conservativeResize(Eigen::Index rows, Eigen::Index cols) { matrix.conservativeResize(rows, cols); }

    // Element access
    type& operator()(Eigen::Index row, Eigen::Index col) { return matrix(row, col); }
    const type& operator()(Eigen::Index row, Eigen::Index col) const { return matrix(row, col); }

    // Common operations
    void setZero() { matrix.setZero(); }
    void setOnes() { matrix.setOnes(); }
    void setRandom() { matrix.setRandom(); }
    void setIdentity() { matrix.setIdentity(); }

    // Matrix operations
    EigenMatrixAdapter<type> transpose() const { return EigenMatrixAdapter<type>(matrix.transpose()); }
    EigenMatrixAdapter<type> inverse() const { return EigenMatrixAdapter<type>(matrix.inverse()); }

    // Arithmetic operators
    EigenMatrixAdapter<type> operator+(const EigenMatrixAdapter<type>& other) const {
        return EigenMatrixAdapter<type>(matrix + other.matrix);
    }
    EigenMatrixAdapter<type> operator-(const EigenMatrixAdapter<type>& other) const {
        return EigenMatrixAdapter<type>(matrix - other.matrix);
    }
    EigenMatrixAdapter<type> operator*(const EigenMatrixAdapter<type>& other) const {
        return EigenMatrixAdapter<type>(matrix * other.matrix);
    }

    // type operations
    EigenMatrixAdapter<type> operator*(const type& type) const {
        return EigenMatrixAdapter<type>(matrix * type);
    }

    // Decompositions
    Eigen::LLT<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> llt() const { return matrix.llt(); }
    Eigen::LDLT<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> ldlt() const { return matrix.ldlt(); }
    Eigen::HouseholderQR<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> householderQr() const {
        return matrix.householderQr();
    }

    // Block operations
    template<int BlockRows, int BlockCols>
    auto block(Eigen::Index startRow, Eigen::Index startCol) {
        return matrix.template block<BlockRows, BlockCols>(startRow, startCol);
    }

    // Raw data access
    type* data() { return matrix.data(); }
    const type* data() const { return matrix.data(); }

    // Access to underlying Eigen matrix
    Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>& getMatrix() { return matrix; }
    const Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>& getMatrix() const { return matrix; }

    // Additional common operations
    type norm() const { return matrix.norm(); }
    type squaredNorm() const { return matrix.squaredNorm(); }
    type sum() const { return matrix.sum(); }
    type prod() const { return matrix.prod(); }
    type mean() const { return matrix.mean(); }
    type minCoeff() const { return matrix.minCoeff(); }
    type maxCoeff() const { return matrix.maxCoeff(); }

    // Row and column operations
    auto row(Eigen::Index i) { return matrix.row(i); }
    auto col(Eigen::Index i) { return matrix.col(i); }

    // Additional utility functions
    bool isZero(type precision = Eigen::NumTraits<type>::dummy_precision()) const {
        return matrix.isZero(precision);
    }
    bool isOnes(type precision = Eigen::NumTraits<type>::dummy_precision()) const {
        return matrix.isOnes(precision);
    }
    bool isIdentity(type precision = Eigen::NumTraits<type>::dummy_precision()) const {
        return matrix.isIdentity(precision);
    }

    // Assignment operators
    EigenMatrixAdapter& operator=(const EigenMatrixAdapter& other) {
        matrix = other.matrix;
        return *this;
    }
    EigenMatrixAdapter& operator+=(const EigenMatrixAdapter& other) {
        matrix += other.matrix;
        return *this;
    }
    EigenMatrixAdapter& operator-=(const EigenMatrixAdapter& other) {
        matrix -= other.matrix;
        return *this;
    }
    EigenMatrixAdapter& operator*=(const type& type) {
        matrix *= type;
        return *this;
    }
};



