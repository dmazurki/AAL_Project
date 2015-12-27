#ifndef AAL_INPUTDATAGENERATOR_H
#define AAL_INPUTDATAGENERATOR_H

/**
 * InputDataGenerator is a class for generating vectors of integers. They can be used
 * as input for Algorithm class.
 *
 * @author Damian Mazurkiewicz
 */

#include <list>


class InputDataGenerator
{
public:
    InputDataGenerator(int n, int k);

    std::list<int> generate() const;

    /**Set size of generated vectors.*/
    void setN(int n);
    /**Set range of integers from generated vectors <0,k-1>*/
    void setK(int k);

private:
    /**Size of generated vectors.*/
    int n;
    /**Integers in generated vectors will have values from range <0, k-1>*/
    int k;
};

#endif //AAL_INPUTDATAGENERATOR_H
