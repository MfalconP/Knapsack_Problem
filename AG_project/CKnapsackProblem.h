#pragma once
#include "CProblem.h"
#include <vector>
#include <string>





class CItem
{
private:
	double weight;
	double value;

public:
	CItem(double dWeight, double dValue);

	double getWeight() { return weight; };
	double getValue() { return value; };

};



class CKnapsackProblem: public CProblem
{
private:
	std::vector<CItem> itemsList;
	double limit;
	int itemsAmount;

	std::vector<bool> solution;

public:
	CKnapsackProblem() {};

	double calcFitness(std::vector<bool> bvSolution);//overloaded
	bool readDataFromFile(std::string sFileName);
	bool randomProblem(double dLimit, int iItemsAmount);

	std::vector<bool> getRandomSolution();//overloaded

	void setSolution(std::vector<bool> bvSolution) { solution = bvSolution; };//overloaded
	void displaySolution();

	std::vector<bool> getSolution() { return solution; };

};

