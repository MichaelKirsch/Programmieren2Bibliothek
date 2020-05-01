

#pragma once
#include "Storage.h"
#include "Person.h"

struct Record
{
    Record(Person* i_pers,int i_ID ,int recNbr): person_that_borrowed(i_pers),
    ID_that_was_boorowed(i_ID),recordNbr(recNbr){}
    Person* person_that_borrowed;
    int ID_that_was_boorowed=0;
    bool was_given_back=false;
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
    bool customerCheck(Person& persToCheck);
    std::vector<Person*> customers;
    std::map<int,Record> recordsOfAllTransactions;
protected:
};



