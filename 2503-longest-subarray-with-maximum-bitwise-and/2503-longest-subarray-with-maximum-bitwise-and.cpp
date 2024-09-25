class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = -1e9;
        for(int i : nums) maxi = max(maxi, i);
        int rep = 0, maxLen = 0;
        for(int num : nums) 
            if(num == maxi) rep++;
            else {
                maxLen = max(maxLen, rep);
                rep = 0;
            }
        return max(maxLen, rep); 
    }
};