#include "_stl.h"

#include <list>
#include <vector>
#include <string>

using namespace std;

//function for printing the elements in a list
template <class T>
void print_list(const list<T>& lst) {
    list<int>:: iterator it;
    for(auto it : lst)
        cout << it << "->";

    cout << endl;
}


// Predicate implemented as a function
bool even(const int& value) {
    return (value % 2) == 0;
}

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

void stl_list(){

    list<int> list1;

    // Insert head, index, tail
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_front(5);

    list1.insert(list1.end(), 54);
    list1.insert(list1.begin(), 54);

    list1.insert(--list1.end(), 64);
    list1.insert(++list1.begin(), 64);

    list<int>::iterator it;
    it = list1.begin();
    list1.insert(it, 2);
    print_list(list1);

    list<int> mylist;

    // set some initial values:
    for (int i=1; i<=5; ++i)
        mylist.push_back(i);                      // 1 2 3 4 5

    it = mylist.begin();
    ++it;       // it points now to number 2           ^

    mylist.insert (it,10);                        // 1 10 2 3 4 5

    // "it" still points to number 2                      ^
    mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

    --it;       // it points now to the second 20            ^

    vector<int> myvector (2,30);
    mylist.insert (it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
    cout << "mylist contains:";
    for (it=mylist.begin(); it!=mylist.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    // Initializer List
    list<string> chlist {"a", "b", "c"};
    chlist.insert(chlist.begin(), {"d", "e"});
    for(auto x : chlist){
        cout << x  << "->";
    }

    cout << endl;

    // Erasing from a List
    list<string>::iterator ch_it = chlist.begin();
    advance(ch_it, 3);

    ch_it = chlist.erase(ch_it);
    cout << "ch_it = " << *ch_it << endl;
    print_list(chlist);

    chlist.erase(ch_it);
    print_list(chlist);

    cout << endl;

    chlist.pop_front();
    print_list(chlist);

    chlist.remove("a");
    chlist.insert(chlist.begin(), {"d", "e", "d", "e", "a", "d", "e", "d", "b"});
    print_list(chlist);
    chlist.remove("d");
    print_list(chlist);

    // Access head, index, tail
    int front = list1.front();
    cout << "Front = " << list1.front() << endl;

    print_list(list1);

    cout << "List Iterator = " << *it << endl;

    cout << "mylist backwards:";
    for (list<int>::reverse_iterator rit=list1.rbegin(); rit!=list1.rend(); ++rit)
        cout << ' ' << *rit;

    cout << endl;

    list<int> num_list{ 1, 2, 2, 2, 5, 6, 7 };
    num_list.remove_if(is_odd());
    num_list.remove_if(even);
    for (auto it = num_list.begin(); it != num_list.end(); ++it)
        cout << ' ' << *it;





}