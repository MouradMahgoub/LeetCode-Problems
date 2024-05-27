class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<1000; i++){
            auto it = lower_bound(nums.begin(), nums.end(), i);
            if(distance(it, nums.end()) == i) return i;
        }
        return -1;
    }
};