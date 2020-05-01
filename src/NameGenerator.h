

#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

//diese Klasse lädt eine txt datei welche über mit \n geteilte wörter verfügt,
//und produziert random strings aus diesen worten

class NameGenerator {
public:
    NameGenerator(std::string filename);
    std::string generateDopeName(int how_many_words);
    ~NameGenerator() = default;
private:
    std::vector<std::string> names;
};



