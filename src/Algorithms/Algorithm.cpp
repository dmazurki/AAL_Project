/**
 * author: Damian Mazurkiewicz
 */

#include "Algorithm.h"
#include <set>
#include <iostream>
#include <cmath>

bool Algorithm::rememberSteps = false;
void Algorithm::setRememberingSteps(bool val)
{
    rememberSteps = val;
}


Algorithm::Algorithm(const std::list<int> & input, Algorithm::AlgorithmType algorithmType)
:steps(),stepsQuantity(0), currentElement(0), algorithm(algorithmType) {

    line = input;

    std::set<int> counter;
    for(int i : line)
        counter.insert(i);

    n = line.size();
    k = counter.size();

    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

    currentPosition = Position(0,line.begin());
    for (; currentPosition.first < n - k; increment(currentPosition)) {

        //In this case we do not need to move this element.
        if (*currentPosition.second == currentElement) {
            currentElement = (currentElement + 1) % k;
            continue;
        }

        Position explorer(currentPosition);

        //Searching for element to place on current position.
        if(algorithmType == BASIC) {
            for (; explorer.first<n-1; increment(explorer))
                if (*explorer.second == currentElement)
                    break;
        }
        else if(algorithmType == PATTERN_SEEKING)
        {
            Position bestChoice = explorer;
            int bestChoiceLength = 0;
            for(;explorer.second!=line.end(); increment(explorer))
            {
                if(*explorer.second==currentElement)
                {
                    int length = 1;
                    int elementMatch = (currentElement+1)%k;
                    Position measure = explorer;

                    for(;length<=k, measure.second!=line.end(); increment(measure), elementMatch=(elementMatch+1)%k)
                    {
                        if(*measure.second==elementMatch)
                            length++;
                        else
                            break;
                    }

                    if(length>bestChoiceLength)
                    {
                        bestChoice=explorer;
                        bestChoiceLength=length;
                    }
                }
            }
            explorer=bestChoice;
        }


        explorer = correctPosition(explorer);

        int movesToDo = (explorer.first - currentPosition.first) / k;
        for (; movesToDo > 0; --movesToDo) {
            moveToEnd(currentPosition);
        }
        currentElement = (currentElement + 1) % k;

    }
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();

    timespan = std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count();
}


Algorithm::Position Algorithm::correctPosition(Algorithm::Position positionToCorrect)
{
    while((positionToCorrect.first-currentPosition.first)%k!=0)
    {
        Algorithm::Position candidateToMove = positionToCorrect;

        //When element is at the end.
        if(positionToCorrect.first == n-1)
        {
            Algorithm::Position pos(n, line.end());
            for(int i = 0; i<k+1;++i) decrement(pos);
            positionToCorrect = moveToEnd(pos);
            continue;
        }

        if(positionToCorrect.first>=n-k)
        {
            Algorithm::Position pos(n, line.end());
            for(int i = 0; i<k+1;++i) decrement(pos);
            candidateToMove = pos;
        }

        for(; candidateToMove.first >= currentPosition.first; decrement(candidateToMove))
        {
            if(candidateToMove.first == currentPosition.first || candidateToMove.first + k - 1 == positionToCorrect.first
               || (((positionToCorrect.first - currentPosition.first) + (n  - (candidateToMove.first + k))) % k == 0))
            {
                moveToEnd(candidateToMove);
                int space = positionToCorrect.first - candidateToMove.first;
                Algorithm::Position newPositionToCorrect(n, line.end());
                for(int i =0; i<k-space; i++) decrement(newPositionToCorrect);
                positionToCorrect  =  newPositionToCorrect;
                break;
            }
        }
    }
    return positionToCorrect;
}

const std::list<int> Algorithm::getResult()  const { return line; }

const std::list<int> Algorithm::getSteps() const { return steps; }

const int Algorithm::getStepsQuantity() const { return  stepsQuantity; }

const int Algorithm::getN() const {return n;};
const int Algorithm::getK() const {return k;};


long Algorithm::getSortingTime() const{ return timespan;}

/**
 * This method is used to move k adjacent elements starting with 'position' to the end of production line.
 * @param position index of first of k elements to move.
 * @return
 */
Algorithm::Position Algorithm::moveToEnd(Algorithm::Position position)
{
    if(rememberSteps == true)
        steps.push_back(position.first);

    stepsQuantity++;

    std::list<int>::iterator sequenceEnd = position.second;

    for(int i = 0; i<k; i++) sequenceEnd++;
    line.splice(line.end(),line,position.second,sequenceEnd);

    if(position.first == currentPosition.first)
        currentPosition=Position(position.first,sequenceEnd);

    return Algorithm::Position(position.first, sequenceEnd);
}

void Algorithm::increment(Algorithm::Position  & p) { ++p.first; ++p.second;}
void Algorithm::decrement(Algorithm::Position  & p) { --p.first; --p.second;}

double Algorithm::getQ(int n, long time, int nMedian, long timeMedian, AlgorithmType type) {
    double nD = (double) n;
    double timeD = (double) time;
    double nMedianD = (double) nMedian;
    double timeMedianD = (double) timeMedian;

    return (timeD/(nD*nD))*((nMedianD*nMedianD)/timeMedianD);
}
