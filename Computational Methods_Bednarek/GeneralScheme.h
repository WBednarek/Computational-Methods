#pragma once
#include <memory>  
#include <cmath>
#include <exception>
#include <iostream>
#include <algorithm>
#include "Matrix.h"

#include "MathFunctions.h"

class GeneralScheme
{




protected:

	const double u = 1.75;
	int numberOfSpacePoints;
	double CFL;
	double xMin;
	double xMax;
	Matrix matrixOfResults;
	double dt;
	double dx;
	double time;
	int numberOfTimePoints;
	int timePoints2;
	bool isSetInitialised;
	bool isAnaliticalSolutionSolved;
	std::vector<double> errorVector;
	
	std::vector<double>::iterator normInfiniteValue;
	double normInfiniteValue1;
	double normOneValue;
	double normTwoValue;





public:
	GeneralScheme();

	

	GeneralScheme(
		double xMin, 
		double xMax, 
		double time, 
		double numberOfSpacePoints, 
		double CFL);

	
	~GeneralScheme();
	double calculateDtValue();
	double calculateDxValue();
	double getDx();
	void initializeSet(int setNumber);
	virtual void solve(int setNumber);
	Matrix GeneralScheme::getMatrix();
	double GeneralScheme::initializationFunction(int numberOfSet, double functionValue);
	double GeneralScheme::solutionFunctionAnalytical(int numberOfSet, double actualSpace, double actualTime);
	void GeneralScheme::calculateError(Matrix & toCalculateError);

	void put_timeValues();

	




};

