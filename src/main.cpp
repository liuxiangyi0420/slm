#include "LanguageModel.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: slm <k> <input-file> <output-length>\n";
        return 1;
    }

    int k = std::atoi(argv[1]);
    std::string filename = argv[2];
    int length = std::atoi(argv[3]);

    LanguageModel model(k);
    model.train(filename);

    std::string text = model.generate(length);
    std::cout << text << std::endl;

    return 0;
}
