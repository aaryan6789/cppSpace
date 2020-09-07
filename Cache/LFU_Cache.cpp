//minFreq is the smallest frequency so far
//The main idea is to put all keys with the same frequency to a linked list so the most recent one can be evicted;
//mIter stored the key's position in the linked list;


// Basically we have two map,
// 1st: key->{value,frequency, pointer to list}
// 2nd : frequency-> list of keys with same frequency
// the list holds records the order so the list back front is most recently used key
class LFUCache {
public:
    LFUCache(int capacity) {
        maxsize=capacity;
        cursize=0;
        minfreq=0;
    }
    
    // Get the Value of the key if its presen tin the cache.
    // Increase the freq od the key also then
    int get(int key) {
        if(hashmap.find(key)==hashmap.end()) return -1;
        Touch(key);
        return hashmap[key].val;
    }
    
    // Put a Keyvalue pair in the cache
    void put(int key, int value) {
        if(maxsize<=0) 
            return;
        
        // If key dosnt exst in the cache
        if(get(key) !=-1){
            hashmap[key].val=value;
            return;
        }
        
        createNewBucket(key, value);
        
        if(maxsize==cursize){
            cursize--;
            int rm_key = freqmap[minfreq].back();
            freqmap[minfreq].pop_back();
            hashmap.erase(rm_key);
        }
        cursize++;
        minfreq=1;
        return;
    }
    
    // Increase the Freq Of the cache
    void Touch(int key){
        // Get the old freq
        int oldfreq = hashmap[key].freq;
        int newfreq = oldfreq + 1;
        
        if(oldfreq==minfreq and freqmap[oldfreq].size()==1) 
            minfreq=newfreq;
        
        // erase the pointer of the oldFreq
        freqmap[oldfreq].erase(hashmap[key].ptr);
        freqmap[newfreq].push_front(key);       // Put this new Freq of the key in the front of the list 
        
        hashmap[key].freq=newfreq;
        hashmap[key].ptr = freqmap[newfreq].begin();
    }
    
    
    void createNewBucket(int key, int value){
        Bucket newbucket;
        newbucket.freq = 1;
        newbucket.val = value;
        freqmap[1].push_front(key);
        newbucket.ptr = freqmap[1].begin();
        hashmap[key] = newbucket;
    }
    
    int maxsize;
    int cursize;
    int minfreq;

    struct Bucket{
      int val;
      int freq;
      list<int>::iterator ptr;
    };
    unordered_map<int,Bucket>    hashmap; //key->bucket
    unordered_map<int,list<int>> freqmap; //freq->same freq list list front new
};



class LFUCache2 {
private:
    map<int, list<pair<int, int>>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> val;
    unordered_map<int, int> freq;
    int maxCap;
public:
    LFUCache2(int capacity) {
        maxCap = capacity;
    }
    
    int get(int key) {
        if(freq.find(key) != freq.end()) {
            int res = val[key]->second;
            put(key, res);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(freq.find(key) == freq.end()) {
            if(freq.size() == maxCap && cache.size()>0) {
                auto it = cache.begin();
                int eliminate = it->second.back().first;
                it->second.pop_back();
                if(it->second.size() == 0) {
                    cache.erase(it->first);
                }
                freq.erase(eliminate);
                val.erase(eliminate);
            }
            if(freq.size() < maxCap) {
                freq[key]++;
                cache[1].emplace_front(make_pair(key, value));
                val[key] = cache[1].begin();
            }
        }
        else {
            int f = freq[key];
            freq[key]++;
            cache[f].erase(val[key]);
            if(cache[f].size() == 0)
                cache.erase(f);
            cache[f+1].emplace_front(make_pair(key, value));
            val[key] = cache[f+1].begin();
        }
    }
};