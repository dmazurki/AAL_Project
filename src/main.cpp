#include <iostream>
#include <vector>
#include "Algorithm/ProductionLine.h"
#include "Algorithm/Algorithm.h"
#include "Algorithm/InputDataGenerator.h"
#include "Presentation/Options.h"
#include "Presentation/Application.h"

using namespace std;

int main(int argc, char ** argv) {

    char * opts[7] = {"-generator","-n","150","-k","4","-time","-steps"};
    Options options(7,opts);
    Application application(options);


    return 0;
}
