#include <vector>
#include <ostream>
#include <iostream>  
#include <fstream>  
#include <memory>


class Matrix : private std::vector< std::vector<double> >
{

	
public:
	using vector<vector<double> >::operator[];
	Matrix();

	std::shared_ptr < std::vector<double> > tmpVec;
	Matrix(int numOfRows, int numOfColumns);
	
	int Matrix::getNumOfRows();
	int Matrix::getNumOfColumns();
	std::vector<double>& getRow(int rowNumber);
	std::vector<double> & Matrix::getColumn(int columnnumber);

	friend std::ostream& operator<<(std::ostream& os, Matrix& mat);

};