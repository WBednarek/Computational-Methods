#include "Matrix.h"



typedef std::vector<std::vector<double> > mat;

/**
Default Constructor
*/
Matrix::Matrix() : mat()  {}

/**
Constructor
*/
Matrix::Matrix(int numOfRows, int numOfColumns) : mat() 
{


	(*this).resize(numOfRows);

	for (int i = 0; i < numOfRows; ++i)
	{
		(*this)[i].resize(numOfColumns);
	}
	
}

int Matrix::getNumOfRows() 
{
	return (*this).size();
}

int Matrix::getNumOfColumns() 
{
	return (*this)[0].size();
}


std::ostream& operator<<(std::ostream& os, Matrix& mat)
{
	for (int i = 0; i < mat.getNumOfRows(); ++i)
	{
		for (int j = 0; j < mat.getNumOfColumns(); ++j)
		{
			os << mat[i][j] << " ";
		}
		os << std::endl;
	}

	return os;
}


