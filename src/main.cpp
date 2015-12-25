#include <iostream>
#include <vector>
#include "ProductionLine.h"
#include "Algorithm.h"

using namespace std;

int main() {

    std::vector<int> init = {0,1,2,2,0,0,2,1,1,1,2};

    Algorithm solution = Algorithm(init,Algorithm::BASIC);

    solution.getResult().display();

    return 0;
}
