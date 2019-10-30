#include <iostream>
#include <iomanip>
#include <iosfwd>

#include <unordered_map>
using namespace std;


// Always pass the read only function sthe referrence and const.
// Reference because no copy will happen then
// Templatized Function for Printing unordered Map
template <class T1, class T2>
void print_unordered_map(const unordered_map<T1,T2>& hash){
    cout << setw (5) << "Key" << " -> " << "Val" << endl;
    for (auto x : hash){
        cout << setw (5) << x.first << " -> " << x.second <<endl;
    }
    cout << endl;
}

void stl_unordered_map(){
    cout << "==========================================" << endl;
    cout << "              Unordered Map               " << endl;
    cout << "==========================================" << endl;

    // Inserting in a Map
    // 1. Inserting values by using [] operator
    // 2. Inserting value by insert function

    // 1. Inserting values by using [] operator
    unordered_map<int, int> hash;
    hash[1] = 10;
    hash[2] = 20;

    print_unordered_map(hash);

    // Declaring umap to be of <string, double> type
    // key will be of string type and mapped value will be of double type
    unordered_map<string, double> umap;

    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

    // 2. Inserting value by insert function
    umap.insert(make_pair("e", 2.718));
    umap.insert(make_pair("e", 2.700));

    print_unordered_map(umap);

    // 3. Inserting value by initializer list
    unordered_map<int,int> hash2 ({{1,10}, {2,20}, {3,30}});

    print_unordered_map(hash2);
    cout << "Hash 2 is empty ? = " << (hash2.empty() ? "is empty" : "is not empty" ) << endl;

    unordered_map<string,string> second ( {{"apple","red"},{"lemon","yellow"}} );       // init list
    unordered_map<string,string> third  ( {{"orange","orange"},{"strawberry","red"}} );  // init list
    unordered_map<string,string> fourth (second);                       // copy
    unordered_map<string,string> sixth  (fourth.begin(),fourth.end());  // range

    print_unordered_map(second);
    print_unordered_map(third);
    print_unordered_map(sixth);

    unordered_map<string,double> myrecipe, mypantry = {{"milk",2.0},{"flour",1.5}};

    pair<string,double> myshopping ("baking powder",0.3);

    myrecipe.insert (myshopping);                                       // copy insertion
    myrecipe.insert (make_pair<string,double>("eggs",6.0));        // move insertion
    myrecipe.insert (mypantry.begin(), mypantry.end());                 // range insertion
    myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );                   // initializer list insertion

    std::cout << "myrecipe contains:" << std::endl;
    for (auto& x: myrecipe)
        std::cout << x.first << ": " << x.second << std::endl;

    std::cout << std::endl;

    // Erase
    std::unordered_map<std::string,std::string> country;

    // populating container:
    country["U.S."] = "Washington";
    country["U.K."] = "London";
    country["France"] = "Paris";
    country["Russia"] = "Moscow";
    country["China"] = "Beijing";
    country["Germany"] = "Berlin";
    country["Japan"] = "Tokyo";

    print_unordered_map(country);

    // erase examples:
    country.erase ( country.begin() );      // erasing by iterator
    country.erase ("France");               // erasing by key
    print_unordered_map(country);
    country.erase ( country.find("Germany"), country.end() ); // erasing by range

    // show content:
    for (const auto & x: country )
        std::cout << x.first << ": " << x.second << std::endl;

    cout << endl;

    // Size of the Map
    std::unordered_map<std::string,double> mymap = {{"milk", 2.30},
                                                    {"potatoes", 1.90},
                                                    {"eggs", 0.40}};

    std::cout << "mymap.size() is " << mymap.size() << std::endl;
    std::cout << "mymap.max_size() is " << mymap.max_size() << std::endl;
    print_unordered_map(mymap);


    // Iterators
    unordered_map<string, string>::iterator ite;

    unordered_map<string,string> mymap2;
    mymap2 = {{"Australia","Canberra"}, {"U.S.","Washington"}, {"France","Paris"}};
    mymap2.insert({"Australia", "Sydney"});

    cout << "mymap2 contains:" << endl;
    for (auto it = mymap2.begin(); it != mymap2.end(); ++it)
        std::cout << " " << it->first << ":" << it->second;

    std::cout << std::endl;
    ite = mymap2.begin();
    cout << "myMap2 begin " << ite->first << endl;
    cout << mymap2.bucket_count() << endl;

    cout << mymap2.at("Australia");
    cout << mymap2["Australia"];
    cout << "\nSize " << mymap2.size() << endl;
    cout << mymap2["Austria"];
    cout << "\nSize " << mymap2.size() << endl;
    // cout << mymap2.at("Austrlia");  // Throws out an Exception
    cout << mymap2.at("Austria");

    auto const got = mymap2.find("Australia");

    if ( got == mymap2.end() )
        std::cout << "not found";
    else
        std::cout << got->first << " has " << got->second;

    cout << endl;
}