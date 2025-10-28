#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>
#include <map>

class RandomGenerator {
private:
    std::mt19937 gen;
public:
    RandomGenerator();
    int getInt(int min, int max);
    char sampleChar(const std::map<char, int> &freqs);
};

#endif
