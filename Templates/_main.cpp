
#include <iostream>
using namespace std;

// Templated Functions
template <typename T>
void print(const T &item)
{
    cout << item << endl;
}

// Templated Classes
// 1. Variable Size of the data member in the class
template <int N>
class Array
{
public:
    int arr[N];

public:
    int getSize() const
    {
        return N;
    }
};

// 2. Variable Data member type and size
template <typename T, int N>
class Array1
{
private:
    T arr[N];

public:
    int getSize() const
    {
        return N;
    }
};

int main()
{

    print(6);
    print("harsh");
    print(5.5f);
    print<int>(6);
    print<double>(7.89);

    Array<5> a;
    cout << a.getSize() << endl;

    Array1<double, 4> a1;
    cout << a1.getSize() << endl;

    return 0;
}