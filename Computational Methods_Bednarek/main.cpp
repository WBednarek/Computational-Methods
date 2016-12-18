#include <iostream>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>
#include <map>
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


void runSchemes(int numberOfBoundaryConditionSet, vector <double> initialSettings, std::string typeOfExtension)
{

	//Initializing and calculating all schemes 

	std::map<int, std::vector<double> > initialSettigsSet;
	initialSettigsSet[0] = { -50, 50, 5, 100, 0.999 };
	initialSettigsSet[1] = { -50, 50, 5, 100, 0.9 };
	initialSettigsSet[2] = { -50, 50, 5, 200, 0.9 };
	initialSettigsSet[3] = { -50, 50, 5, 400, 0.9 };
	initialSettigsSet[4] = { -50, 50, 10, 100, 0.9 };
	initialSettigsSet[5] = { -50, 50, 10, 200, 0.9 };
	initialSettigsSet[6] = { -50, 50, 10, 400, 0.9 };
	


		GeneralScheme general = GeneralScheme(initialSettigsSet[0][0], initialSettings[1], initialSettings[2], initialSettings[3], initialSettings[4]);
		general.solve(numberOfBoundaryConditionSet);

		ExplicitUpwindScheme upwindScheme(initialSettings[0], initialSettings[1], initialSettings[2], initialSettings[3], initialSettings[4]);
		upwindScheme.solve(numberOfBoundaryConditionSet);

		ImplicitUpwindScheme implicitUpwindScheme(initialSettings[0], initialSettings[1], initialSettings[2], initialSettings[3], initialSettings[4]);
		implicitUpwindScheme.solve(numberOfBoundaryConditionSet);

		Lax_Wendroff laxWendroff(initialSettings[0], initialSettings[1], initialSettings[2], initialSettings[3], initialSettings[4]);
		laxWendroff.solve(numberOfBoundaryConditionSet);

		Richtmyer_multi_step solutionRichtmyer(initialSettings[0], initialSettings[1], initialSettings[2], initialSettings[3], initialSettings[4]);
		solutionRichtmyer.solve(numberOfBoundaryConditionSet);
	

	std::ofstream osGeneralScheme;
	std::ofstream osUpwindScheme;
	std::ofstream osImplicitScheme;
	std::ofstream osLaxFile;
	std::ofstream osRichtmyer;
	
	//Operation helps to plot charts in programs such as Exel. Setting type of decimal separator depending on current geographical location. In some countries comma in default separator in numbers in others dot
	osGeneralScheme.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osUpwindScheme.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osImplicitScheme.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osLaxFile.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	osRichtmyer.imbue(std::locale(std::cout.getloc(), new DecimalSeparator<char>(',')));
	
	//Open/create file with selected extension. It clold be for instance exel files extensions (.xls; .xlsx).
	osGeneralScheme.open("C:/Users/Domowy/Desktop/Results/" + general.getName() + "Results_t=" + std::to_string((int) initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + typeOfExtension);
	osUpwindScheme.open("C:/Users/Domowy/Desktop/Results/" + upwindScheme.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + typeOfExtension);
	osImplicitScheme.open("C:/Users/Domowy/Desktop/Results/" + implicitUpwindScheme.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + typeOfExtension);
	osLaxFile.open("C:/Users/Domowy/Desktop/Results/" + laxWendroff.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + typeOfExtension);
	osRichtmyer.open("C:/Users/Domowy/Desktop/Results/" + solutionRichtmyer.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + typeOfExtension);
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



Matrix initialSettigsSet(8, 8);
initialSettigsSet[0] = { -50, 50, 5, 100, 0.999 };
initialSettigsSet[1] = { -50, 50, 5, 100, 0.9 };
initialSettigsSet[2] = { -50, 50, 5, 200, 0.9};
initialSettigsSet[3] = { -50, 50, 5, 400, 0.9 };
initialSettigsSet[4] = { -50, 50, 10, 100, 0.9};
initialSettigsSet[5] = { -50, 50, 10, 200, 0.9 };
initialSettigsSet[6] = { -50, 50, 10, 400, 0.9 };

cout << initialSettigsSet[0][4]<<std::endl;

//Initial setings values are respectively: xMin, xMax, time, number of spacePoints, CFL value
vector <double> initialSettings = { -50, 50, 5, 100, 0.999};

//Extension type of file which storing results of schemes computation. It could be Exel (.xls; .xlsx) file type for instance. 
std::string typeOfExtension = ".xls";

//Running program using above settings
runSchemes(setNum, initialSettings, typeOfExtension);
//system("pause");

return 0;
}









//vector <double> results = { 231.43, 432.434, 3.2 };
//displayVector(general.getMatrix().getColumn(5));
//std::cout << "\nMatrix a is :\n" << mat;
//displayVector(results);

//system("pause");



//Preparing streams for each scheme
/*
vector<std::string> schemesNames = {}

vector<std::shared_ptr<std::ofstream> > streams;
for (int i = 0; i < numStreams; i++) {
std::shared_ptr<ofstream> out(new std::ofstream);
string fileName = "text" + to_string(i) + ".txt";
out->open(fileName.c_str());
streams.push_back(out);
}
*/