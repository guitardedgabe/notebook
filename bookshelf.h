#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <iostream>
#include <ctime>
#include "notebook.h"
//#include <vector.h> // Should be included in notebook.h

class Bookshelf {
    
    public:
        
        // Constructor
        Bookshelf( string );

        void add_notebook( string );
        string[] list_notebook_names();
        Notebook get_notebook( string );
        void remove_notebook( string );
        string get_author();
    
    private:

        vector<Notebook> notebooks;
        string author;
};

// Constructor
Bookshelf::Bookshelf( string owner ) {

    author = owner;

}


void Bookshelf::add_notebook( string title ) {

}


string[] Bookshelf::list_notebook_names() {
    
}


Notebook Bookshelf::get_nookbook( string title ) {
    
}


void Bookshelf::remove_notebook( string title ) {
    
}


string Bookshelf::get_author() {

    return author;

}


#endif
