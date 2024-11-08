class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, maxCurr = 1, minCurr = 1;
        for(int num : nums){
            if(num == 0){
                ans = max(ans, 0);
                maxCurr = 1;
                minCurr = 1;
                continue;
            }else if(num < 0){
                swap(maxCurr, minCurr);    
            }
            maxCurr = max(num, maxCurr*num);
            minCurr = min(num, minCurr*num);
            ans = max(ans, maxCurr);
        }
        return ans;
    }
};