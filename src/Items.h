

#pragma once
#include "Borrowable.h"

struct Book : public Borrowable
{
    Book(std::string name, int ID, std::string author, unsigned int page_count, int gen, int stock) : Borrowable(name,ID,stock),
    m_genre(gen),m_authors_name(author),m_page_count(page_count) {};
    int m_genre;
    std::string m_authors_name="Default";
    unsigned int m_page_count;
};

struct VideoGame : public Borrowable
{
    VideoGame(std::string name, int ID, std::string strudioname, int gen, int stock)
    :Borrowable(name,ID,stock),m_studio(strudioname),m_genre(gen){};
    std::string m_studio="EA is Bad";
    int m_genre;
};

struct AudioBook : public Borrowable
{
    AudioBook(std::string name, int ID, std::string author, unsigned int minutes, int gen, int stock) :
    Borrowable(name,ID,stock),m_author(author),m_minutes_long(minutes),m_genre(gen){};
    std::string m_author="Default";
    int m_genre;
    unsigned int m_minutes_long =0;
};