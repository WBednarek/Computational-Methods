
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



void  calculateAllSchemes( int numberOfBoundaryConditionSet, vector <int> initialSettings)
{

	
	

	/*
	switch (functionToCompute)
	{
	case 1:	
		general.initializeSet(numberOfBoundaryConditionSet);
		general.solveSetAnalytical(numberOfBoundaryConditionSet);
		return general;	
		break;
	case 2:
		upwindScheme.solveExplicitUpwindScheme(numberOfBoundaryConditionSet);
		return upwindScheme;
		break;
	case 3:
		implicitUpwindScheme.solveImplicitUpwindScheme(numberOfBoundaryConditionSet);
		return implicitUpwindScheme;
		break;
	case 4:
		laxWendroff.solveLax_Wendroff(numberOfBoundaryConditionSet);
		return laxWendroff;
		break;
	case 5:
		solutionRichtmyer.solveRichtmyer_multi_step(numberOfBoundaryConditionSet);
		return solutionRichtmyer;
		break;


	default:
		break;
	}
	*/
	
	

}

void runSchemes(int numberOfBoundaryConditionSet, vector <int> initialSettings, std::string typeOfExtension)
{

	//Initializing and calculating all schemes 
	GeneralScheme general(initialSettings[0], initialSettings[1], initialSettings[2]);
	general.initializeSet(numberOfBoundaryConditionSet);
	general.solveSetAnalytical(numberOfBoundaryConditionSet);
	ExplicitUpwindScheme upwindScheme(initialSettings[0], initialSettings[1], initialSettings[2]);
	upwindScheme.solveExplicitUpwindScheme(numberOfBoundaryConditionSet);
	ImplicitUpwindScheme implicitUpwindScheme(initialSettings[0], initialSettings[1], initialSettings[2]);
	implicitUpwindScheme.solveImplicitUpwindScheme(numberOfBoundaryConditionSet);
	Lax_Wendroff laxWendroff(initialSettings[0], initialSettings[1], initialSettings[2]);
	laxWendroff.solveLax_Wendroff(numberOfBoundaryConditionSet);
	Richtmyer_multi_step solutionRichtmyer(initialSettings[0], initialSettings[1], initialSettings[2]);
	solutionRichtmyer.solveRichtmyer_multi_step(numberOfBoundaryConditionSet);


	//Preparing streams for each scheme
	std::ofstream osGeneralScheme;
	std::ofstream osUpwindScheme;
	std::ofstream osImplicitScheme;
	std::ofstream osLaxFile;
	std::ofstream osRichtmyer;
	
	//Setting type of decimal separator depending on current location. Operation helps to plot charts in programs such as Exel.
	osGeneralScheme.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osUpwindScheme.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osImplicitScheme.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osLaxFile.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osRichtmyer.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	
	//Open/create file with selected extension. It clold be for instance exel files extensions (.xls; .xlsx).
	osGeneralScheme.open("C:/Users/Domowy/Desktop/Results/GeneralSchemeResults" + typeOfExtension);
	osUpwindScheme.open("C:/Users/Domowy/Desktop/Results/UpwindSchemeResults" + typeOfExtension);
	osImplicitScheme.open("C:/Users/Domowy/Desktop/Results/ImplicitSchemeResults" + typeOfExtension);
	osLaxFile.open("C:/Users/Domowy/Desktop/Results/LaxWendroffResults" + typeOfExtension);
	osRichtmyer.open("C:/Users/Domowy/Desktop/Results/RichtmyerMultiStepResults" + typeOfExtension);
	//Exporting full matrix for each timestep to file
	//file << general.getMatrix();
	//file << upwindScheme.getUpwindMatrix();
	//file << 

	//Saving schemes calculating results 
	osGeneralScheme << general.getMatrix();
	osUpwindScheme << upwindScheme.getUpwindMatrix();
	osImplicitScheme << implicitUpwindScheme.getImplicitUpwindMatrix();
	osLaxFile << laxWendroff.getLax_WendroffdMatrix();
	osRichtmyer << solutionRichtmyer.getRichtmyer_multi_stepdMatrix();

	//Closing alle opened streams at the end
	osGeneralScheme.close();
	osUpwindScheme.close();
	osImplicitScheme.close();
	osLaxFile.close();
	osRichtmyer.close();


}


int main()
{
	
//Number of boundary condition set. 1 for sign boundary set type ; 2 for exp boundary set type 
int setNum = 1;

//Initial setings values are respectively: xMin, xMax, time
vector <int> initialSettings = { -20, 20, 5};

//Extension type of file which storing results of schemes computation. It could be Exel (.xls; .xlsx) file type for instance. 
std::string typeOfExtension = ".xls";

//Running program using above settings
runSchemes(setNum, initialSettings, typeOfExtension);


return 0;
}









//vector <double> results = { 231.43, 432.434, 3.2 };
//displayVector(general.getMatrix().getColumn(5));
//std::cout << "\nMatrix a is :\n" << mat;
//displayVector(results);

//system("pause");


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
