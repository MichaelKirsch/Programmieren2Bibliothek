

#pragma once

#include <string>

class Person {
public:
    Person(const std::string &mName);
    bool searchForBook(int ID);
    bool searchForAuthor(std::string auth);
    bool searchForName(std::string name);
    virtual ~Person() = default;
    std::string m_name;
};



