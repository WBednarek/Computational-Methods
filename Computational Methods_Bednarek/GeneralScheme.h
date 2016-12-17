#pragma once
#include "Matrix.h"
#include <memory>  
#include "MathFunctions.h"

class GeneralScheme
{
protected:

	const double u = 1.75;
	int spacePoints;
	double CFL;
	double xMin;
	double xMax;
	Matrix matrixOfResults;
	double dt;
	double dx;
	double time;
	int timePoints;
	int timePoints2;
	bool isSetInitialised;




public:
	GeneralScheme();

	GeneralScheme(
		double xMin,
		double xMax,
		double time);

	
	~GeneralScheme();
	double calculateDtValue();
	double calculateDxValue();
	double getDx();
	void initializeSet(int setNumber);
	void solveSetAnalytical(int setNumber);
	Matrix GeneralScheme::getMatrix();
	double GeneralScheme::initializationFunction(int numberOfSet, double functionValue);
	double GeneralScheme::solutionFunctionAnalytical(int numberOfSet, double actualSpace, double actualTime);

	




};

