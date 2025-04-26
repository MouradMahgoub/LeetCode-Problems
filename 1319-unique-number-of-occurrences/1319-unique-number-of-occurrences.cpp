class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp, numOfocc;
        for(int i : arr) mp[i]++;
        for(auto [i, cnt] : mp)
            if(numOfocc[cnt]++) return false;
        return true;
    }
};