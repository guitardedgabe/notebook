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
        string title;
        string body;
};

Note::Note( string t, string b ) {

    time_t now = time(0);
    char *dt = ctime( &now );

    created = dt;
    lastUpdated = dt;

    title = t;
    body = b;

}


string Note::get_title() {

    return title;

}


string Note::get_body() {

    return body;

}


void Note::set_title( string new_title ) {

    title = new_title;

}


void Note::set_body( string new_body ) {

    body = new_body;

}


void Note::view_note() {

    cout << "Created: " << created << endl;
    cout << "Last Updated: " << lastUpdated << endl;
    cout << "Title: " << title << endl;
    cout << "Note:" << endl;
    cout << body << endl;

}

#endif
