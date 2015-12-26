//
// Created by damian on 26.12.15.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Application.h"
#include "../Algorithm/InputDataGenerator.h"
#include "../Algorithm/Algorithm.h"

Application::Application(const Options & options_)
:options(options_)
{
    if(options.getBool("generator"))
        generatorExecution();

    if(options.getBool("presentation"))
        presentationExecution();
}

void Application::runUserInputExecution()
{

}
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
        for(int i : moves)
            std::cout<<i<<",";
        std::cout<<std::endl;
    }


}
void Application::presentationExecution()
{
    int k = options.getInt("k");
    int currentN;

    Algorithm::AlgorithmType type = Algorithm::BASIC;
    if(options.getBool("pattern_seeking"))
        type = Algorithm::PATTERN_SEEKING;

    std::list<std::pair<int,long>> times;

    while(true)
    {
        std::cin>>currentN;

        if(!std::cin.good())
            continue;

        if(currentN<0)
            break;

        Algorithm algorithm(InputDataGenerator(currentN,k).generate(),type);

        times.push_back(std::make_pair(currentN,algorithm.getSortingTime().count()));
    }

    int width = 21;
    std::cout<<std::setiosflags(std::ios::left);
    std::cout<<std::setw(width)<<"n"<<std::setw(width)<<"t(n)[ms]"<<"q(n)"<<std::endl;
    for(auto p : times)
    {
        std::cout<<std::setw(width)<<p.first<<std::setw(width)<<p.second<<pow(p.second,0.333)<<std::endl;
    }

}

void Application::showHelp()
{

}