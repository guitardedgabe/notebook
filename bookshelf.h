#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "notebook.h"
//#include <vector.h> // Should be included in notebook.h

class Bookshelf {
    
    public:
        
        // Constructor
        Bookshelf();
        Bookshelf( string );

        bool is_created();
        string get_author();
        void set_author( string );
        void add_notebook( string );
        void remove_notebook( string );
        void list_notebook_names();
        int check_for_notebook( string );
        Notebook get_notebook( int );
    
    private:

        vector<Notebook> notebooks;
        string author;
        bool created;
};

// Constructor
Bookshelf::Bookshelf() {

    created = true;

};


Bookshelf::Bookshelf( string owner ) {

    author = owner;

    created = true;

}


bool Bookshelf::is_created() {

    return created;

}


string Bookshelf::get_author() {

    return author;

}


void Bookshelf::set_author( string owner ) {

    author = owner;

}


void Bookshelf::add_notebook( string name ) {

    Notebook notebook( name );

    notebooks.push_back( notebook );
    
    cout << "Added notebook " << notebook.get_name() << " to the bookshelf." << endl;

}


void Bookshelf::remove_notebook( string name ) {
    
    int result = check_for_notebook( name );

    if ( result >= 0 ) {
        Notebook nb = get_notebook( result );

        notebooks.erase( notebooks.begin() + ( result - 1 ) );

        cout << "Erased the notebook named " << name << " from the bookshelf." << endl;
    } else {
        cout << "Couldn't erase notebook named " << name << " from the bookshelf. It was not found." << endl;
    }

}


void Bookshelf::list_notebook_names() {

    if ( notebooks.size() > 0 ) {
        cout << "Here is a printout of all notebooks in the bookshelf: " << endl;

        for ( int i = 0; i < notebooks.size(); ++i ) {
            Notebook nb = notebooks.at( i );
            cout << nb.get_name() << endl;
        }

        cout << endl;
    } else {
        cout << "There are currently no notebooks in this bookshelf. You should add one!" << endl;
    }

}


int Bookshelf::check_for_notebook( string name ) {

    for ( int i = 0; i < notebooks.size(); ++i ) {
        Notebook nb = notebooks.at( i );

        if ( nb.get_name() == name ) {
            return i;
        }
    }

    return -1;

}


Notebook Bookshelf::get_notebook( int index ) {

    Notebook nb = notebooks.at( index );

    return nb;

}


#endif
