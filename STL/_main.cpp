#include "_stl.h"


int main(){
    // stl_pair();

    // stl_vector();

    // stl_unordered_map();

    // stl_map();
    stl_list();



    cout << sizeof(char) << endl;
    cout << sizeof(int) << endl;

    cout << sizeof(float) << endl;

    cout << sizeof(double) << endl;
    cout << sizeof(bool) << endl;
    cout << sizeof(string) << endl;


    unordered_map<string,vector<string>> users;
    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users["Emma"]  = {"song5", "song6", "song7"};
    
    unordered_map<string,vector<string>> songs;
    songs["Rock"]       = {"song1", "song3"};
    songs["Dubstep"]    = {"song7"};
    songs["Techno"]     = {"song2", "song4"};
    songs["Pop"]        = {"song5", "song6"};
    songs["Jazz"]       = {"song8", "song9"};

    auto result = songsAndGeneres(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
    
    users.clear();
    songs.clear();
    
    users["David"] = {"song1", "song2"};
    users["Emma"] = {"song3", "song4"};
    
    result = songsAndGeneres(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }




}