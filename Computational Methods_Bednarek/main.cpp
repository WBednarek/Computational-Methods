#include <iostream>
#include <vector>
#include <stdio.h>
#include "Matrix.h"



using std::vector;
using std::cin;
using std::cout;
using std::endl;

void displayVector(vector<int> vector)
{
	for (auto v : vector)
	{
		cout << " " << v;
	}
	cout << endl;

}


void fulfillMatrix(Matrix& mat)
{
	for (int i = 0; i < mat.getNumOfRows(); ++i)
	{
		for (int j = 0; j < mat.getNumOfColumns(); ++j)
		{
			mat[i][j] = rand() % 10;
		}

	}

}

int main()
{

	Matrix someMatrix(10,10);
	
	fulfillMatrix(someMatrix);
	//cout << "This is some matrix: \n" << someMatrix;
	std::cout << "\nMatrix a is :\n" << someMatrix;
	system("pause");

	return 0;
}