#include "CKnapsackProblem.h"
#include <iostream>
#include <stdlib.h>
#include <fstream> 
#include <cmath>




CItem::CItem(double dWeight, double dValue)
{
	weight = dWeight;
	value = dValue;
}


bool CKnapsackProblem::randomProblem(double dLimit, int iItemsAmount)
{
	if (dLimit <= 0 || iItemsAmount <= 1)
	{
		return false;
	}
		
	limit = dLimit;
	itemsAmount = iItemsAmount;

	for (int i = 0; i < itemsAmount; i++)
	{
		CItem item( (rand() % (int)(limit/2) + 1),  (rand() % 10 + 1) );
		itemsList.push_back(item);
	}
	return true;
}


bool CKnapsackProblem::readDataFromFile(std::string sFileName)
{
	std::ifstream file(sFileName);
	
	if (!file.is_open())
		return false;


	std::string line;
	
	
	getline(file, line);
	line = line.substr(16, line.length());
	limit = std::stoi(line);
	if (limit <= 0)
	{
		return false;
	}
	
	getline(file, line);
	line = line.substr(14, line.length());
	itemsAmount = std::stoi(line);
	if (itemsAmount <= 1)
	{
		return false;
	}


	getline(file, line);

	double param1;
	double param2;

	for (int i = 0; i < itemsAmount; i++)
	{
		getline(file, line, ' ');
		param1 = std::stod(line);
		if (param1 <= 0)
		{
			return false;
		}
		getline(file, line, '\n');
		param2 = std::stod(line);
		if (param2 <= 0)
		{
			return false;
		}
		CItem item(param1, param2);
		itemsList.push_back(item);

	}

	file.close();
	return true;
}


double CKnapsackProblem::calcFitness(std::vector<bool> bvSolution)
{
	double solutionValue = 0;
	double solutionWeight = 0;
	for (int i = 0; i < itemsAmount; i++)
	{
		if (bvSolution[i] == 1)
		{
			solutionValue += itemsList[i].getValue();
			solutionWeight += itemsList[i].getWeight();
		}

	}
	if (solutionWeight > limit)
	{
		solutionValue = 0;
	}
	return solutionValue;
}


std::vector<bool> CKnapsackProblem::getRandomSolution()
{
	std::vector<bool> solution;
	for (int i = 0; i < itemsAmount; i++)
	{
		solution.push_back(rand() % 2);
	}
	return solution;
}

void CKnapsackProblem::displaySolution()
{
	std::cout << "\n\nBest solution (best sum value), which was fitted into knapsack is: " << calcFitness(solution);
}

