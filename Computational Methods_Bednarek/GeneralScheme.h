#pragma once
#include "Matrix.h"
class GeneralScheme
{
protected:

	const double u = 1.75;
	int sizeOfGrid;
	double CFL;
	double xMin;
	double xMax;
	Matrix matrixOfResults;
	double dt;
	double dx;



public:
	GeneralScheme();

	GeneralScheme(
		double xMin,
		double xMax,
		double dt,
		double dx);

	
	~GeneralScheme();
	void calculateDtValue();
	void calculateDxValue();
	double getDx();
	void initializeFirtsSet();
	void initializeFirtsSetAnalytical();
	void initializeSecondSet();
	void initializeSocondSetAnalytical();

	
	
};

