class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        int cnt = 0, minDiff = INT_MAX;
        for(int num : nums){
            int xorNum = num^k;
            if(xorNum > num) cnt++;
            ans += max(num, xorNum);
            minDiff = min(minDiff, abs(num - xorNum));
        }
        return cnt&1 ? ans - minDiff : ans;
    }
};