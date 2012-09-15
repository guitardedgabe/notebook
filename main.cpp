#include <iostream>
#include <fstream>
using namespace std;

int writeToFile( const string &filename, const string &text ) {
    
    /* Need to user c_str() because constructor for ofstream takes a const char* not a string */
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
}
