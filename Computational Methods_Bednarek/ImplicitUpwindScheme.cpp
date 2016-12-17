#include "ImplicitUpwindScheme.h"



ImplicitUpwindScheme::ImplicitUpwindScheme()
{
}

ImplicitUpwindScheme::ImplicitUpwindScheme(double xMin,
	double xMax,
	double time) : GeneralScheme::GeneralScheme(xMin, xMax, time), methodName("ImplicitUpwindScheme")
{
}


ImplicitUpwindScheme::~ImplicitUpwindScheme()
{
}




void ImplicitUpwindScheme::solveImplicitUpwindScheme(int setNumber)
{
	try
	{

		std::cout << "Implicit upwid scheme solution runs and matrix is initialised\n";

		//Variables hold values below 0. Thanks to that negative values could be passed to sign function, it makes loop iteration easier.
		double actualSpaceValue = xMin;
		//Variable assinged to dt because time at 0 point is initialised in function initializeSet()
		double actualTimeValue = dt;

		(*this).initializeSet(setNumber);
		implicitResults = Matrix((*this).getMatrix());
		

		for (auto j = 0; j < timePoints - 1; ++j)
		{
			for (int i = 1; i < spacePoints; ++i)
			{

				implicitResults[i][j + 1] = (-1.0 * CFL) * (implicitResults[i][j + 1] - implicitResults[i - 1][j + 1]) + implicitResults[i ][j];

			}
			
		}

	}

	catch (std::exception & e)
	{
		std::cout << "Standard exception: " << e.what() << std::endl;
	}
}

Matrix ImplicitUpwindScheme::getImplicitUpwindMatrix()
{
	return implicitResults;
}
