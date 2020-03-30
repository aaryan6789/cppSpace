
/**
 * SONG AND GENERES | AMAZON OA
 * Given a map Map<String, List<String>> userSongs with usernames as keys and a list of all the songs that the user has listened to as values.
 * Also given a map Map<String, List<String>> songGenres, with song genre as keys and a list of all the songs within that genre as values. The song can only belong to only one genre.
 * The task is to return a map Map<String, List<String>>, where the key is a username and the value is a list of the user's favorite genre(s). Favorite genre is the most listened to genre. A user can have more than one favorite genre if he/she has listened to the same number of songs per each of the genres.
 * Example 1:
 * Input:
 * userSongs = {  
 *    "David": ["song1", "song2", "song3", "song4", "song8"],
 *    "Emma":  ["song5", "song6", "song7"]
 * },
 * songGenres = {  
 *    "Rock":    ["song1", "song3"],
 *    "Dubstep": ["song7"],
 *    "Techno":  ["song2", "song4"],
 *    "Pop":     ["song5", "song6"],
 *    "Jazz":    ["song8", "song9"]
 * }
 * 
 * Output: {  
 *    "David": ["Rock", "Techno"],
 *    "Emma":  ["Pop"]
 * }
 * 
 * Explanation:
 * David has 2 Rock, 2 Techno and 1 Jazz song. So he has 2 favorite genres.
 * Emma has 2 Pop and 1 Dubstep song. Pop is Emma's favorite genre.
 * 
 * Example 2:
 * Input:
 * userSongs = {  
 *    "David": ["song1", "song2"],
 *    "Emma":  ["song3", "song4"]
 * },
 * songGenres = {}
 * 
 * Output: {  
 *    "David": [],
 *    "Emma":  []
 * }
 * 
 */

/**
 * (1) Get a hash map of song to genres for quick lookup as to what genre a particular song is
(2) For each user create a hash map counting the genres they like and keep track of the maximum count (favourite genre)
(3) Find all the genres with this maximum count and add it to the vector of the resulting map for that user

Since we have to iterate through all of songGenres that's o(n) time. Then we go through each user in userSong so that's o(m) time because we have o(1) access for the genreToSong and o(n) space for keeping track of the genre frequency. Then we iterate through all of the genre count and grab the favourite genres, which is o(n) time

So the time complexity is o(n*m + n) and space complexity os o(n)
 */
#include "_stl.h"
#include <vector>

unordered_map<string, vector<string>> 
songsAndGeneres(unordered_map<string,vector<string>>& users, 
                unordered_map<string,vector<string>>& genres) {

    unordered_map<string, string> songToGenre;
    unordered_map<string, unordered_map<string, int>> userToGenre;
    unordered_map<string, vector<string>> result;

    unordered_map<string, int> maxGenre;


    for( auto genre : genres){
        for (auto song : genre.second){
            songToGenre[song] = genre.first;
        }
    }

    for(auto user : users){
        for( auto song : user.second){
            userToGenre[user.first][songToGenre[song]]++;

            auto tempMax = userToGenre[user.first][songToGenre[song]];
            maxGenre[user.first] = std::max(tempMax, maxGenre[user.first]);
        }
    }

    for(auto user: userToGenre){
        for(auto genre : user.second){
            if(genre.second == maxGenre[user.first]){
                result[user.first].push_back(genre.first);
            }
        }
    }
    
    return result;
}























