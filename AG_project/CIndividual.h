#pragma once
#include "CProblem.h"
#include <vector>

class CIndividual
{
private:
	CProblem* problem;

	std::vector<bool> genotype;
	double fitness;


public:
	CIndividual(std::vector<bool> ivGenotype, CProblem* cProblem);
	CIndividual() { fitness = 0; };


	double calcFitness() { return problem->calcFitness(genotype); };
	void mutate(double mutProb, CIndividual& other);
	std::vector<CIndividual> cross(CIndividual& parent);
	void print();


	double getFitness() { return fitness; };
	std::vector<bool> getGenotype() { return genotype; };
};

