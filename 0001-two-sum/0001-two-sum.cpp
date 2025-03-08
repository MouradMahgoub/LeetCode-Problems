class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int x) {
        vector<pair<int, int>> v(nums.size());
        for(int i=0; i<nums.size(); i++) v[i] = {nums[i], i};
        sort(v.begin(), v.end());
        int i=0, j=v.size()-1;
        while(i < j){
            int currSum = v[i].first + v[j].first;
            if(currSum < x) i++;
            else if(currSum > x) j--;
            else return {v[i].second, v[j].second};
        }
        return {};
    }
};
        // unordered_map<int, int> mp;
        // for(int i=0; i<v.size(); i++) {
        //     mp[v[i]] = i;
        // }
        // for(int i=0; i<v.size(); i++) {
        //     int indx = mp[x - v[i]];
        //     if(indx != 0 && indx != i){
        //         cout << i << " " << indx;
        //         return {i, indx};
        //     }
        // }
        // return {};