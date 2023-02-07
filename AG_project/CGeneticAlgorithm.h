#pragma once
#include "CProblem.h"
#include "CIndividual.h"
#include <string>
#include <vector>

class CGeneticAlgorithm
{
private:
	CProblem* problem;

	double popSize;
	double crossProb;
	double mutProb;

	CIndividual bestChildEver;

	int stopper;

	std::vector<CIndividual> population;

public:
	CGeneticAlgorithm(){};

	bool fillInArgs(CProblem* cProblem, double dPopSize, double dCrossProb, double dMutProb, int iStopper);

	void generateFirstPopulation();
	std::vector<bool> getRandomGenotype();
	CIndividual rollParrentToCross();
	void calcFitnessAndBestIndividual(std::vector<CIndividual>& vNextPopulation);


	CIndividual& getRandomFromPop();

	void runIteration();
	void run();

	CIndividual getBestFromPopulation();


	
	















};

