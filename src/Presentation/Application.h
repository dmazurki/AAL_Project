//
// Created by damian on 26.12.15.
//

#ifndef AAL_APPLICATION_H
#define AAL_APPLICATION_H

/**
 * This is the main class that deals with presenting the results of the sorting algorithm.
 * @author Damian Mazurkiewicz
 */

#include "Options.h"

class Application
{
public:
    Application(const Options & options_);

private:
    void runUserInputExecution();
    void generatorExecution();
    void presentationExecution();
    void showHelp();

    Options options;
};

#endif //AAL_APPLICATION_H
