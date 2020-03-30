/* size_of_variables.cpp  * Created on: Aug 11, 2018 * Author: Harsh */

#include <iostream>
#include "test.hpp"

/* GOAL: Practice writing to the console and learn the variables types available
 * in C++.
** Print the sizes of each variable to the console.
** Print them in the following order:
** int, short, long, char, float, double, bool
**
** Use the command sizeof(variable type) ie: sizeof(int)
*/

/** C++ Variable Sizes
 * The size a variable is allocated in memory is dependent upon its type.
 * To determine how many bytes each variable type uses, C++ provides the function
 *
 * sizeof(variableType)
 */

using namespace std;
void sizeOfVariables() {
	cout << "\n ---- sizeOfVariables() -----\n";
	cout << "Print the Sizes of Different data types\n";
	cout << "Integer = " << sizeof(int) << "\n";
	cout << "Short   = " << sizeof(short) << "\n";
	cout << "Long    = " << sizeof(long) << "\n";
	cout << "Char    = " << sizeof(char) << "\n";
	cout << "Float   = " << sizeof(float) << "\n";
	cout << "Double  = " << sizeof(double) << "\n";
	cout << "Bool    = " << sizeof(bool) << "\n";
	return;
}
//std
