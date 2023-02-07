#include "CIndividual.h"
#include <stdlib.h>
#include <iostream>


CIndividual::CIndividual(std::vector<bool> ivGenotype, CProblem* cProblem)
{
	genotype = ivGenotype;
	problem = cProblem;
	fitness = calcFitness();
}

void CIndividual::mutate(double mutProb, CIndividual& other)
{

	for (int i = 0; i < genotype.size(); i++)
	{
		if(genotype[i] != other.genotype[i])
		{
			if ((rand() % 100) < (mutProb * 100))
			{
				genotype[i] = !genotype[i];
			}
		}
	}
}


std::vector<CIndividual> CIndividual::cross(CIndividual& parent)
{
	

	int seperatePoint = rand() % genotype.size();
	
	std::vector<bool> genotypeOfFirstChild;
	std::vector<bool> genotypeOfSecondChild;

	for (int i = 0; i <= seperatePoint; i++)
	{
		genotypeOfFirstChild.push_back(genotype[i]);
		genotypeOfSecondChild.push_back(parent.genotype[i]);
	}

	for (int i = seperatePoint + 1; i < genotype.size(); i++)
	{
		genotypeOfSecondChild.push_back(genotype[i]);
		genotypeOfFirstChild.push_back(parent.genotype[i]);
	}

	CIndividual child1(genotypeOfFirstChild, problem);
	CIndividual child2(genotypeOfSecondChild, problem);

	std::vector<CIndividual> children;
	children.push_back(child1);
	children.push_back(child2);
	return children;
}


void CIndividual::print()
{
	std::cout << "\t";
	for (int i = 0; i < genotype.size(); i++)
	{
		std::cout << genotype[i];
	}
	std::cout << "\n\tfitness: " << fitness <<"\n";

}
