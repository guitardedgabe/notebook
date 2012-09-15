#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <iostream>
#include <ctime>

class Bookshelf {
    
    public:
        
        // Constructor
        Bookshelf();

        Notebook[] get_notebooks();
        string get_author();
    
    private:

        Notebook[] noteBooks;
        string owner;
};

#endif
