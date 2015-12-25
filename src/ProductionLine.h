//
// Created by damian on 24.12.15.
//

#ifndef AAL_PRODUCTIONLINE_H
#define AAL_PRODUCTIONLINE_H

#include <vector>
#include <forward_list>
#include <memory>

class ProductionLine
{
    friend class Algorithm;

public:
    ProductionLine(const std::vector<int> & initializingVector);

    const int & operator[](int index) const;

    std::forward_list<int> getMoves() const;
    void display() const;
    int getN() const { return n;};
    int getK() const { return k;};
    ~ProductionLine();

private:
    int moveToEnd(int index);
    int & operator[](int index);

    int * current;
    int * other;
    int n;
    int k;
    std::forward_list<int> moves;

};


#endif //AAL_PRODUCTIONLINE_H
