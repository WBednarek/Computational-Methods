#include "GeneralScheme.h"



/**
Default constructor
*/
GeneralScheme::GeneralScheme()
{
	(*this).sizeOfGrid = 100;
	(*this).CFL = 0.999;
}


GeneralScheme::~GeneralScheme()
{
}

void GeneralScheme::calculateDtValue()
{
	 (*this).dt = ((*this).CFL * (*this).dx) / u;
}

void GeneralScheme::calculateDxValue()
{
	(*this).dx = (std::abs((*this).xMin) + std::abs((*this).xMax)) / sizeOfGrid;
}


