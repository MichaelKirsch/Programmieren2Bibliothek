

#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

class NameGenerator {
public:
    NameGenerator(std::string filename);
    std::string generateDopeName(int how_many_words);
    ~NameGenerator() = default;
private:
    std::vector<std::string> names;
    std::ifstream file;
};



