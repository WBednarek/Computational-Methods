#include "SimpleMathFunctions.h"



SimpleMathFunctions::SimpleMathFunctions()
{
}


SimpleMathFunctions::~SimpleMathFunctions()
{
}

 int SimpleMathFunctions::sign(double x)
{
	if (x < 0)
	{
		return -1;
	}
	else if (x == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}