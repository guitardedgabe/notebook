#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "item_manager.h"

void print_bookshelf_menu() {

    cout << "1. Create a bookshelf." << endl;
    cout << "2. Load a bookshelf." << endl;
    cout << "3. List notebook names." << endl;
    cout << "4. See which notebook you currently have open." << endl;
    cout << "5. Switch to a different notebook." << endl;
    cout << "6. List notes in the current notebook." << endl;
    cout << "7. Add a note to the current notebook." << endl;
    cout << "8. Edit a note in the current notebook." << endl;
    cout << "9. View a note in the current notebook." << endl;
    cout << "10. Add a notebook." << endl;

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

    ItemManager itemManager;
    string input;
    bool ok = false;

    while (true) {
    
        cout << "~~~~~Available Commands~~~~~" << endl;

        print_bookshelf_menu();

        cout << "\nSelect an option from the menu: ";
        cin >> input;

        ok = validate_input( input );

        if ( !ok ) {
            while ( !ok ) {
                cout << "\nInvalid input. Please re-enter your response: ";
                cin >> input;

                ok = validate_input( input );
            }
        }

        if ( input == "1" ) {
            itemManager.create_bookshelf();
        }

        else if ( input == "2" ) {
            cout << "You asked to load a bookshelf." << endl;
        }

        else if ( input == "3" ) {
            itemManager.see_notebook_names();
        }

        else if ( input == "4" ) {
            itemManager.get_current_notebook();
        }

        else if ( input == "5" ) {
            itemManager.change_notebook();
        }

        else if ( input == "6" ) {
            itemManager.see_note_titles();
        }

        else if ( input == "7" ) {
            itemManager.add_note();
        }

        else if ( input == "8" ) {
            itemManager.edit_note();
        }

        else if ( input == "9" ) {
            itemManager.see_note();
        }

        else if ( input == "10" ) {
            itemManager.create_notebook();
        }

        else {
            cout << "\nUh oh...\nYou did not select one of the menu choices.\n\n" << endl;
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
