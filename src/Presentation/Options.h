//
// Created by damian on 26.12.15.
//

#ifndef AAL_OPTIONS_H
#define AAL_OPTIONS_H

#include <string>
#include <map>

/**
 * Class for parsing options passed to application and accessing them.
 */
class Options
{
public:
    Options(int argc, char ** argv);

    const std::string & getString(const std::string & option);
    int getInt(const std::string & option);
    bool getBool(const std::string & option);

private:
    char * getCmdOption(int argc, char ** argv, const std::string & option);
    bool cmdOptionExists(int argc, char ** argv, const std::string & option);


    std::map<std::string,std::string> options;
};
#endif //AAL_OPTIONS_H
