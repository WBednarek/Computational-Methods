#include "ExplicitUpwindScheme.h"



ExplicitUpwindScheme::ExplicitUpwindScheme(double xMin,
	double xMax,
	double time,
	double spacePoints,
	double CFL) : GeneralScheme::GeneralScheme(xMin, xMax, time, spacePoints, CFL),  methodName("ExplicitUpwindScheme")
{

}


ExplicitUpwindScheme::~ExplicitUpwindScheme()
{
}


void ExplicitUpwindScheme::solve(int setNumber)
{
	try
	{
		
			std::cout << "Explicit upwid scheme solution runs and matrix is initialised\n";

			(*this).initializeSet(setNumber);
			explicitResutls = Matrix((*this).getMatrix());		
			
			for (auto j = 0; j < numberOfTimePoints-1; ++j)
			{
				for (int i = 1; i < spacePoints; ++i)
				{				
					explicitResutls[i][j+1] = (explicitResutls[i][j] - CFL*(explicitResutls[i][j] - explicitResutls[i - 1][j]));			
				}			
					
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


