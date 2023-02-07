#pragma once
#include <vector>

class CProblem
{
public:
	virtual double calcFitness(std::vector<bool> bvSolution) = 0;
	virtual std::vector<bool> getRandomSolution() = 0;
	virtual void setSolution(std::vector<bool> bvSolution) = 0;
};