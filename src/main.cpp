#include <iostream>
#include <fstream>
#include "Library.h"
#include "Person.h"

int main() {

    Library lib;
    //std::cout << lib.isAvailableByAuthor("TestAuthor") << std::endl;

    NameGenerator gen("../data/names.txt");
    std::vector<Person> persons;
    for(int x=0;x<30;x++)
    {
        persons.emplace_back(Person(gen.generateDopeName(2),rand()%RAND_MAX));
    }

    for(auto& per:persons)
        if(rand()%10>5)
            lib.registerCustomer(per);

    for(auto& per:persons)
        for(int x=0;x<rand()%4;x++)
            lib.borrow(rand()%lib.getStockAmount(),per);

    for(auto& per:persons)
    {
        for(auto& slot:per.slots)
            if(slot!= nullptr)
                std::cout << per.m_name << " has following item with him/her: " << slot->m_name << std::endl;
    }

    for (auto& per:persons)
        lib.giveBack(per);

    for(auto& per:persons)
        if(rand()%10>5)
            lib.deregisterCustomer(per);

    // lib.spill();
    return 0;
}
