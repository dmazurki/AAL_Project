//
// Created by damian on 24.12.15.
//

#include "Algorithm.h"

Algorithm::Algorithm(const std::vector<int> & input, Algorithm::AlgorithmType algorithmType)
:productionLine(input), currentPosition(0),currentElement(0) {

    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

    int n = productionLine.getN();
    int k = productionLine.getK();

    for (currentPosition = 0; currentPosition < n - k; ++currentPosition) {
        //In this case we do not need to move this element.
        if (productionLine[currentPosition] == currentElement) {
            currentElement = (currentElement + 1) % k;
            continue;
        }

        int explorer = currentPosition;

        //Searching for element to place on current position.
        for (; explorer < n; explorer++)
            if (productionLine[explorer] == currentElement)
                break;

        explorer = correctPosition(explorer);

        int movesToDo = (explorer - currentPosition) / k;
        for (; movesToDo > 0; --movesToDo) {
            productionLine.moveToEnd(currentPosition);
        }
        currentElement = (currentElement + 1) % k;

    }
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();

    timespan = std::chrono::duration_cast<std::chrono::microseconds>(endTime-startTime);
}

std::chrono::duration<long, std::micro> Algorithm::getSortingTime() const{ return timespan;}

ProductionLine Algorithm::getResult() const
{
    std::vector<int> returnValue(productionLine.getN());

    for(int i=0; i<productionLine.getN(); ++i)
    {
        returnValue[i] = productionLine[i];
    }

    return returnValue;
}


int Algorithm::correctPosition(int positionToCorrect)
{
    int n = productionLine.getN();
    int k = productionLine.getK();


    while((positionToCorrect-currentPosition)%k!=0)
    {
        int candidateToMove = positionToCorrect;

        //When element is at the end.
        if(positionToCorrect == n-1)
        {
            productionLine.moveToEnd(n-k-1);
            positionToCorrect = positionToCorrect-k;
            continue;
        }

        if(positionToCorrect>=n-k)
        {
            candidateToMove = n - k - 1;
        }

        for(; candidateToMove >= currentPosition; --candidateToMove)
        {
            if(candidateToMove == currentPosition || candidateToMove + k - 1 == positionToCorrect
               || (((positionToCorrect - currentPosition) + (n  - (candidateToMove + k))) % k == 0))
            {
                productionLine.moveToEnd(candidateToMove);
                positionToCorrect  =  n - k + (positionToCorrect - candidateToMove);
            }
        }
    }
    return positionToCorrect;
}
