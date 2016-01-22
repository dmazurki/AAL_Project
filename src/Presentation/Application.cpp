/**
 * author: Damian Mazurkiewicz
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Application.h"
#include "../Algorithms/InputDataGenerator.h"

Application::Application(const Options & options_)
:options(options_)
{
    if(options.getBool("list_steps"))
        Algorithm::setRememberingSteps(true);

    if(options.getBool("help"))
        showHelp();

    if(options.getBool("generator"))
        generatorExecution();
    else
    if(options.getBool("presentation"))
        presentationExecution();
    else
        runUserInputExecution();
}

void Application::runUserInputExecution()
{
    int input;
    while(true)
    {
        std::cin>>input;

        if(input<0)
            break;

       readAndSolve(input);
    }
}

void Application::readAndSolve(int problemSize)
{
    std::list<int> arg;
    int val;
    while(problemSize--)
    {
        std::cin>>val;

        if(!std::cin.good() || val<0)
            return;

        arg.push_back(val);
    }
    Algorithm algorithm(arg,getAlgorithmType());
    presentResult(algorithm);

}

/**
 * Execution type with data generated randomly.
 */
void Application::generatorExecution()
{
    InputDataGenerator generator(options.getInt("n"), options.getInt("k"));
    Algorithm algorithm(generator.generate(), getAlgorithmType());

    presentResult(algorithm);
}

void Application::presentationExecution()
{
    int k = options.getInt("k");
    int currentN;


    std::list<std::pair<int,long>> times;

    while(true)
    {
        std::cin>>currentN;

        if(!std::cin.good())
            continue;

        if(currentN<0)
            break;

        Algorithm algorithm(InputDataGenerator(currentN, k).generate(), getAlgorithmType());
        presentResult(algorithm);

        times.push_back(std::make_pair(currentN,algorithm.getSortingTime()));
    }

    int width = 21;
    std::cout<<std::setiosflags(std::ios::left);
    std::cout<<std::setw(width)<<"n"<<std::setw(width)<<"t(n)[ms]"<<"q(n)"<<std::endl;

    int medianSeek = 0;
    auto medianSeekIterator = times.begin();

    int nMedian;
    long timeMedian;

    if(times.size()%2 ==  0)
    {
        while(medianSeek != (times.size()/2 -1))
        {
            ++medianSeek;
            ++medianSeekIterator;
        }

        auto next = medianSeekIterator;
        ++next;

        nMedian = (medianSeekIterator->first + next->first)/2;
        timeMedian = (medianSeekIterator->second + next->second)/2;

    }
    else {
        while (medianSeek != (times.size() / 2)) {
            ++medianSeek;
            ++medianSeekIterator;
        }
        nMedian = medianSeekIterator->first;
        timeMedian = medianSeekIterator->second;
    }


    for(auto p : times)
    {
        std::cout<<std::setw(width)<<p.first<<std::setw(width)<<p.second<<Algorithm::getQ(p.first,p.second,nMedian,timeMedian,Algorithm::BASIC)<<std::endl;
    }
    std::cout<<"n median: "<<nMedian<<" t(n) median: "<<timeMedian<<std::endl;


}

void Application::showHelp()
{
    std::cout<<"For information about execution modes and program parameters check readme.txt file.";
}

void Application::presentResult(const Algorithm & algorithm)
{
    std::cout<<"Problem solved for n = "<<algorithm.getN()<<", k = "<<algorithm.getK()<<std::endl;
    if(options.getBool("result"))
    {
        std::cout<<"After sorting:"<<std::endl;
        for(int val : algorithm.getResult())
        {
            std::cout<<val<<", ";
        }
        std::cout<<std::endl;
    }
    if(options.getBool("time"))
    {
        std::cout<<"Sorting time: "<<algorithm.getSortingTime()<<std::endl;
    }

    if(options.getBool("steps"))
    {
        std::cout<<"Steps quantity: "<<algorithm.getStepsQuantity()<<std::endl;
    }

    if(options.getBool("list_steps"))
    {
        std::cout<<"List of steps:";
        for(int i : algorithm.getSteps())
            std::cout<<i<<", ";
        std::cout<<std::endl;
    }
}

Algorithm::AlgorithmType Application::getAlgorithmType()
{
    if(options.getBool("pattern_algorithm"))
        return Algorithm::PATTERN_SEEKING;
    else
        return Algorithm::BASIC;
}


