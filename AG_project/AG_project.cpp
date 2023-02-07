#include <iostream>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"


int main()
{
    //10; 0.6; 0.1; 35; best: 309
    srand(time(NULL));


    CKnapsackProblem* defaultKnapsackProblem = new CKnapsackProblem;
    if (defaultKnapsackProblem->readDataFromFile("Knapsack.txt"))
    {
        CGeneticAlgorithm CGA;
        if (CGA.fillInArgs(defaultKnapsackProblem, 10, 0.6, 0.1, 35))
        {
            CGA.run();
            defaultKnapsackProblem->displaySolution();
        }      
    }
    


    



    delete defaultKnapsackProblem;
    std::cout << "\nDone!\n";
}
