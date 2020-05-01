

#include "Person.h"

Person::Person(const std::string &mName, int passport_number) : m_name(mName),passport_nbr(passport_number){
    std::cout << "Person " << m_name << " was created" << std::endl;
    for(auto& slot:slots)
        slot.second= nullptr;
}
