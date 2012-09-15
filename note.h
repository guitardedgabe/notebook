#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <ctime>

class Note {
    
    public:
        
        // Constructor
        Note();

        // Note view( title ); // Method to "print" a note into the terminal with its attrs
    
    private:

        time_t created;
        time_t lastUpdated;
        string note;
        string title;
        string author;
};

#endif
