#include "GeneralScheme.h"
#include <exception>
#include <iostream>



/**
Default constructor
*/

GeneralScheme::GeneralScheme()
{
}

GeneralScheme::GeneralScheme(
	double xMin,
	double xMax,
	double time) : spacePoints(100), CFL(0.99), isSetInitialised(false)
{
	(*this).xMin = xMin;
	(*this).xMax = xMax;
	(*this).time = time;
	(*this).dt = (*this).calculateDtValue();
	(*this).dx = (*this).calculateDxValue();
	
	(*this).timePoints = std::ceil(time / (((*this).CFL * (*this).dx) / u));
	
	matrixOfResults = Matrix(spacePoints, timePoints);
	(*this).calculateDtValue();
	//(*this).timePoints2 = std::ceil( (*this).time / (*this).dt );
	
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

double GeneralScheme::initializationFunction(int numberOfSet, double functionValue)
{
	switch (numberOfSet)
	{
	case 1:
		return (MathFunctions::sign(functionValue) + 1);
		break;
	case 2:
		return std::exp((-1.0)*std::pow(functionValue, 2));
		break;
	}


}

double GeneralScheme::solutionFunctionAnalytical(int numberOfSet, double actualSpaceValue, double actualTimeValue)
{
	switch (numberOfSet)
	{
	case 1:
		return 0.5 * (MathFunctions::sign(actualSpaceValue - 1.75 * actualTimeValue) + 1);
		break;
	case 2:
		return 0.5 * std::exp((-1.0)*std::pow(actualSpaceValue - 1.75 * actualTimeValue, 2));
		break;
	}
}



void GeneralScheme::initializeSet(int setNumber)
{
	

		try
		{
			double actualValue = xMin;
			for (int i = 0; i < spacePoints; ++i)
			{
				matrixOfResults[i][0] = (1.0 / 2.0) * (*this).initializationFunction(setNumber, actualValue);
				actualValue += (*this).dx;
			}


			if (setNumber == 1)
			{
				for (int i = 0; i < timePoints; ++i)
				{
					matrixOfResults[0][i] = 0;
					matrixOfResults[spacePoints - 1][i] = 1;
				}
			}
			else
			{
				for (int i = 0; i < timePoints; ++i)
				{
					matrixOfResults[0][i] = 0;
					matrixOfResults[spacePoints - 1][i] = 0;
				}
			}

			(*this).isSetInitialised = true;

		}
		catch (std::exception & e)
		{
			std::cout << "Standard exception: " << e.what() << std::endl;
		}
		
	
}



void GeneralScheme::solveSetAnalytical(int setNumber)
{
	try
	{
		if ((*this).isSetInitialised == true)
		{
			std::cout << "Analytical solution runs and matrix is initialised\n";

			//Variables hold values below 0. Thanks to that negative values could be passed to sign function, it makes loop iteration easier.
			double actualSpaceValue = xMin;
			//Variable assinged to dt because time at 0 point is initialised in function initializeSet()
			double actualTimeValue = dt;
			for (int i = 1; i < spacePoints; ++i)
			{
				for (auto j = 1; j < timePoints; ++j)
				{
					matrixOfResults[i][j] = solutionFunctionAnalytical(setNumber, actualSpaceValue, actualTimeValue);
					actualTimeValue += dt;				

				}
				actualTimeValue = dt;
				actualSpaceValue += dx;
			}

		}
		else
		{
			std::cout << "Matrix is not initialised\n";
		}
	}
	
	catch (std::exception & e)
	{
		std::cout << "Standard exception: " << e.what() << std::endl;
	}

	
}



Matrix GeneralScheme::getMatrix()
{
	return matrixOfResults;
}




