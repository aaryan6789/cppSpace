/* main.cpp  * Created on: Aug 11, 2018 * Author: Harsh */

#include "main_arithmetic.hpp"

using namespace std;

int main(){

	// Power Function: pow(x, y) = x^y
	// pow(base, exponent)
	cout << "Power of 3^5 = " << pow(3,5);

	// Area of a Circle
	// M_PI is a macro in cmath library for Pi.
	float area = 0.0;
	float radius = 3.5;
	area = M_PI * radius * radius;

	cout << "\nArea of a Circle of radius = " << radius << " is " << area;

	// Volume
	volume();

	// Variable Assignement
	variableAssignment();

	return 0;
}
