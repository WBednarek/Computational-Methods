#include "Richtmyer_multi_step.h"



Richtmyer_multi_step::Richtmyer_multi_step()
{
}

Richtmyer_multi_step::Richtmyer_multi_step(double xMin, double xMax, double time) :
	 GeneralScheme::GeneralScheme(xMin, xMax, time), methodName("RichtmyerMultiStepScheme")
{
}


Richtmyer_multi_step::~Richtmyer_multi_step()
{
}

void Richtmyer_multi_step::solveRichtmyer_multi_step(int setNumber)
{
	try
	{

		std::cout << "Richtmyer_multi_step scheme solution runs and matrix is initialised\n";

		//Initializing General Scheme
		GeneralScheme upwindIsntance(-50, 50, 5);
		//Preparing initial data with choosen setNumber: 1 - sign set; 2 - exp set
		upwindIsntance.initializeSet(setNumber);
		//Initializing Matrices with initial conditions
		RichtmyerResutls = Matrix(upwindIsntance.getMatrix());
		halfStepRichtmyer = Matrix(upwindIsntance.getMatrix());

		//Calculating Richtmyer_multi_step scheme cooeficients before loop for code claryti and performance profit
		auto coef1 = ( 1 - (CFL/2) ) / 2;
		auto coef2 = ( 1 + (CFL/2) ) / 2;
		auto coef3 = CFL / 2;
		
		

		//Main time loop iterating for each time point
		for (int j = 0; j < timePoints - 1; ++j)
		{
			for (int i = 1; i < spacePoints - 1; ++i)
			{

				halfStepRichtmyer[i][j] = coef1 * halfStepRichtmyer[i + 1][j] + coef2 *halfStepRichtmyer[i - 1][j];

			}


			for (int i = 1; i < spacePoints - 1; ++i)
			{

				RichtmyerResutls[i][j + 1] = RichtmyerResutls[i][j] - coef3 * (halfStepRichtmyer[i + 1][j] - halfStepRichtmyer[i - 1][j]);
			}

		}

	}

	catch (std::exception & e)
	{
		std::cout << "Standard exception: " << e.what() << std::endl;
	}

}

Matrix Richtmyer_multi_step::getRichtmyer_multi_stepdMatrix()
{
	return RichtmyerResutls;
}
