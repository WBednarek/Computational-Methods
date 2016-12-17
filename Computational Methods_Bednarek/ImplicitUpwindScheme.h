#pragma once
#include "GeneralScheme.h"
class ImplicitUpwindScheme :
	public GeneralScheme
{

	std::string methodName;
	Matrix implicitResults;
public:
	ImplicitUpwindScheme();
	ImplicitUpwindScheme(double xMin, double xMax, double time);
	virtual ~ImplicitUpwindScheme();
	void solveImplicitUpwindScheme(int setNumber);
	Matrix getImplicitUpwindMatrix();
};

