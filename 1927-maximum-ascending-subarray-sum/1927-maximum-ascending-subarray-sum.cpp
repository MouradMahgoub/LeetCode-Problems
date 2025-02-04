class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = -1e9, curr = 0, lastNum = -1e9;
        for(int num : nums) {
            curr += num;
            if(num <= lastNum) curr = num;
            if(curr < 0) curr = 0;
            ans = max(ans, curr);
            lastNum = num;
        }
        return ans;
    }
};