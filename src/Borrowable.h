

#pragma once
#include <string>
class Borrowable {
public:
    Borrowable(std::string& _name,int _ID,int stock): m_name(_name),m_ID(_ID),how_many_are_available(stock) { } ;
    virtual ~Borrowable() = default;
    std::string m_name="";
    int m_ID=-1;
    int how_many_are_available = 0;
    int how_many_are_borrowed = 0;
};



