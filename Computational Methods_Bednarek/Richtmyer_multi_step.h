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

	//Virtual solve method as in the rest classes. Overide is an "tip" for compiler in cases then method could be by an accident not overrided but created as new one
	virtual void solve(int setNumber) override;
	Matrix Richtmyer_multi_step::getRichtmyer_multi_stepdMatrix();
	virtual std::string Richtmyer_multi_step::getName() override;

};

