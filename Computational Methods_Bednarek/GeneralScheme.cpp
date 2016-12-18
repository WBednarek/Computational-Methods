#include "GeneralScheme.h"




/**
Default constructor
*/

GeneralScheme::GeneralScheme()
{
}

GeneralScheme::~GeneralScheme()
{
	
}


GeneralScheme::GeneralScheme(double xMin, double xMax, double time, double numberOfSpacePoints, double CFL) 
	:xMin(xMin), xMax(xMax), time(time), numberOfSpacePoints(numberOfSpacePoints), CFL(CFL), isSetInitialised(false), isAnaliticalSolutionSolved(false)
{
	
	(*this).dt = (*this).calculateDtValue();
	(*this).dx = (*this).calculateDxValue();
    (*this).numberOfTimePoints = std::ceil(time / (((*this).CFL * (*this).dx) / u));

	matrixOfResults = Matrix(numberOfSpacePoints, numberOfTimePoints);
	(*this).calculateDtValue();

}

double GeneralScheme::calculateDtValue()
{
	return (*this).dt = ((*this).CFL * (*this).dx) / u;
}


double GeneralScheme::calculateDxValue()
{
	return (*this).dx = (std::abs((*this).xMin) + std::abs((*this).xMax)) / numberOfSpacePoints;
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
	default:
		break;
	}
}


//Error and norms calculation
void GeneralScheme::calculateError(Matrix& toCalculateError)
{
	errorVector.resize(toCalculateError.getNumOfRows());
		for (auto i = 0; i < toCalculateError.getNumOfRows(); ++i) 
		{
			errorVector[i] = toCalculateError[i][numberOfTimePoints - 1] - (*this).matrixOfResults[i][numberOfTimePoints - 1];
		}

		(*this).normInfiniteValue = std::max_element(errorVector.begin(), errorVector.end(), MathFunctions::compareTwoAbsElements);
		normInfiniteValue1 = std::distance(errorVector.begin(), normInfiniteValue);

		for (auto i = 0; i < errorVector.size(); ++i)
		{
			(*this).normOneValue += std::abs(errorVector[i]);
			(*this).normTwoValue += std::pow(std::abs(errorVector[i]), 2);
		}
		std::vector<double> norms = { normInfiniteValue1, normOneValue, normTwoValue };
		toCalculateError.resizeMat(numberOfSpacePoints + norms.size() + 1, numberOfTimePoints);
		for (int i = 0; i < norms.size(); ++i)
		{
			//Adding norms results to last matrix colunm
			toCalculateError[i + numberOfSpacePoints+1][numberOfTimePoints - 1] = norms.at(i);
		}
	

}
/*
void GeneralScheme::getNorms(Matrix  toCalculateError)
{
	(*this).calculateError(toCalculateError);
	
	
}
*/


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
			for (int i = 0; i < numberOfSpacePoints ; ++i)
			{
				matrixOfResults[i][0] = (1.0 / 2.0) * (*this).initializationFunction(setNumber, actualValue);
				actualValue += (*this).dx;
			}


			if (setNumber == 1)
			{
				for (int i = 0; i < numberOfTimePoints ; ++i)
				{
					matrixOfResults[0][i] = 0;
					matrixOfResults[numberOfSpacePoints - 1][i] = 1;
				}
			}
			else
			{
				for (int i = 0; i < numberOfTimePoints ; ++i)
				{
					matrixOfResults[0][i] = 0;
					matrixOfResults[numberOfSpacePoints - 1][i] = 0;
				}
			}

			(*this).isSetInitialised = true;

		}
		catch (std::exception & e)
		{
			std::cout << "Standard exception: " << e.what() << std::endl;
		}
		
	
}


//Analytical scheme solving
void GeneralScheme::solve(int numberOfBoundaryConditionSet)
{
	(*this).initializeSet(numberOfBoundaryConditionSet);
	try
	{
		if ((*this).isSetInitialised == true)
		{
			std::cout << "Analytical solution runs and matrix is initialised\n";

			//Variables hold values below 0. Thanks to that negative values could be passed to sign function, it makes loop iteration easier.
			double actualSpaceValue = xMin;
			//Variable assinged to dt because time at 0 point is initialised in function initializeSet()
			double actualTimeValue = dt;
			for (int i = 1; i < numberOfSpacePoints; ++i)
			{
				for (auto j = 1; j < numberOfTimePoints; ++j)
				{
					matrixOfResults[i][j] = solutionFunctionAnalytical(numberOfBoundaryConditionSet, actualSpaceValue, actualTimeValue);
					actualTimeValue += dt;				

				}
				actualTimeValue = dt;
				actualSpaceValue += dx;
			}
			
			isAnaliticalSolutionSolved = true;
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




