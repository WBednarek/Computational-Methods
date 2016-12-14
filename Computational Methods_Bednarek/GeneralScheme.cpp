#include "GeneralScheme.h"



/**
Default constructor
*/

GeneralScheme::GeneralScheme(double xMin,
	double xMax,
	double dt,
	double dx) : sizeOfGrid(100), CFL(0.999) 
{
	(*this).xMin = xMin;
	(*this).xMax = xMax;
	(*this).dt = dt;
	(*this).dx = dx;
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

double GeneralScheme::getDx()
{
	return dx;
}

void GeneralScheme::initializeFirtsSet()
{
}

void GeneralScheme::initializeFirtsSetAnalytical()
{
}

void GeneralScheme::initializeSecondSet()
{
}

void GeneralScheme::initializeSocondSetAnalytical()
{
}




