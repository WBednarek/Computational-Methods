#pragma once
#include "GeneralScheme.h"
class Richtmyer_multi_step :
	public GeneralScheme
{
	std::string methodName;
	Matrix RichtmyerResutls;
	Matrix halfStepRichtmyer;

public:
	Richtmyer_multi_step();

	Richtmyer_multi_step(double xMin,
		double xMax,
		double time,
		double numberOfSpacePoints,
		double CFL);

	virtual ~Richtmyer_multi_step();


	virtual void solve(int setNumber) override;
	Matrix Richtmyer_multi_step::getRichtmyer_multi_stepdMatrix();
};

