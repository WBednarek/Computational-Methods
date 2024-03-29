#pragma once
#include <memory>  
#include <cmath>
#include <exception>
#include <iostream>
#include <algorithm>
#include "Matrix.h"

#include "MathFunctions.h"

/**
@brief This class gives number of functions used in numerical alalysis. 
It initializes the Matrix, compte errors and calculating norms.
This class provides method to solve Analytical solution

*/

class GeneralScheme
{




protected:

	const double u = 1.75; //Const variable to of u value
	int numberOfSpacePoints; //Variable stores number of Space points for initializing Matrix size
	double CFL; //Courant number
	double xMin; //Lower boundary of space domain
	double xMax; //Upper boundary of space domain
	Matrix matrixOfResults; //Matrix which stores Analytical solution results
	double dt; // Time step for solution
	double dx; // Space step
	double time; // Time of simulation
	int numberOfTimePoints; // Number of time points for initializing vetor
	bool isSetInitialised; //Checking if initial boundary conditions is initialized
	bool isAnaliticalSolutionSolved; ////Checking if Analitical Solution is Solved
	std::vector<double> errorVector;// Vector to store erroes
	
	double normInfiniteValue;
	double normOneValue;
	double normTwoValue;
	std::string name;

public:
	GeneralScheme();

	GeneralScheme(
		double xMin, 
		double xMax, 
		double time, 
		double numberOfSpacePoints, 
		double CFL);

	~GeneralScheme();

	/**
	@brief Calculating initial time point value

	@return Initial time point value
	*/
	double calculateDtValue();
	/**
	@brief Calculatinginitialspace point value

	@return Initial pace point value
	*/
	double calculateDxValue();
	/**
	@brief Returns actual time step value

	@return Actual time step value
	*/
	double getDx();


	/**
	@brief Method initializes classes Matrix with selected initial boundary type. After this operation matrix if initialized with selected boundary type

	@param Variable provides boundary initialization set type number, 1 or 2 respectively for:  sign type and exponential type

	*/
	void initializeSet(int setNumber);
	
	
	/**
	@brief Method allows to choose on of boundary function: 1 for sign type; 2 for exponential type. 

	@param Variable provides boundary initialization set type number, 1 or 2 respectively for:  sign type and exponential type
	@param Value of current time step to compute

	@return Calculated sign or exponential fucntion for given fuctionValue

	*/
	double GeneralScheme::initializationFunction(int numberOfSet, double functionValue);

	/**
	@brief Method solves Analytical scheme. Results are stored in Matrix and returns it.

	@param Variable provides boundary initialization set type number, 1 or 2 respectively for:  sign type and exponential type
	@param Value of actaul space point
	@param Value of current time point

	@return Matrix with calculated Analytical scheme

	*/

	double GeneralScheme::solutionFunctionAnalytical(int numberOfSet, double actualSpace, double actualTime);
	/**
	@brief Method returns class Matrix where Analitical solution could be stored

	@return Matrix with calculated Analytical scheme

	*/
	Matrix GeneralScheme::getMatrix();
	/**
	@brief Method calcutales three norms in given matrix for last time step. Norm infinite, One norm and Two norm

	@param Matrix for which last time point all 3 norms will be calculated
	

	@return Matrix with calculated Analytical scheme

	*/
	void GeneralScheme::calculateNorms(Matrix & toCalculateError);
	void put_timeValues();
	

	/**
	@brief Virtual method to returns name of class

	@return name of class
	*/
	virtual  std::string GeneralScheme::getName();


	/**
	@brief Virtual method to solve analytical scheme 

	@param Variable for inidicating boundary initialization set type, 1 or 2 respectively for:  sign type and exponential type


	@return Matrix with calculated Analytical scheme

	*/
	virtual void solve(int setNumber);

	




};

