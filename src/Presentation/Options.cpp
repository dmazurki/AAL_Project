//
// Created by damian on 26.12.15.
//

#include "Options.h"
#include <algorithm>

Options::Options(int argc, char ** argv)
{
    options["n"] = "25";
    options["k"] = "3";

    for(std::string s : OPTIONS_WITHOUT_ARGUMENTS)
    {
        if(cmdOptionExists(argv, argc,"-"+s))
            options[s] = "1";
    }

    for(std::string s : OPTIONS_WITH_ARGUMENTS)
    {
        if(cmdOptionExists(argv,argc,"-"+s))
            options[s] = getCmdOption(argv,argc,"-"+s);
    }
}

const std::string & Options::getString(const std::string & option)
{
    return options[option];
}
int Options::getInt(const std::string & option)
{
    return std::stoi(options[option]);
}
bool Options::getBool(const std::string & option)
{
    return !options[option].empty();
}

char * Options::getCmdOption(char ** begin, int elements, const std::string & option)
{
    char ** end = begin+elements;
    char ** foundOption = std::find(begin, begin+elements, option);

    if (foundOption!=end && ++foundOption!=end)
        return *foundOption;
    else
        return nullptr;
}
bool Options::cmdOptionExists(char ** begin, int elements, const std::string & option)
{
    char ** end = begin+elements;
    return std::find(begin, end, option) != end;
}

const std::vector<std::string> Options::OPTIONS_WITHOUT_ARGUMENTS =
        {
                "help",

                "user_input",
                "generator",
                "presentation",

                "basic_algorithm",
                "pattern_algorithm",

                "time",
                "list_steps",
                "steps",
                "result"
        };

const std::vector<std::string> Options::OPTIONS_WITH_ARGUMENTS =
        {
                "n",
                "k"
        };
