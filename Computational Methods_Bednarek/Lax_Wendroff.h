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
		double time,
		double numberOfSpacePoints,
		double CFL);

	virtual ~Lax_Wendroff();


	virtual void solve(int setNumber) override;
	//double solutionFunctionExplicitScheme(int numberOfSet, Matrix toUpwindSchemeCalculations);
	Matrix Lax_Wendroff::getLax_WendroffdMatrix();

};

