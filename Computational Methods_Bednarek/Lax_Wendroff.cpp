#include "Lax_Wendroff.h"



Lax_Wendroff::Lax_Wendroff()
{
}

Lax_Wendroff::Lax_Wendroff(double xMin,
	double xMax,
	double time,
	double spacePoints,
	double CFL) : GeneralScheme::GeneralScheme(xMin, xMax, time, spacePoints, CFL), methodName("Lax_Wendroff")
{
}


Lax_Wendroff::~Lax_Wendroff()
{
}

void Lax_Wendroff::solve(int setNumber)
{
	try
	{

		std::cout << "Lax_Wendroff upwind scheme solution runs and matrix is initialised\n";
		
		(*this).initializeSet(setNumber);
		Lax_WendroffResutls = Matrix((*this).getMatrix());
		

		auto T1 = (CFL * (CFL + 1)) / 2;
		auto T2 =  1 - (CFL  * CFL) ;
		auto T3 = (CFL * (CFL - 1)) / 2;


		for (auto j = 0; j < numberOfTimePoints - 1; ++j)
		{
			for (int i = 1; i < spacePoints - 1; ++i)
			{

				Lax_WendroffResutls[i][j + 1] = T1 * Lax_WendroffResutls[i - 1][j] + T2 * Lax_WendroffResutls[i][j] + T3 * Lax_WendroffResutls[i + 1][j];
			}

		}

	}

	catch (std::exception & e)
	{
		std::cout << "Standard exception: " << e.what() << std::endl;
	}
}

Matrix Lax_Wendroff::getLax_WendroffdMatrix()
{
	return Lax_WendroffResutls;
}
