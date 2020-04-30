

#pragma once
#include "Storage.h"
#include "Person.h"
class Library : public Storage{
public:
    Library();
    void deregisterCustomer(Person& person);
    void registerCustomer(Person& person);
    void borrow(int ID, Person& person);
    void giveBack(Person& person);
    ~Library() = default;

private:
    bool customerCheck(Person& persToCheck);
    std::vector<Person*> customers;
protected:
};



