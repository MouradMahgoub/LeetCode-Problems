class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_map<int ,int> mp1, mp2;
        for(int i : nums1) mp1[i]++;
        for(int i : nums2) mp2[i]++;
        for(auto [i, cnt] : mp1)
            if(!mp2[i]) ans[0].push_back(i);
        for(auto [i, cnt] : mp2)
            if(!mp1[i]) ans[1].push_back(i);
        return ans;
    }
};