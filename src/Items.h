

#pragma once

#include "Borrowable.h"

struct Book : public Borrowable {
    Book(std::string name, int ID, std::string author, unsigned int page_count, int gen, int stock) : Borrowable(name,
                                                                                                                 ID,
                                                                                                                 stock),
                                                                                                      m_genre(gen),
                                                                                                      m_authors_name(
                                                                                                              author),
                                                                                                      m_pages(page_count) {};
    int m_genre = 0;
    std::string m_authors_name = "Default";
    unsigned int m_pages = 0;
};

struct VideoGame : public Borrowable {
    VideoGame(std::string name, int ID, std::string strudioname, int gen, int stock)
            : Borrowable(name, ID, stock), m_studio(strudioname), m_genre(gen) {};
    std::string m_studio = "EA is Bad";
    int m_genre = 0;
};

struct AudioBook : public Borrowable {
    AudioBook(std::string name, int ID, std::string author, unsigned int minutes, int gen, int stock) :
            Borrowable(name, ID, stock), m_authors_name(author), m_minutes(minutes), m_genre(gen) {};
    std::string m_authors_name = "Default";
    int m_genre = 0;
    unsigned int m_minutes = 0;
};