

#include "Storage.h"

void Storage::fillItUp(int count_books, int count_audiobooks, int count_videogames, int maxcount_of_item) {


    m_books.emplace_back(Book("TestBook",globalIDcounter,"TestAuthor",100,1,10,2000));
    globalIDcounter++;
    for(int x=0;x<count_books;x++)
    {
        m_books.emplace_back(Book(booknamegen.generateDopeName(1+rand()%4),globalIDcounter,
                authornamegen.generateDopeName(2),rand()%600,rand()%8,rand()%maxcount_of_item,1900+rand()%120));
        globalIDcounter++;
    }
    for(int x=0;x<count_audiobooks;x++)
    {
        m_audiobooks.emplace_back(AudioBook(booknamegen.generateDopeName(1+rand()%4),globalIDcounter,
                authornamegen.generateDopeName(2),rand()%150,rand()%8,rand()%maxcount_of_item,1900+rand()%120));
        globalIDcounter++;
    }
    for(int x=0;x<count_videogames;x++)
    {
        m_videogames.emplace_back(VideoGame(booknamegen.generateDopeName(1+rand()%4),globalIDcounter,
                authornamegen.generateDopeName(1),rand()%8,rand()%maxcount_of_item,1900+rand()%120));
        globalIDcounter++;
    }

    for(auto& book:m_books)
        allItems.insert(std::make_pair(book.m_ID,&book));

    for(auto& vid:m_videogames)
        allItems.insert(std::make_pair(vid.m_ID,&vid));

    for(auto& aud:m_audiobooks)
        allItems.insert(std::make_pair(aud.m_ID,&aud));

    for(auto& i:allItems)
    {
        publicationYearContainer.emplace(std::make_pair(i.second->m_date_of_publication,i.second));
    }

}

Borrowable* Storage::getItem(int ID) {
    if(allItems.find(ID)!=allItems.end())
    {
        if(allItems.at(ID)->m_borrowed < allItems.at(ID)->m_inStock)
        {
            allItems.at(ID)->m_borrowed++;
            return allItems.at(ID);
        }
        return nullptr;
    }
    return nullptr;
}

void Storage::placeBack(int ID) {
    if(allItems.find(ID)!=allItems.end())
    {
        allItems.at(ID)->m_borrowed--;
    }
}

bool Storage::isAvailableByID(int ID){
    if(allItems.find(ID)!=allItems.end())
    {
        if(allItems.at(ID)->m_borrowed < allItems.at(ID)->m_inStock)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool Storage::isAvailableByName(std::string name) {
    for(auto& item:allItems)
        if(item.second->m_name == name)
            return true;
    return false;
}

bool Storage::isAvailableByAuthor(std::string author_name) {
    for(auto& item:allItems)
    {
        auto t = dynamic_cast<Book*>(item.second);
        if(t!=NULL)
            if(t->m_authors_name==author_name)
                return true;
    }
    return false;
}

void Storage::spill() {
    for(auto& item:allItems)
    {
        std::cout << " ID:" << item.first << " Title: " << item.second->m_name << std::endl;
    }
}

int Storage::getAmount(int ID) {
    if(allItems.find(ID)!=allItems.end())
    {
        return allItems.at(ID)->m_inStock;
    }
}

std::vector<Borrowable *> Storage::getAllPubOfYear(int year) {
    auto test = std::pair(year, nullptr);
    std::vector<Borrowable *> to_return;
    auto low = publicationYearContainer.lower_bound(test);
    auto high = publicationYearContainer.upper_bound(test);
    std::multiset <std::pair<int,Borrowable*>> :: iterator itr;
    for(itr=publicationYearContainer.lower_bound(test);itr!=publicationYearContainer.upper_bound(test);++itr)
        to_return.emplace_back(itr->second);
    return to_return;
}

void Storage::printAllPubofYear(int year) {
    auto t = getAllPubOfYear(year);
    std::cout << "All Books of " << year << ":" << std::endl;
    for(auto& s:t)
    {
        std::cout << s->m_name << std::endl;
    }
    std::cout << "Done!" << std::endl;
}

