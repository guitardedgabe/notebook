#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector.h>
#include "note.h";

class Notebook {
    
    public:
        
        // Constructor
        Notebook( string );

        string get_name();
        void add_note( string, string );
        void update_note_body( string );
        void update_note_title( string );
        void remove_note( string );
        Note get_note( string );
        string[] list_note_titles();

    
    private:

        vector<Note> notes;
        string name;
};

#endif
