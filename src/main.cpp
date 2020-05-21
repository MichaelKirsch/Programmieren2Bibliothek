#include <iostream>
#include <fstream>
#include "Library.h"
#include "Person.h"

int main() {

    Library lib;
    std::cout <<lib.isAvailableByAuthor("TestAuthor") << std::endl;
    std::cout << lib.getAmount(100) << std::endl;

    NameGenerator gen("../data/names.txt");
    std::vector<Person> persons;
    for(int x=0;x<100;x++)
    {
        persons.emplace_back(Person(gen.generateDopeName(2),rand()%RAND_MAX));
    }

    for(auto& per:persons)
        if(rand()%10>5)
            lib.registerCustomer(per);

    for(auto& per:persons)
        for(int x=0;x<rand()%4;x++)
        {
            auto t =rand()%lib.getStockAmount();
            if(lib.isAvailableByID(t))
                lib.borrow(t,per);
        }

    lib.listNotGivenBackItems();

    for (auto& per:persons)
        lib.giveBack(per);


    lib.listNotGivenBackItems();

    for(auto& per:persons)
        if(rand()%10>5)
            lib.deregisterCustomer(per);

    //lib.spill();

    lib.listAllItemsEverBorrowed();
    lib.printAllPubofYear(2000);
    lib.write_transactions_to_file();
    return 0;
}
