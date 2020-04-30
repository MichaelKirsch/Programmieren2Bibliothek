


#include "NameGenerator.h"

NameGenerator::NameGenerator(std::string filename) {
    srand(time(NULL));
   file.open(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // using printf() in all tests for consistency
            names.emplace_back(line.c_str());
        }
        file.close();
    }
}

std::string NameGenerator::generateDopeName(int how_many_words) {

    int names_available = names.size();
    int multiply = (names_available/RAND_MAX);
    std::string to_return;
    for(int x =0;x<how_many_words;x++)
        if(multiply>0)
            to_return+=names[rand()%names_available+((rand()%(multiply-1))*RAND_MAX)] + " ";
        else
            to_return+=names[rand()%names_available] + " ";
    return to_return;
}
