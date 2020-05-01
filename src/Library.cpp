

#include "Library.h"

Library::Library() {
    fillItUp(1000,1000,1000,10);
    std::cout << "The Lib was created, there are " << getStockAmount() << " items available" << std::endl;
}

void Library::registerCustomer(Person &person) {
    for(auto& alreadyReg: customers)
        if(checkIfCustomer(person))
            return;
    customers.emplace_back(&person);
    std::cout << person.m_name << " registered at the lib" << std::endl;
}

void Library::borrow(int ID, Person &person) {
    if(checkIfCustomer(person))
    {
        for(auto& slot:person.slots)
            if(slot.second == nullptr)
            {
                slot.second = getItem(ID);
                if(slot.second!= nullptr)
                {
                    std::cout << person.m_name << " borrowed " << slot.second->m_name << std::endl;
                    slot.first = globalRecordCounter;
                    recordsOfAllTransactions.insert(std::make_pair(globalRecordCounter, Record(&person, ID, globalRecordCounter)));
                    globalRecordCounter++;
                }
                return;
            }
    }
}

void Library::giveBack(Person &person) {
    if(checkIfCustomer(person))
    {
        std::cout << person.m_name << " gave all items back" << std::endl;
        for(auto& item:person.slots)
            if(item.second!= nullptr)
            {
                recordsOfAllTransactions.at(item.first).givenBack = true; // clear the record
                placeBack(item.second->m_ID);
                item.second = nullptr;
                item.first=-1;
            }
    }
}

bool Library::checkIfCustomer(Person &persToCheck) {
    for(auto& cust:customers)
        if(&persToCheck==cust)
            return true;
    return false;
}

void Library::deregisterCustomer(Person &person) {
    if(checkIfCustomer(person))
    {
        int iterator =0;
        for(auto& cust:customers)
        {
            if(&person==cust)
            {
                std::cout << person.m_name << " deregistered from the lib" << std::endl;
                customers.erase(customers.begin()+iterator);
                return;
            }
            iterator++;
        }
    }
}

void Library::listNotGivenBackItems() {
    for(auto& rec:recordsOfAllTransactions)
    {
        if(!rec.second.givenBack)
        {
            std::cout << rec.second.person->m_name << " did not give back "
                      << allItems.at(rec.second.ID_borrowed)->m_name << std::endl;
        }
    }
}

void Library::listAllItemsEverBorrowed() {
    for(auto& rec:recordsOfAllTransactions)
    {
            std::cout << "Record: " << rec.second.person->m_name << " borrowed "
                      << allItems.at(rec.second.ID_borrowed)->m_name << std::endl;
    }
}
