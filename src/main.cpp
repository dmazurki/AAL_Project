#include <iostream>
#include <vector>
#include "Algorithm/ProductionLine.h"
#include "Algorithm/Algorithm.h"
#include "Algorithm/InputDataGenerator.h"

using namespace std;

int main() {

    std::vector<int> data = InputDataGenerator(1000,10).generate();
    Algorithm solution = Algorithm(data,Algorithm::BASIC);
    solution.getResult().display();

    return 0;
}
