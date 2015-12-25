//
// Created by damian on 24.12.15.
//

#include "ProductionLine.h"
#include "ArrayDestructor.hpp"
#include <set>
#include <sstream>
#include <iostream>

ProductionLine::ProductionLine(const std::vector<int> &initializingVector)
{
    n = initializingVector.size();
    current = new int [n];
    other = new int [n];
    std::set<int> counter;


    for(int i = 0; i<n;++i)
    {
        counter.insert(initializingVector[i]);
        current[i] = initializingVector[i];
    }

    k = counter.size();
}

int& ProductionLine::operator[](int index)
{
   return current[index];
}

int ProductionLine::moveToEnd(int position)
{
    bool foundNewStart = false;
    int newPosition = 0;

        for(int i = 0; i<n; i++)
        {
            if(i<position)
                other[i]=current[i];
            else
            if(i>=position&&i<n-k)
                other[i]=current[i+k];
            else
            {
                if(foundNewStart==false)
                {
                    newPosition=i;
                    foundNewStart=true;
                }
                other[i] = current[position + (k + i - n) ];
            }
        }
        std::swap(current,other);
        return newPosition;
}

int ProductionLine::correct(int referencePosition, int positionToCorrect)
{

    int correctedPosition = 0;
    int candidateToMove = positionToCorrect;

    //When element is at the end.
    if(positionToCorrect == n-1)
    {
        moveToEnd(n-k-1);
        return positionToCorrect-k;
    }

    if(positionToCorrect>=n-k)
    {
        candidateToMove = n - k - 1;
    }

    for(; candidateToMove >= referencePosition; --candidateToMove)
    {
        if(candidateToMove == referencePosition || candidateToMove + k - 1 == positionToCorrect)
        {
            correctedPosition = moveToEnd(candidateToMove);
            return correctedPosition+ (positionToCorrect - candidateToMove);
        }

        if((( (positionToCorrect - referencePosition) + (n  - (candidateToMove + k))) % k == 0))
        {
            correctedPosition = moveToEnd(candidateToMove);
            return correctedPosition + (positionToCorrect - candidateToMove);
        }
    }
    return correctedPosition;
}

void ProductionLine::display() const
{
    std::cout<<"[";
    for(int i = 0 ; i<n; i++)
    {
        std::cout<<current[i]<<" ";
    }
    std::cout<<"]";
    std::cout<<"n = "<<n<<" k = "<<k<<std::endl;
}

ProductionLine::~ProductionLine() {
    delete[]current;
    delete[]other;
}
