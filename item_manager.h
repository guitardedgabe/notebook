#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include "bookshelf.h"

class ItemManager {

    public:
        
        // Constructor
        ItemManager();

        bool has_bookshelf();
        void get_current_notebook();
        void create_bookshelf();
        void create_notebook();
        void change_notebook();
        void see_notebook_names();
        void add_note();
        void see_note_titles();
        void edit_note();
        void see_note();

    private:
        
        Bookshelf bookshelf;
        Notebook notebook;

};


ItemManager::ItemManager() {}


bool ItemManager::has_bookshelf() {

    return bookshelf.is_created();

}


void ItemManager::get_current_notebook() {

    cout << "The currently selected notebook is " << notebook.get_name() << "." << endl;

}


void ItemManager::create_bookshelf() {
    
    bookshelf = Bookshelf();

    string firstName, lastName;

    cout << "Type the first name of the owner of the bookshelf: ";
    cin >> firstName;
    cout << endl << "Type the last name of the owner of the bookshelf: ";
    cin >> lastName;

    bookshelf.set_author( firstName + " " + lastName );

    cout << "\n\nYour bookshelf has been created, " << firstName << " " << lastName << ".\n" << endl;

}


void ItemManager::create_notebook() {

    string name;

    cout << "What would you like to name this notebook?: ";
    cin >> name;
    
    bookshelf.add_notebook( name );

    cout << "\n\nYour notebook has been created and added to your bookshelf, " << bookshelf.get_author() << ".\n" << endl;


}


void ItemManager::change_notebook() {

    string name;

    cout << "Which notebook would you like to select?: ";
    cin >> name;

    int result = bookshelf.check_for_notebook( name );

    if ( result > 0 ) {
        notebook = bookshelf.get_notebook( result );
        
        cout << "\n\nYou can now view notes from the notebook named " << notebook.get_name() << ".\n" << endl;

    } else {
        cout << "\n\nNo notebook by that name was found.\n" << endl;
    }

}


void ItemManager::see_notebook_names() {

    bookshelf.list_notebook_names();

}


void ItemManager::add_note() {

    string title, body;

    cout << "Type a title for the note: " << endl;
    cin >> title;

    cout << "Now type the note body: " << endl;
    cin >> body;

    notebook.add_note( title, body );

}


void ItemManager::see_note_titles() {

    notebook.list_note_titles();

}


void ItemManager::edit_note() {

    string title, response;

    notebook.list_note_titles();

    cout << "Which note would you like to edit? (Enter title): ";
    cin >> title;

    int result = notebook.check_for_note( title );

    if ( result >= 0 ) {
        cout << "1. Edit title." << endl;
        cout << "2. Edit body." << endl;
        cin >> response;

        if ( response == "1" ) {
            string new_title;

            cout << "Enter new title: ";
            cin >> new_title;

            notebook.update_note_title( title, new_title );
        } else if ( response == "2" ) {
            string body;

            cout << "Enter new note body:" << endl;
            cin >> body;

            notebook.update_note_body( title, body );
        } else {
            cout << "You entered an invalid response." << endl;
        }
    } else {
        cout << "No note by that name was found." << endl;
    }

}


void ItemManager::see_note() {

    string title;

    cout << "Please enter the title of the note you wish to view: ";
    cin >> title;

    int result = notebook.check_for_note( title );

    if ( result >= 0 ) {
        Note n = notebook.get_note( result );

        n.view_note();
    } else {
        cout << "\n\nThere was no note found by that name.\n" << endl;
    }

}


#endif

