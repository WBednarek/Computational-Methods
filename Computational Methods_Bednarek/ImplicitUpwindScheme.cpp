#include "ImplicitUpwindScheme.h"



ImplicitUpwindScheme::ImplicitUpwindScheme()
{
}

ImplicitUpwindScheme::ImplicitUpwindScheme(double xMin,
	double xMax,
	double time,
	double spacePoints,
	double CFL) : GeneralScheme::GeneralScheme(xMin, xMax, time, spacePoints, CFL), methodName("ImplicitUpwindScheme")
{
}


ImplicitUpwindScheme::~ImplicitUpwindScheme()
{
}

void ImplicitUpwindScheme::solve(int setNumber)
{
	try
	{

		std::cout << "Implicit upwid scheme solution runs and matrix is initialised\n";


		(*this).initializeSet(setNumber);
		implicitResults = Matrix((*this).getMatrix());
		

		for (auto j = 0; j < numberOfTimePoints - 1; ++j)
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
