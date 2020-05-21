

#pragma once
#include <vector>
#include <map>
#include <set>
#include "Items.h"
#include "NameGenerator.h"

class Storage {
public:
    Storage(): booknamegen("../data/words.txt"),authornamegen("../data/names.txt"){
        //TODO clear the record file
    };
    void fillItUp(int count_books,int count_audiobooks, int count_videogames, int maxcount_of_item);
    bool isAvailableByID(int ID);
    bool isAvailableByName(std::string name);
    bool isAvailableByAuthor(std::string author_name);
    std::vector<Borrowable*> getAllPubOfYear(int year);
    void printAllPubofYear(int year);

    int getAmount(int ID);
    void spill();
    int getStockAmount(){return allItems.size();};
    ~Storage() = default;

private:
    NameGenerator booknamegen, authornamegen;
    std::vector<Book> m_books;
    std::vector<AudioBook> m_audiobooks;
    std::vector<VideoGame> m_videogames;
    int globalIDcounter=0;

protected:
    std::multiset<std::pair<int,Borrowable*>> publicationYearContainer;
    std::map<int,Borrowable*> allItems;
    Borrowable* getItem(int ID);
    void placeBack(int ID);
};



