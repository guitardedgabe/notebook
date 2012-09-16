#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "bookshelf.h"

void print_bookshelf_menu() {

    cout << "1. Create a bookshelf." << endl;
    cout << "2. Load a bookshelf." << endl;

}

void print_notebook_menu() {



}

int validate_input( string input ) {

    if ( input == "q" || input == "quit" ) {
        cout << "Goodbye." << endl;
        exit(0);
    }

    // Always return true just for initial testing
    return true;

}

int main() {

    string input;
    bool ok = false;

    while (true) {
    
        print_bookshelf_menu();

        cout << "Select an option from the menu: ";
        cin >> input;

        ok = validate_input( input );

        if ( !ok ) {
            while ( !ok ) {
                cout << "Invalid input. Please re-enter your response: ";
                cin >> input;

                ok = validate_input( input );
            }
        }

        if ( input == "1" ) {
            cout << "You asked to create a bookshelf." << endl;
        }

        else if ( input == "2" ) {
            cout << "You asked to load a bookshelf." << endl;
        }

        else {
            cout << "You did not select one of the menu choices." << endl;
        }

    }

    return 0;

}

/*int writeToFile( const string &filename, const string &text ) {
    
    ofstream myfile(filename.c_str());

    if (myfile.is_open()) {
        
        myfile << text << endl;
        myfile.close();

    } else {
        
        return -1;

    }

    return 0;
}

int main() {
    
    string filename;
    char text[256];

    cout << "Enter a filename to which you will save your note: ";
    cin >> filename;

    cout << "Enter text to write to file " << filename << ": ";
    cin.ignore();
    cin.getline(text, 256);

    filename = filename + ".txt";
    
    int file_write_result = writeToFile( filename, text );

    if ( file_write_result < 0 ) {
        
        cout << "Error writing to file." << endl;
        return 1;

    }

    return 0;
}*/
