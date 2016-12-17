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
	
	Matrix(const Matrix & m);

	int getNumOfRows() const;

	int getNumOfColumns() const;


	std::vector<double>& getRow(int rowNumber);
	std::vector<double> & Matrix::getColumn(int columnnumber);

	friend std::ostream& operator<<(std::ostream& os, Matrix& mat);
	friend std::ofstream& operator<<(std::ofstream& ofs,
		const Matrix& m);
	Matrix& Matrix::operator=(const Matrix& m);

};