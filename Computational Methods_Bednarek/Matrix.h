#include <vector>
#include <ostream>
#include <iostream>  
#include <fstream>   


class Matrix : private std::vector<std::vector<double> >
{

public:
	using vector<vector<double> >::operator[];
	Matrix();

	Matrix(int numOfRows, int numOfColumns);

	int Matrix::getNumOfRows();
	int Matrix::getNumOfColumns();

	friend std::ostream& operator<<(std::ostream& os, Matrix& mat);

};