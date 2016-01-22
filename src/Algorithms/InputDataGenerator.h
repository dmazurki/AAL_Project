#ifndef AAL_INPUTDATAGENERATOR_H
#define AAL_INPUTDATAGENERATOR_H

/**
 * InputDataGenerator is a class for generating lists of integers. They can be used
 * as input for Algorithm class.
 * @author Damian Mazurkiewicz
 */

#include <list>


class InputDataGenerator
{
public:
    /**
     * @param n size of generated lists.
     * @param k range of integers within generated lists <0,k-1>
     */
    InputDataGenerator(int n, int k);

    std::list<int> generate() const;

private:
    int n;
    int k;
};

#endif //AAL_INPUTDATAGENERATOR_H
