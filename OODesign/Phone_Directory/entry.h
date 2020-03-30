//----------------- ENTRY.H -----------------

#include <iostream>		// so that we can overload << and >>

using namespace std;

// Declarations for class Entry for a phone directory

class Entry
{
   friend istream& operator >> (istream& a, Entry& e);
   friend ostream& operator << (ostream& a, const Entry& e);

public:
   Entry();			// initializes all values to blanks
   const char* GetName();		// returns name in an entry
	
private:
   char name[20];		// A name is 20 characters,
   char phoneNumber[20];	// so is a phone number,
   char address[20];		// and so is an address.
};
