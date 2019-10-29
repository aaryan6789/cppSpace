/* main.cpp  * Created on: Aug 11, 2018 * Author: Harsh */


#include "iostream"
#include "test.hpp"
using namespace std;
/* About Namespace
 * This tells the compiler to assume we are using the standard library,
 * so we don�t have to write std::.
 */


int main(){
	std::cout << "Hello world, I am ready for C++\n";

	// using namespoace
	cout << "Hey, writing std:: is pain, \n";
	cout << "change the program so I don't have to write it.";

	/* C++ Print: Integers and String literals
	 * Any string literal must be enclosed in double quotes.
	 * Numbers do not require double quotes.
	 * If a variable name is used, the value of the variable is printed.
	 */
	int integer = 4543;
	std::cout << "\nThe value of integer is \n" << integer;
	cout << "\n" << integer;

	sizeOfVariables();
	outputFormatting();
	area();
	hello();
	return 0;
}
