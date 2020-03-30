#include "_stl.h"

#include <vector>
#include <algorithm>
using namespace std;

/**
 * Vectors are like Dynamic arrays.
 */

void stl_vector(){

    cout << " ----- Vectors ------- " << endl;

    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";

    // initialize a vector
    vector<int> vec;

    // returns the max_size of vector
    cout << "\nmax_size of vector 1 <int> = " << vec.max_size() << endl;

    vector<double> vec1;

    // returns the max_size of vector
    cout << "max_size of vector 2 <double>= " << vec1.max_size() << endl;

    struct node{
        int id;
        struct node* next;
    };
    vector<node> vec2;

    // returns the max_size of vector
    cout << "max_size of vector 3 <node>= " << vec1.max_size() << endl;

    // Modifiers functions of Vector
    cout << "---------------------------------------\n";
    cout << "Modifier Functions of Vector STL Class\n";
    vector<int> one;
    one.assign(7, 10);      // Assign 10 to first 7 values

    for(auto item : one){
        cout << item << "\n" ;
    }

    // Assigning values from an array or list:
    vector<int> v1;
    int a[] = { 1, 2, 3 };

    cout << "Array : " << endl;
    for (auto item : a){
        cout << item << "\n";
    }

    v1.assign(a, a + 2);        // assign first 2 values

    cout << "Elements of vector1 are\n";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    vector<int> v2;
    v2.assign(a, a + 3);        // assign first 3 values

    cout << "\nElements of vector2 are\n";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    int count = 0;
    vector<int> myvector;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(5);
    myvector.push_back(6);
    // myvector.insert(3, 3);

    // auto it = myvector.emplace(vec.begin(), 15);

    while (!myvector.empty()) {
        count++;
        myvector.pop_back();
    }

    cout << "Count of myvector = " << count << " Size = " << myvector.size() << endl;

    myvector.emplace_back(1);
    myvector.emplace_back(2);
    myvector.emplace_back(3);
    myvector.emplace_back(4);
    myvector.emplace_back(5);
    myvector.emplace_back(6);
    // vector becomes 1, 2, 3, 4, 5, 6

    // printing the vector
    for (auto it = myvector.begin(); it != myvector.end(); ++it)
        cout << ' ' << *it;

    myvector.clear();

    // vector declaration
    vector<string> myvector2;
    myvector2.emplace_back("This");
    myvector2.emplace_back("is");
    myvector2.emplace_back("a");
    myvector2.emplace_back("computer science");
    myvector2.emplace_back("portal");

    for (auto it = myvector2.begin(); it != myvector2.end(); ++it)
        cout << ' ' << *it;

    cout << endl;

    std::vector<int> myvector3 (3,100);
    std::vector<int>::iterator it;

    it = myvector3.begin();
    it = myvector3.insert ( it , 200 );

    myvector3.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector3.begin();

    std::vector<int> anothervector (2,400);
    myvector3.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector3.insert (myvector3.begin(), myarray, myarray+3);

    std::cout << "myvector3 contains:";
    for (it=myvector3.begin(); it<myvector3.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';


}
