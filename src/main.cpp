#include <iostream>
#include <vector>
#include "Algorithm/ProductionLine.h"
#include "Algorithm/Algorithm.h"
#include "Algorithm/InputDataGenerator.h"
#include "Presentation/Options.h"
#include "Presentation/Application.h"

using namespace std;

int main(int argc, char ** argv) {

    char * opts[1] = {"-presentation"};
    Options options(1,opts);
    Application application(options);




    return 0;
}
