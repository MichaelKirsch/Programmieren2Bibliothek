

#include "Library.h"

Library::Library() {
    fillItUp(1000,1000,1000,10);
    std::cout << "The Lib was created, there are " << getStockAmount() << " items available" << std::endl;
}

void Library::registerCustomer(Person &person) {
    for(auto& alreadyReg: customers)
        if(alreadyReg->m_name == person.m_name && alreadyReg->passport_nbr ==person.passport_nbr)
            return;
    customers.emplace_back(&person);
    std::cout << person.m_name << " registered at the lib" << std::endl;
}

void Library::borrow(int ID, Person &person) {
    if(customerCheck(person))
    {
        for(auto& slot:person.slots)
            if(slot == nullptr)
            {
                slot = getItem(ID);
                if(slot!= nullptr)
                    std::cout << person.m_name << " borrowed " << slot->m_name << std::endl;
                return;
            }
    }
}

void Library::giveBack(Person &person) {
    if(customerCheck(person))
    {
        std::cout << person.m_name << " gave all items back" << std::endl;
        for(auto& item:person.slots)
            if(item!= nullptr)
            {
                placeBack(item->m_ID);
                item= nullptr;
            }
    }
}

bool Library::customerCheck(Person &persToCheck) {
    for(auto& cust:customers)
        if(&persToCheck==cust)
            return true;
    return false;
}

void Library::deregisterCustomer(Person &person) {
    if(customerCheck(person))
    {
        int iterator =0;
        for(auto& cust:customers)
        {
            if(&person==cust)
                customers.erase(customers.begin()+iterator);
            iterator++;
        }
    }
}
