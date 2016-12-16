#include <iostream>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iterator> 
#include <string>
#include "MathFunctions.h"
#include "GeneralScheme.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;


void displayVector(vector<double> vector)
{
	for (auto v : vector)
	{
		cout << "\n" << v;
	}
	cout << endl;

}


template<typename CharT>
class SeparatorType : public std::numpunct<CharT>
{

private:
	CharT outSeparator;


protected:
	CharT decimal_point()const
	{
		return outSeparator;
	}


public:
	SeparatorType(CharT Separator)
		: outSeparator(Separator)
	{}

};


template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<T> &v) 
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, "\n"));
	return out;
}

void exportToCsv(vector <double> resultsVector, vector <int> timeSetVector)
{

	GeneralScheme general(-50, 50, 10);

	general.calculateDxValue();
	general.calculateDtValue();
	general.initializeSet(2);
	general.solveSetAnalytical(2);

	for (auto t = 0; t < timeSetVector.size(); ++t)
	{
		for (auto i = 0; i < general.getMatrix().getNumOfRows(); ++i)
		{
			resultsVector.push_back(general.getMatrix()[i][timeSetVector.at(t)]);
		}

		std::ofstream file;
		//Setting type of decimal separator depending on current location. Operation helps to plot charts in programs such as Exel.
		file.imbue(std::locale(std::cout.getloc(), new SeparatorType<char>(',')));
		file.open("C:/Users/Domowy/Desktop/Results/result t=" + std::to_string(timeSetVector.at(t)) + std::string(".csv"));
		file << resultsVector;
		resultsVector.clear();

	}
		

}

int main()
{
	std::cout.imbue(std::locale(std::cout.getloc(), new SeparatorType<char>(',')));
	
	vector <int> setNumber = { 1, 2, 3 };
	int setNum = 2;
	vector <double> results;
	vector <int> timeSet = { 5,10 };

	//displayVector(general.getMatrix().getColumn(5));
	//std::cout << "\nMatrix a is :\n" <<general.getMatrix();
	displayVector(results);
	exportToCsv(results, timeSet);
	//system("pause");

	return 0;
}







/*
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
*/