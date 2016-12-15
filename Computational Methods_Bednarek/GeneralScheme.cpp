#include "GeneralScheme.h"



/**
Default constructor
*/

GeneralScheme::GeneralScheme(
	double xMin,
	double xMax,
	double time) : spacePoints(16), CFL(0.999)
{
	(*this).xMin = xMin;
	(*this).xMax = xMax;
	(*this).dt = (*this).calculateDtValue();
	(*this).dx = (*this).calculateDxValue();
	(*this).time = time;
	(*this).timePoints = std::ceil(time / (((*this).CFL * (*this).dx) / u));
	
	matrixOfResults = Matrix(spacePoints, timePoints);
	(*this).calculateDtValue();
	(*this).timePoints2 = std::ceil( (*this).time / (*this).dt );
	
}


GeneralScheme::~GeneralScheme()
{
	
}

double GeneralScheme::calculateDtValue()
{
	return (*this).dt = ((*this).CFL * (*this).dx) / u;
}


double GeneralScheme::calculateDxValue()
{
	return (*this).dx = (std::abs((*this).xMin) + std::abs((*this).xMax)) / spacePoints;
}



double GeneralScheme::getDx()
{
	
	return dx;
}

void GeneralScheme::initializeFirtsSet()
{

	
	if (xMin < 0)
	{
		double actualValue = xMin;
		for (int i = 0; i < spacePoints; ++i)
		{			
			matrixOfResults[i][0] = (1.0/2.0) * (MathFunctions::sign(actualValue) + 1);
			actualValue += dx;
			
		}
	}
	else
	{
		for (int i = 0; i < spacePoints; ++i)
		{
			matrixOfResults[i][0] = (1.0 / 2.0) * (MathFunctions::sign(i) + 1);
		}
	}
	
	for (int i = 0; i < timePoints; ++i)
		{
			matrixOfResults[0][i] = 0;
			matrixOfResults[spacePoints-1][i] = 1 ;

		}
		
	
}

Matrix GeneralScheme::getMatrix()
{
	return matrixOfResults;
}

void GeneralScheme::initializeFirtsSetAnalytical()
{
}

void GeneralScheme::initializeSecondSet()
{
}

void GeneralScheme::initializeSocondSetAnalytical()
{
}




