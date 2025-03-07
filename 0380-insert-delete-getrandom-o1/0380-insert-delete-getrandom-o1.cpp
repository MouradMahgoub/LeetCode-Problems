class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> v;
public:
    RandomizedSet() {
    }
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;        
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;  
        int last = v.back();
        int indexRemoved = mp[val];
        v[indexRemoved] = last;
        mp[last] = indexRemoved;
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */