#pragma once
#include "GeneralScheme.h"



/**
* Class created for calculating Explicit Upwind Scheme
* Class inherits methods from GeneralScheme class

*/

class ExplicitUpwindScheme : public GeneralScheme
	
{

	std::string methodName;
	Matrix explicitResutls;
public:
	
	ExplicitUpwindScheme(double xMin,
		double xMax,
		double time,
		double spacePoints,
		double CFL);
	~ExplicitUpwindScheme();


	void solveExplicitUpwindScheme(int setNumber);
	//double solutionFunctionExplicitScheme(int numberOfSet, Matrix toUpwindSchemeCalculations);
	Matrix ExplicitUpwindScheme::getUpwindMatrix();

};



