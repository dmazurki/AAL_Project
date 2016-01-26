#ifndef AAL_ALGORITHM_H
#define AAL_ALGORITHM_H

/**
 * Class that implements algorithms that sort production lines.
 * @author Damian Mazurkiewicz
 */

#include <vector>
#include <chrono>
#include <list>

class Algorithm
{
public:
    enum AlgorithmType { BASIC, PATTERN_SEEKING};
    typedef std::pair<int,std::list<int>::iterator> Position;


    Algorithm(const std::list<int> & input, AlgorithmType algorithmType);

    long getSortingTime() const;

    const std::list<int> getResult() const;
    const std::list<int> getSteps() const;
    const int getStepsQuantity() const;
    const int getN() const;
    const int getK() const;


    static double getQ(int n, long time, int nMedian, long timeMedian, AlgorithmType type);
    static double getQk(int k, long time, int kMedian, long timeMedian, AlgorithmType type);

    static void setRememberingSteps(bool val);
    static bool rememberSteps;

private:
    Position correctPosition(Position positionToCorrect);
    Position moveToEnd(Position position);

    void increment(Position  & p);
    void decrement(Position  & p);


    std::list<int> line;
    std::list<int> steps;
    int stepsQuantity;

    int n;
    int k;
    int currentElement;
    Position currentPosition;
    AlgorithmType algorithm;
    long timeSpan;
};

#endif //AAL_ALGORITHM_H
