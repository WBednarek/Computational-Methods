#include "GeneralScheme.h"
#include <exception>
#include <iostream>



/**
Default constructor
*/

GeneralScheme::GeneralScheme()
{
}

GeneralScheme::~GeneralScheme()
{
	
}


GeneralScheme::GeneralScheme(double xMin, double xMax, double time, double spacePoints, double CFL) 
	:xMin(xMin), xMax(xMax), time(time), spacePoints(spacePoints), CFL(CFL), isSetInitialised(false)
{
	
	(*this).dt = (*this).calculateDtValue();
	(*this).dx = (*this).calculateDxValue();
    (*this).numberOfTimePoints = std::ceil(time / (((*this).CFL * (*this).dx) / u));

	matrixOfResults = Matrix(spacePoints, numberOfTimePoints);
	(*this).calculateDtValue();

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

void GeneralScheme::put_timeValues()
{

	double actualValue = 0;
	for (int i = 0; i < numberOfTimePoints; ++i)
	{
		matrixOfResults[0][i] = actualValue;
		actualValue += (*this).dt;
	}

}

void GeneralScheme::initializeSet(int setNumber)
{
	
	
		try
		{
			//put_timeValues();
			double actualValue = xMin;
			for (int i = 0; i < spacePoints ; ++i)
			{
				matrixOfResults[i][0] = (1.0 / 2.0) * (*this).initializationFunction(setNumber, actualValue);
				actualValue += (*this).dx;
			}


			if (setNumber == 1)
			{
				for (int i = 0; i < numberOfTimePoints ; ++i)
				{
					matrixOfResults[0][i] = 0;
					matrixOfResults[spacePoints - 1][i] = 1;
				}
			}
			else
			{
				for (int i = 0; i < numberOfTimePoints ; ++i)
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



void GeneralScheme::solve(int setNumber)
{
	(*this).initializeSet(setNumber);
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
				for (auto j = 1; j < numberOfTimePoints; ++j)
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




