/**
 *@author Damian Mazurkiewicz
 */
#include <iostream>
#include "Presentation/Options.h"
#include "Presentation/Application.h"

using namespace std;

int main(int argc, char ** argv) {
    Application(Options(argc,argv));
    return 0;
}
