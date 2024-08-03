class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i : arr) mp[i]++;
        for(int i : target) 
            if(mp[i]) mp[i]--;
            else return false;
        return true;
    }
};