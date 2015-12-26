//
// Created by damian on 24.12.15.
//

#include "ProductionLine.h"
#include <set>
#include <sstream>
#include <iostream>

ProductionLine::ProductionLine(const std::vector<int> &initializingVector)
:moves()
{
    n = initializingVector.size();
    current = std::shared_ptr<int>(new int[n],[](int * t)->void{delete [] t;});
    other = std::shared_ptr<int>(new int[n],[](int * t)->void{delete [] t;});


    std::set<int> counter;


    for(int i = 0; i<n;++i)
    {
        counter.insert(initializingVector[i]);
        current.get()[i] = initializingVector[i];
    }

    k = counter.size();
}


std::list<int> ProductionLine::getMoves() const
{
    return moves;
}

int& ProductionLine::operator[](int index)
{
   return current.get()[index];
}

const int & ProductionLine::operator[](int index) const
{
    return current.get()[index];
}
/**
 * This method is used to move k adjacent elements starting with 'position' to the end of production line.
 * @param position index of first of k elements to move.
 * @return
 */
int ProductionLine::moveToEnd(int position)
{
    moves.push_back(position);
    bool foundNewStart = false;
    int newPosition = 0;

        for(int i = 0; i<n; i++)
        {
            if(i<position)
                other.get()[i]=current.get()[i];
            else
            if(i>=position&&i<n-k)
                other.get()[i]=current.get()[i+k];
            else
            {
                if(foundNewStart==false)
                {
                    newPosition=i;
                    foundNewStart=true;
                }
                other.get()[i] = current.get()[position + (k + i - n) ];
            }
        }

    current.swap(other);
        return newPosition;
}



void ProductionLine::display() const
{
    std::cout<<"[";
    for(int i = 0 ; i<n; i++)
    {
        std::cout<<current.get()[i]<<" ";
    }
    std::cout<<"]";
    std::cout<<"n = "<<n<<" k = "<<k<<" moves: "<<moves.size()<<std::endl;
}

ProductionLine::~ProductionLine() {

}
