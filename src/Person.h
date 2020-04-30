

#pragma once

#include <string>
#include <iostream>
#include <array>
#include "Borrowable.h"

class Person {
public:
    Person(const std::string &mName,int  passport_number);
    virtual ~Person() = default;
    std::array<Borrowable*,2> slots;
    std::string m_name;
    int passport_nbr;
};



