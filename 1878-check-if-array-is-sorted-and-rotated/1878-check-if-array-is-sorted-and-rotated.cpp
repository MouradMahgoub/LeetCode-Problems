class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        int cnt = 0;
        for(int i=0; i<n; i++)
            if(!(nums[(n+i-1)%n] <= nums[i] && nums[i] <= nums[(i+1)%n])) cnt++;
        return (cnt <= 2);
    }
};