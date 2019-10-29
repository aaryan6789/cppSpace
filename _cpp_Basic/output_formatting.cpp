/* output_formatting.cpp  * Created on: Aug 11, 2018 * Author: Harsh */

#include <iostream>
#include <iomanip>
#include "test.hpp"

/*Formatting Output
**Goal: practice using cout to format output to console
**Print the variables in three columns:
**Ints, Floats, Doubles
*/

using namespace std;
int outputFormatting() {
    int a = 45;
    float b = 45.323;
    double c = 45.5468;
    cout << a << setw(15) << b << setw(15) << c << "\n";
    cout << c << setw(15) << b << setw(15) << a << "\n";

    int aa = a + 9;
    float bb = b + 9;
    double cc = c + 9;
    cout << aa << "\t" << bb << "\t" << cc << "\n";
    cout << cc << "\t" << bb << "\t" << aa << "\n";

    int aaa = aa + 9;
    float bbb = bb + 9;
    double ccc = cc + 9;
    cout << aaa << "\t" << bbb << "\t" << ccc << "\n";

    return 0;
}
