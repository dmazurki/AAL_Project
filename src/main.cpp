#include <iostream>
#include "Presentation/Options.h"
#include "Presentation/Application.h"

using namespace std;

int main(int argc, char ** argv) {

    char * opts[5] = {"-presentation","-k","5","-steps","-time"};
    Options options(5,opts);
    Application application(options);




    return 0;
}
