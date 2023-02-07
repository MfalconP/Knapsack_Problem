#include "CGeneticAlgorithm.h"
#include <stdlib.h>
#include <iostream>



CIndividual& CGeneticAlgorithm::getRandomFromPop()
{
	return population[rand() % population.size()];
}


bool CGeneticAlgorithm::fillInArgs(CProblem* cProblem, double dPopSize, double dCrossProb, double dMutProb, int iStopper)
{
	if (cProblem == nullptr || dPopSize < 2 || dCrossProb < 0 || dCrossProb > 1 || dMutProb < 0 || dMutProb > 1 || iStopper < 1)
	{
		return false;
	}
	problem = cProblem;
	popSize = dPopSize;
	crossProb = dCrossProb;
	mutProb = dMutProb;
	stopper = iStopper;
	return true;
}


void CGeneticAlgorithm::generateFirstPopulation()
{
	for (int i = 0; i < popSize; i++)
	{
		CIndividual member(getRandomGenotype(), problem);
		population.push_back(member);

		if (member.getFitness() > bestChildEver.getFitness())
		{
			bestChildEver = member;
		}
	}
}



std::vector<bool> CGeneticAlgorithm::getRandomGenotype()
{
	return problem->getRandomSolution();
}


CIndividual CGeneticAlgorithm::rollParrentToCross()
{
	CIndividual parent;

	int firstCandidateIndex = rand() % population.size();
	int secondCandidateIndex = rand() % population.size();

	while (secondCandidateIndex == firstCandidateIndex)
	{
		secondCandidateIndex = rand() % population.size();
	}

	if (population[firstCandidateIndex].getFitness() > population[secondCandidateIndex].getFitness())
	{
		parent = population[firstCandidateIndex];
	}
	else
	{
		parent = population[secondCandidateIndex];
	}

	return parent;
}


void CGeneticAlgorithm::calcFitnessAndBestIndividual(std::vector<CIndividual>& vNextPopulation)
{
	for (int i = 0; i < vNextPopulation.size(); i++)
	{
		vNextPopulation[i].calcFitness();
		if (vNextPopulation[i].getFitness() > bestChildEver.getFitness())
		{
			bestChildEver = vNextPopulation[i];
		}
	}
}

void CGeneticAlgorithm::runIteration()
{
	std::vector<CIndividual> newPopulation;
	
	while (newPopulation.size() < popSize)
	{
		CIndividual firstParent = rollParrentToCross();
		CIndividual secondParent = rollParrentToCross();

		//Crossing in order to get new population
		if ((rand() % 101) < (crossProb * 100))
		{
			std::vector<CIndividual> children = firstParent.cross(secondParent);
			for (int i = 0; i < children.size(); i++)
			{
				newPopulation.push_back(children[i]);
			}
		}
		else
		{
			newPopulation.push_back(firstParent);
			newPopulation.push_back(secondParent);
		}
	}
	
	//Mutations in new population
	for (int i = 0; i < newPopulation.size(); i++)
	{
		newPopulation[i].mutate(mutProb, getRandomFromPop());	
	}

	calcFitnessAndBestIndividual(newPopulation);

	population = newPopulation;
	

}


void CGeneticAlgorithm::run() 
{
	generateFirstPopulation();

	for (int i = 0; i < stopper; i++)
	{
		runIteration();
		//std::cout << "Iteration " << i + 1 << ". Best result: " << bestChildEver.getFitness() << std::endl;
		CIndividual champ = getBestFromPopulation();
		//champ.print();
	}
	problem->setSolution(bestChildEver.getGenotype());
}


CIndividual CGeneticAlgorithm::getBestFromPopulation()
{
	CIndividual champion;
	for (int i = 0; i < population.size(); i++)
	{
		if (population[i].getFitness() >= champion.getFitness())
			champion = population[i];
	}
	return champion;
}




