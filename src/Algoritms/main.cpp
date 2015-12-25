#include <iostream>
#include <vector>
#include "ProductionLine.h"

using namespace std;

int main() {

    std::vector<int> init = {0,1,2,2};

    ProductionLine line(init);
    line.display();
    line.moveToEnd(0);
    line.display();


    return 0;
}
