#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <ctime>

class Note {
    
    public:
        
        // Constructor
        Note( string, string );

        string get_title();
        string get_body();
        void set_title( string );
        void set_body( string );
        void view_note();
    
    private:

        time_t created;
        time_t lastUpdated;
        string note;
        string title;
};

Note::Note( string title, string body ) {

    

}

#endif
