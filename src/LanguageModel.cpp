#include "LanguageModel.h"
#include "RandomGenerator.h"
#include <fstream>
#include <sstream>
#include <iostream>

LanguageModel::LanguageModel(int k_value) {
    k = k_value;
}

void LanguageModel::train(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return;
    }

    std::ostringstream ss;
    ss << file.rdbuf();
    std::string text = ss.str();

    if ((int)text.size() <= k) return;

    for (size_t i = 0; i + k < text.size(); ++i) {
        std::string w = text.substr(i, k);
        char next = text[i + k];
        model[w][next] += 1;
    }
}

std::string LanguageModel::generate(int length) {
    if (model.empty()) return "";

    RandomGenerator rng;

    auto it = model.begin();
    std::advance(it, rng.getInt(0, model.size() - 1));
    std::string w = it->first;

    std::string output = w;

    for (int i = 0; i < length - k; ++i) {
        if (model.find(w) == model.end()) break;

        std::map<char, int> &next_chars = model[w];
        char c = rng.sampleChar(next_chars);
        output += c;

    
        w = w.substr(1) + c;
    }

    return output;
}
