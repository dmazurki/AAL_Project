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

        if(algorithmType == BASIC) {
            for (; explorer < n; explorer++)
                if (productionLine[explorer] == currentElement)
                    break;
        }
        else if(algorithmType == PATTERN_SEEKING)
        {
            int bestChoice = explorer;
            int bestChoiceLength = 0;
            for(;explorer < n; explorer++)
            {
                if(productionLine[explorer]==currentElement)
                {
                    int length = 1;
                    int elementMatch = currentElement+1;
                    for(int i = 1;i<k && elementMatch<k && explorer+i < n; i++, elementMatch++)
                    {
                        if(productionLine[explorer+i]==elementMatch)
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

        int movesToDo = (explorer - currentPosition) / k;
        for (; movesToDo > 0; --movesToDo) {
            productionLine.moveToEnd(currentPosition);
        }
        currentElement = (currentElement + 1) % k;

    }
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();

    timespan = std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime);
}

std::chrono::duration<long, std::milli> Algorithm::getSortingTime() const{ return timespan;}

ProductionLine Algorithm::getResult() const
{
    return productionLine;
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
                break;
            }
        }
    }
    return positionToCorrect;
}
