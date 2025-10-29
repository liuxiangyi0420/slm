#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <map>
#include <string>

class LanguageModel {
private:
    int k;  
    std::map<std::string, std::map<char, int>> model;  
public:
    LanguageModel(int k_value);
    void train(const std::string &filename);
    std::string generate(int length);
};

#endif
