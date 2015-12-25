//
// Created by damian on 24.12.15.
//

#ifndef AAL_PRODUCTIONLINE_H
#define AAL_PRODUCTIONLINE_H

#include <vector>
#include <memory>

class ProductionLine
{
public:
    ProductionLine(const std::vector<int> & initializingVector);
    int moveToEnd(int index);
    int correct(int referencePosition, int positionToCorrent);
    int & operator[](int index);
    void display() const;
    int getN() const { return n};
    int getK() const { return k;};
    ~ProductionLine();
private:
    int * current;
    int * other;
    int n;
    int k;
};


#endif //AAL_PRODUCTIONLINE_H
