#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <ctime>

using namespace std;

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

        string created;
        string lastUpdated;
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

    time_t now = time(0);
    char *dt = ctime( &now );

    lastUpdated = dt;

    title = new_title;

}


void Note::set_body( string new_body ) {

    time_t now = time(0);
    char *dt = ctime( &now );

    lastUpdated = dt;

    body = new_body;

}


void Note::view_note() {

    cout << "=====================================================" << endl;
    cout << "==================== Note View ======================" << endl;
    cout << "Created: " << created << endl;
    cout << "Last Updated: " << lastUpdated << endl;
    cout << "Title: " << title << endl;
    cout << "Note:" << endl;
    cout << body << endl;
    cout << "=====================================================" << endl;
    cout << "=====================================================" << endl;

}

#endif
