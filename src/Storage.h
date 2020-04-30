

#pragma once
#include <vector>
#include <map>
#include "Items.h"
#include "NameGenerator.h"

class Storage {
public:
    Storage(): booknamegen("../data/words.txt"),authornamegen("../data/names.txt"){};

    void fillItUp(int count_books,int count_audiobooks, int count_videogames, int maxcount_of_item);

    bool borrow(int ID);
    void placeBack(int ID);

    bool isAvailableByID(int ID);
    bool isAvailableByName(std::string name);
    bool isAvailableByAuthor(std::string author_name);

    void spill();


    ~Storage() = default;

private:
    std::vector<std::string>BookGenres{"Fantasy","Adventure","Romance","Contemporary","Dystopian","Mystery","Horror","Thriller"};

    NameGenerator booknamegen, authornamegen;
    std::vector<Book> m_books;
    std::vector<AudioBook> m_audiobooks;
    std::vector<VideoGame> m_videogames;
    std::map<int,Borrowable*> allItems;
    int globalIDcounter=0;
protected:
};



