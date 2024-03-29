#include <iostream>
#include <vector>
#include <stdio.h>
#include <errno.h>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <memory>
#include <unistd.h>
#include <map>
#include <iomanip>
#include "MathFunctions.h"
#include "GeneralScheme.h"
#include "ExplicitUpwindScheme.h"
#include "ImplicitUpwindScheme.h"
#include "Lax_Wendroff.h"
#include "Richtmyer_multi_step.h"
#include "Display.h"




using std::vector;
using std::cin;
using std::cout;
using std::endl;
//Own display namespace with user friendly displaying functions
using namespace display;






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


std::string getCurrentPath()
{
	char cwd[1024];
	std::string path;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		path = std::string(cwd);
	}
	else
		perror("getcwd() error");


	return path;

}


void runSchemes(int numberOfBoundaryConditionSet, vector <double> initialSettings, std::string typeOfExtension)
{
    //Create Results folder first
    std::string path = getCurrentPath() + "/Results/";

	
	GeneralScheme general = GeneralScheme(initialSettings[0], initialSettings[1], initialSettings[2], initialSettings[3], initialSettings[4]);
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

    std::stringstream streams[initialSettings.size()];

    for(int i = 0; i < initialSettings.size(); ++i)
    {
        streams[i] << (int) initialSettings[i];
    }

    std::string generalSchemeFileName = path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + general.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension;
	const char *CharGeneralSchemeFileName = generalSchemeFileName.c_str();

	std::string UpwindSchemeFileName = path+ getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + upwindScheme.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension;
	const char *CharUpwindSchemeFileName = UpwindSchemeFileName.c_str();

	std::string implicitUpwindSchemeFileName = path+ getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + implicitUpwindScheme.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension;
	const char *CharImplicitUpwindSchemeFileName= implicitUpwindSchemeFileName.c_str();

	std::string LaxWendroffFileName = path+ getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + laxWendroff.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension;
	const char *CharLaxWendroffFileName = LaxWendroffFileName.c_str();

	std::string solutionRichtmyerFileName = path+ getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + solutionRichtmyer.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension;
	const char *CharSolutionRichtmyerFileName = solutionRichtmyerFileName.c_str();

	//std::string path = "C:/Users/Domowy/Desktop/Results/";
	//Open/create file with selected extension. It clold be for instance exel files extensions (.xls; .xlsx).
    osGeneralScheme.open(CharGeneralSchemeFileName);
	osUpwindScheme.open(CharUpwindSchemeFileName);

	osImplicitScheme.open(CharImplicitUpwindSchemeFileName);
	osLaxFile.open(CharLaxWendroffFileName);
	osRichtmyer.open(CharSolutionRichtmyerFileName );

/*
	osUpwindScheme.open(path+ getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + upwindScheme.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension);
	osImplicitScheme.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + implicitUpwindScheme.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension);
	osLaxFile.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + laxWendroff.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension);
	osRichtmyer.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + solutionRichtmyer.getName() + "Results_t=" + streams[2].str() + "_points=" + streams[3].str() + "_CFL=" + streams[4].str() + typeOfExtension);


    osGeneralScheme.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + general.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + "_CFL=" + std::to_string(initialSettings[4]) + typeOfExtension);
    osUpwindScheme.open(path+ getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + upwindScheme.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + "_CFL=" + std::to_string(initialSettings[4]) + typeOfExtension);
    osImplicitScheme.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + implicitUpwindScheme.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + "_CFL=" + std::to_string(initialSettings[4]) + typeOfExtension);
    osLaxFile.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + laxWendroff.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + "_CFL=" + std::to_string(initialSettings[4]) + typeOfExtension);
    osRichtmyer.open(path + getInitialBoundaryConditionName(numberOfBoundaryConditionSet) + "_" + solutionRichtmyer.getName() + "Results_t=" + std::to_string((int)initialSettings[2]) + "_points=" + std::to_string((int)initialSettings[3]) + "_CFL=" + std::to_string(initialSettings[4]) + typeOfExtension);
*/
	//Saving schemes calculated results
	osGeneralScheme  << general.getMatrix();


	osUpwindScheme  << upwindScheme.getUpwindMatrix();
	osImplicitScheme  << implicitUpwindScheme.getImplicitUpwindMatrix();
	osLaxFile  << laxWendroff.getLax_WendroffdMatrix();
	osRichtmyer  << solutionRichtmyer.getRichtmyer_multi_stepdMatrix();

	//Closing all opened streams at the end
	osGeneralScheme.close();
	
	osUpwindScheme.close();
	osImplicitScheme.close();
	osLaxFile.close();
	osRichtmyer.close();


}



int main()
{

	//Number of boundary condition set. 1 for sign boundary set type ; 2 for exp boundary set type 
	vector<int> setNumber;
    setNumber.push_back(1);



	//Initial setings values are respectively: xMin, xMax, time, number of spacePoints, CFL value


	cout << "Actual parameters are: ";

	//Extension type of file which storing results of schemes computation. It could be Exel (.xls; .xlsx) file type for instance. 
	std::string typeOfExtension = ".xls";

	//Running program using above settings for all initial boundary types

	vector<double> courantNumberSet;
    courantNumberSet.push_back(0.999);
	vector<double> pointsSet;
    pointsSet.push_back(200);
	double timeSet[] = {5};

	for (int v; v < setNumber.size(); ++v)
	{			
			for (int j = 0; j < pointsSet.size(); ++j)
			{

				for (int i = 0; i < sizeof(timeSet)/sizeof(timeSet[0]); ++i)
				{
					
						for (int k = 0; k < courantNumberSet.size(); ++k)
						{
							vector <double> initialSettings;
                            initialSettings.push_back(-50);
                            initialSettings.push_back(50);
                            initialSettings.push_back(timeSet[i]);
                            initialSettings.push_back( pointsSet[j]);
                            initialSettings.push_back(courantNumberSet[k]);
							runSchemes(setNumber[v], initialSettings, typeOfExtension);
						}
									
				}
					

			}
			
			
		}


	return 0;

	}


	//system("pause");

	