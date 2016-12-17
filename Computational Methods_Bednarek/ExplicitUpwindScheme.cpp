#include "ExplicitUpwindScheme.h"



ExplicitUpwindScheme::ExplicitUpwindScheme(double xMin,
	double xMax,
	double time) : GeneralScheme::GeneralScheme(xMin, xMax, time),  methodName("ExplicitUpwindScheme")
{

}


ExplicitUpwindScheme::~ExplicitUpwindScheme()
{
}


void ExplicitUpwindScheme::solveExplicitUpwindScheme(int setNumber)
{
	try
	{
		
			std::cout << "Explicit upwid scheme solution runs and matrix is initialised\n";

			//Variables hold values below 0. Thanks to that negative values could be passed to sign function, it makes loop iteration easier.
			double actualSpaceValue = xMin;
			//Variable assinged to dt because time at 0 point is initialised in function initializeSet()
			double actualTimeValue = dt;

			GeneralScheme upwindIsntance(-50,50,5);
			upwindIsntance.initializeSet(setNumber);
			explicitResutls = Matrix(upwindIsntance.getMatrix());
			
			for (auto j = 0; j < timePoints-1; ++j)
			{
				for (int i = 1; i < spacePoints; ++i)
				{
				
					explicitResutls[i][j+1] = (explicitResutls[i][j] - CFL*(explicitResutls[i][j] - explicitResutls[i - 1][j]));
					//explicitResutls[i][j + 1] = (1 - CFL) * (upwindIsntance.getMatrix()[i][j]) + (CFL * upwindIsntance.getMatrix()[i - 1][j]);
					actualSpaceValue += dx;
					
				}			
				actualTimeValue += dt;
				actualSpaceValue = dx;
				
			}
			

	}

	catch (std::exception & e)
	{
		std::cout << "Standard exception: " << e.what() << std::endl;
	}
}

Matrix ExplicitUpwindScheme::getUpwindMatrix()
{
	return explicitResutls;
}


