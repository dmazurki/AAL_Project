//
// Created by damian on 26.12.15.
//

#include <iostream>
#include "Application.h"
#include "../Algorithm/InputDataGenerator.h"
#include "../Algorithm/Algorithm.h"

Application::Application(const Options & options_)
:options(options_)
{
    if(options.getBool("generator"))
        generatorExecution();

}

//void Application::runUserInputExecution();
void Application::generatorExecution()
{
    int n = options.getInt("n");
    int k = options.getInt("k");

    Algorithm::AlgorithmType type = Algorithm::BASIC;
    if(options.getBool("pattern_seeking"))
        type = Algorithm::PATTERN_SEEKING;

    InputDataGenerator generator(n,k);
    Algorithm algorithm(generator.generate(),type);

    ProductionLine line =  algorithm.getResult();
    line.display();

    if(options.getBool("time"))
    {
        std::cout<<"time:"<<algorithm.getSortingTime().count()<<std::endl;
    }
    if(options.getBool("steps"))
    {
        std::list<int> moves = line.getMoves();
        std::cout<<"st:";
        std::cout<<moves.size();
        for(int i : moves)
            std::cout<<i;
    }


}
//void Application::presentationExecution();
//void Application::showHelp();