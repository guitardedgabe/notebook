#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <iostream>
#include <ctime>

class Notebook {
    
    public:
        
        // Constructor
        Notebook();

        Note[] get_notes();
        int create_note( string );
        int remove_note( string );
        int update_note( string );
        string[] list_titles();
    
    private:

        Note[] notes;
        string name;
};

#endif
