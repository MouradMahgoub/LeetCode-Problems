class Solution {
public:
    vector<int> twoSum(vector<int>& v, int x) {
        unordered_map<int, int> mp;
        for(int i=0; i<v.size(); i++) {
            mp[v[i]] = i;
        }
        for(int i=0; i<v.size(); i++) {
            int indx = mp[x - v[i]];
            if(indx != 0 && indx != i){
                cout << i << " " << indx;
                return {i, indx};
            }
        }
        return {};
    }
};