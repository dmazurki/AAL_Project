//
// Created by damian on 24.01.16.
//

#include "SpliceTester.h"
#include <list>
#include <chrono>

long SpliceTester::getSpliceTime(int listElementsCount, int movedElementsCount)
{
    auto l = std::list<int>();
    auto l2 = std::list<int>();
    for(int i = 0; i< listElementsCount; ++i) { l.push_back(i); }

    auto i1 = ++l.begin();
    auto i2 = i1;

    for(int i = 0; i<movedElementsCount; ++i) {++i2;}

    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

    //l.splice(l.end(),l,i1,i2);
    l.size();


    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}
