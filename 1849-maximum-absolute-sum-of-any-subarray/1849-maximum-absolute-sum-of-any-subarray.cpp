class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxPrfx = 0, minPrfx = 0, prfx = 0;
        for(int num : nums){
            prfx += num;
            maxPrfx = max(maxPrfx, prfx);
            minPrfx = min(minPrfx, prfx);
        }
        return maxPrfx - minPrfx;
    }
};