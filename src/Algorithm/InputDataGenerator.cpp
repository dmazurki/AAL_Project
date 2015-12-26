//
// Created by damian on 24.12.15.
//

#include "InputDataGenerator.h"
#include <chrono>
#include <random>
#include <functional>

InputDataGenerator::InputDataGenerator(int n_, int k_)
        :n(n_), k(k_){}

std::vector<int> InputDataGenerator::generate() const
{
    std::vector<int> generated(n);

    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, k-1);

    for(int i = 0; i<n; ++i)
    {
        generated[i] = distribution(generator);
    }

    return generated;
}

void InputDataGenerator::setN(int n_) { n = n_;}

void InputDataGenerator::setK(int k_) { k = k_;};