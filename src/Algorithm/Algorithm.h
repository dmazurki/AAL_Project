//
// Created by damian on 24.12.15.
//

#ifndef AAL_BASICALGORITHM_H
#define AAL_BASICALGORITHM_H

#include "ProductionLine.h"
#include <vector>
#include <chrono>

class Algorithm
{
public:
    enum AlgorithmType { BASIC, PATTERN_SEEKING};

    Algorithm(const std::vector<int> & input, AlgorithmType algorithmType);

    std::chrono::duration<long,std::milli> getSortingTime() const;
    ProductionLine getResult() const;

private:
    int correctPosition(int positionToCorrect);

    int currentPosition;
    int currentElement;
    ProductionLine productionLine;
    AlgorithmType algorithm;
    std::chrono::milliseconds timespan;
};

#endif //AAL_BASICALGORITHM_H
