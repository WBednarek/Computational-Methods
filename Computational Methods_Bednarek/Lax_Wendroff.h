#pragma once
#include "GeneralScheme.h"
class Lax_Wendroff :
	public GeneralScheme
{

	std::string methodName;
	Matrix Lax_WendroffResutls;

public:
	Lax_Wendroff();

	Lax_Wendroff(double xMin,
		double xMax,
		double time);

	virtual ~Lax_Wendroff();


	void solveLax_Wendroff(int setNumber);
	//double solutionFunctionExplicitScheme(int numberOfSet, Matrix toUpwindSchemeCalculations);
	Matrix Lax_Wendroff::getLax_WendroffdMatrix();

};

