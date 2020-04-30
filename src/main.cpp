#include <iostream>
#include <fstream>
#include "Storage.h"

int main() {
    NameGenerator gen("../data/words.txt");

    Storage st;
    st.fillItUp(10000,1000,1000,12);

    std::cout <<st.isAvailableByName("TestBook") << std::endl;
    std::cout <<st.isAvailableByAuthor("TestAuthor") << std::endl;

    st.spill();
    return 0;
}
