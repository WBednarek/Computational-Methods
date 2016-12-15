#include "MathFunctions.h"



MathFunctions::MathFunctions()
{
}


MathFunctions::~MathFunctions()
{
}

 int MathFunctions::sign(double x)
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