

#pragma once
#include "Storage.h"
#include "Person.h"

struct Record
{
    Record(Person* i_pers,int i_ID ,int recNbr): person(i_pers),
                                                 ID_borrowed(i_ID), recordNbr(recNbr){}
    Person* person;
    int ID_borrowed=0;
    bool givenBack=false;
    const int recordNbr;
};

class Library : public Storage{
public:
    Library();
    void deregisterCustomer(Person& person);
    void registerCustomer(Person& person);
    void borrow(int ID, Person& person);
    void giveBack(Person& person);
    void listNotGivenBackItems();
    void listAllItemsEverBorrowed();
    ~Library() = default;

private:
    int globalRecordCounter =0;
    bool checkIfCustomer(Person& persToCheck);
    std::vector<Person*> customers;
    std::map<int,Record> recordsOfAllTransactions;
};



