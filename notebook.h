#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include "note.h";

class Notebook {
    
    public:
        
        // Constructor
        Notebook( string );

        string get_name();
        void add_note( string, string );
        void update_note_title( string, string );
        void update_note_body( string, string );
        void remove_note( string );
        void list_note_titles();

    
    private:

        int check_for_note( string );
        Note get_note( int );

        vector<Note> notes;
        string name;
};

// Constructor
Notebook::Notebook( string n ) {

    name = n;

}


string Notebook::get_name() {

    return name;

}


void Notebook::add_note( string title, string body ) {

    Note note( title, body );

    notes.push_back( note );

    cout << "Added note " << note.get_title() << " to the the notebook " << name << "." << endl;

}


void Notebook::update_note_title( string old_title, string new_title ) {
    
    int result = check_for_note( old_title );

    if ( result > 0 ) {
        Note n = get_note( result );

        n.set_title( new_title );

        notes[ result ] = n;

        cout << "Updated note title from " << old_title << " to " << n.get_title() << "." << endl;
    } else { 
        cout << "Couldn't update note titled " << old_title << ". No note by that name was found." << endl;
    }

}


void Notebook::update_note_body( string title, string new_body ) {

    int result = check_for_note( title );

    if ( result > 0 ) {
        Note n = get_note( result );

        n.set_body( new_body );

        notes[ result ] = n;

        cout << "Updated note titled " << n.get_title() << " with the given text." << endl;
    } else {
        cout << "Couldn't update note titled " << title << ". No note by that name was found." << endl;
    }

}


void Notebook::remove_note( string title ) {

    int result = check_for_note( title );

    if ( result > 0 ) {
        notes.erase( notes.begin() + ( result - 1 ) );

        cout << "Erased the note titled " << title << " from the notebook." << endl;
    } else {
        cout << "Couldn't erase note titled " << title << " from the notebook. It was not found." << endl;
    }

}


void Notebook::list_note_titles() {
    
    cout << "Here is a printout of all notes in the notebook " << name << ": " << endl;

    for ( int i = 0; i < notes.size(); ++i ) {
        Note n = notes.at(i);
        cout << n.get_title() << endl;
    }

    cout << endl;

}


int Notebook::check_for_note( string title ) {

    for ( int i = 0; i < notes.size(); ++i ) {
        Note n = notes.at( i );

        if ( n.get_title() == title ) {
            return i;
        }
    }
    
    return -1;

}


Note Notebook::get_note( int index ) {
    
    Note n = notes.at( index );

    return n;

}


#endif
