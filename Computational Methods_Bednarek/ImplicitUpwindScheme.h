#pragma once
#include "GeneralScheme.h"
class ImplicitUpwindScheme :
	public GeneralScheme
{

	std::string methodName;
	Matrix implicitResults;
public:
	ImplicitUpwindScheme();
	ImplicitUpwindScheme(double xMin,
		double xMax,
		double time,
		double spacePoints,
		double CFL);
	virtual ~ImplicitUpwindScheme();
	virtual void solve(int setNumber) override;
	Matrix getImplicitUpwindMatrix();
};

