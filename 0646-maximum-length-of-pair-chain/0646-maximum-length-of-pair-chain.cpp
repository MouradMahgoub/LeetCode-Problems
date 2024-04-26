class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b){return a[1] < b[1];});
        int ans=1, curr=pairs[0][1];
        for(int i=1; i<pairs.size(); i++)
            if(curr < pairs[i][0]){
                curr = pairs[i][1];
                ans++;
            }
        return ans;
    }
};