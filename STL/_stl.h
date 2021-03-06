
#include <iostream>
#include <iostream>
#include <iomanip>
#include <iosfwd>

#include <unordered_map>
#include <vector>

using namespace std;


void stl_pair();
void stl_vector();
void stl_unordered_map();
void stl_map();

void stl_list();


template <class T1, class T2>
void print_unordered_map(unordered_map<T1,T2>& hash);

unordered_map<string, vector<string>> 
songsAndGeneres(unordered_map<string,vector<string>>& users, 
                unordered_map<string,vector<string>>& genres);