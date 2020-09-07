#include <iostream>
#include <cstring>

using namespace std;

// Copy Constructor

class String {
    private:
        char* s;
        int size;

    public:
        String(const char* str = NULL);         // Constructor
        ~String() {                             // Destructor
            delete []s;
        }

        String(const String&);                  // Copy Constructor (Declaration only no {})

    public:
        void print() {
            cout << s << endl;
        }

        void change(const char* s);
};

// Parameterized Constructor
String::String(const char* str){
    cout << "Strings Parameterized Constructor Called" << endl;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

// Member Function Change
void String::change(const char* str){
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

// Copy Constructor
String::String(const String& str_obj){
    cout << "Strings Copy Constructor Called" << endl;
    size = str_obj.size;        // str_obj is an Object and not a string
    s = new char[size+1];

    strcpy(s, str_obj.s);
}
