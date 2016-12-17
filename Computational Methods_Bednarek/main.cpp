
#include <iostream>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>
#include "MathFunctions.h"
#include "GeneralScheme.h"
#include "ExplicitUpwindScheme.h"
#include "ImplicitUpwindScheme.h"
#include "Lax_Wendroff.h"
#include "Richtmyer_multi_step.h"

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
class DecimalSeparator : public std::numpunct<CharT>
{
public:
	DecimalSeparator(CharT Separator)
		: m_Separator(Separator)
	{}

protected:
	CharT do_decimal_point()const
	{
		return m_Separator;
	}

private:
	CharT m_Separator;
};


template<typename T>
std::ostream &operator <<(std::ostream &out, const std::vector<T> &v)
{
std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, "\n"));
return out;
}



void exportToCsv(int setNum, vector <int> timeSetVector, vector <int> initialSettings)
{

/*
GeneralScheme general(initialSettings[0], initialSettings[1], initialSettings[2]);
general.calculateDxValue();
general.calculateDtValue();
general.initializeSet(setNum);
general.solveSetAnalytical(setNum);
*/
ExplicitUpwindScheme upwindScheme(initialSettings[0], initialSettings[1], initialSettings[2]);
upwindScheme.solveExplicitUpwindScheme(setNum);

ImplicitUpwindScheme implicitUpwindScheme(initialSettings[0], initialSettings[1], initialSettings[2]);
implicitUpwindScheme.solveImplicitUpwindScheme(setNum);

Lax_Wendroff laxWendroff(initialSettings[0], initialSettings[1], initialSettings[2]);
laxWendroff.solveLax_Wendroff(setNum);

Richtmyer_multi_step solutionRichtmyer(initialSettings[0], initialSettings[1], initialSettings[2]);
solutionRichtmyer.solveRichtmyer_multi_step(setNum);

/*

Matrix mat;

mat = upwindScheme.getUpwindMatrix();


vector <double> resultsVector;
for (auto t = 0; t < timeSetVector.size(); ++t)
{
	
	for (auto i = 0; i < general.getMatrix().getNumOfRows(); ++i)
	{
		resultsVector.push_back(general.getMatrix()[i][timeSetVector.at(t)]);
	}

	resultsVector.clear();
	file.open("C:/Users/Domowy/Desktop/Results/result t=" + std::to_string(timeSetVector.at(t)) + std::string(".xls"));
}
	*/

	std::ofstream file;
	std::ofstream laxFile;
	std::ofstream richtmyer;
	//Setting type of decimal separator depending on current location. Operation helps to plot charts in programs such as Exel.
	file.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	laxFile.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	richtmyer.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	//Open file with selected extension
	file.open("C:/Users/Domowy/Desktop/Results/Results" + std::string(".xls"));
	laxFile.open("C:/Users/Domowy/Desktop/Results/ResultsLaxWendroff" + std::string(".xls"));
	richtmyer.open("C:/Users/Domowy/Desktop/Results/ResultsRichtmyer_multi_step" + std::string(".xls"));
	//Exporting full matrix for each timestep to file
	//file << general.getMatrix();
	//file << upwindScheme.getUpwindMatrix();
	file << implicitUpwindScheme.getImplicitUpwindMatrix();
	laxFile << laxWendroff.getLax_WendroffdMatrix();
	richtmyer << solutionRichtmyer.getRichtmyer_multi_stepdMatrix();
	
	file.close();
	

/*
vector <double> resultsVector;
for (auto t = 0; t < timeSetVector.size(); ++t)
{
for (auto i = 0; i < upwindScheme.getUpwindMatrix().getNumOfRows(); ++i)
{
resultsVector.push_back(upwindScheme.getUpwindMatrix()[i][timeSetVector.at(t)]);
}
*/

}

int main()
{
std::cout.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));

vector <int> setNumber = { 1, 2, 3 };
int setNum = 2;
//Initial setings values are respectively: xMin, xMax, time
vector <int> initialSettings = { -50, 50, 5};
vector <int> timeSet = { 5,10 };

//vector <double> results = { 231.43, 432.434, 3.2 };
//displayVector(general.getMatrix().getColumn(5));
//std::cout << "\nMatrix a is :\n" << mat;
//displayVector(results);
exportToCsv(setNum, timeSet, initialSettings);
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
