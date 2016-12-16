#pragma once
#include "GeneralScheme.h"



/**
* Class created for calculating Explicit Upwind Scheme
* Class inherits methods from GeneralScheme class

*/

class ExplicitUpwindScheme : public GeneralScheme
	
{

	std::string methodName;
public:
	
	ExplicitUpwindScheme();
	~ExplicitUpwindScheme();


	void solveExplicitUpwindScheme();

};



