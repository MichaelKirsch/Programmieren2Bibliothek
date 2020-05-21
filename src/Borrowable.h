

#pragma once
#include <string>
class Borrowable {
public:
    Borrowable(std::string& _name,int _ID,int stock, int date): m_name(_name), m_ID(_ID), m_inStock(stock),m_date_of_publication(date) { } ;
    virtual ~Borrowable() = default;
    std::string m_name="";
    int m_ID=-1;
    int m_inStock = 0;
    int m_borrowed = 0;
    int m_date_of_publication = 0;
};



