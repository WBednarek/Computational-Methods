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
	void initializeFirtsSet();
	void initializeFirtsSetAnalytical();
	void initializeSecondSet();
	void initializeSocondSetAnalytical();
	Matrix GeneralScheme::getMatrix();

	
	
};

