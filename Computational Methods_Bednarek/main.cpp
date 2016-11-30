#include <iostream>
#include <vector>
#include <stdio.h>

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


int main()
{
	typedef vector<int> Row;
	typedef vector<Row> Matrix;

	Matrix someMatrix(3, Row(5));

	someMatrix[2][2] = 4;
	
	vector<int> myTestVec = { 187, 1234, 145, -5432, 534 };

	/*
	cout << "I'm using vector which is filled with following values: "; 
	displayVector(myTestVec);
	*/
	cout <<"This is some matrix element: " << someMatrix[2][2];
	system("pause");

	return 0;
}