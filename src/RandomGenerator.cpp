#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
    std::random_device rd;
    gen.seed(rd());
}

int RandomGenerator::getInt(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

char RandomGenerator::sampleChar(const std::map<char, int> &freqs) {
    int total = 0;
    for (auto &p : freqs) total += p.second;

    std::uniform_int_distribution<> dist(1, total);
    int rnd = dist(gen);

    int sum = 0;
    for (auto &p : freqs) {
        sum += p.second;
        if (rnd <= sum) return p.first;
    }

    return freqs.begin()->first; // fallback
}
