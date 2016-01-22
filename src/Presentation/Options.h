//
// Created by damian on 26.12.15.
//

#ifndef AAL_OPTIONS_H
#define AAL_OPTIONS_H

#include <string>
#include <map>
#include <vector>

/**
 * Class for parsing options passed to application and accessing them.
 */
class Options
{
public:
    static const std::vector<std::string> OPTIONS_WITHOUT_ARGUMENTS;
    static const std::vector<std::string> OPTIONS_WITH_ARGUMENTS;

    Options(int argc, char ** argv);

    int getInt(const std::string & option);
    bool getBool(const std::string & option);
    const std::string & getString(const std::string & option);

private:
    char * getCmdOption(char ** begin, int elements, const std::string & option);
    bool cmdOptionExists(char ** begin, int elements, const std::string & option);

    std::map<std::string,std::string> options;
};
#endif //AAL_OPTIONS_H
