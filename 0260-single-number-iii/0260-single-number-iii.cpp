class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans1_2 = 0;
        for(int num : nums) ans1_2 ^= num;
        int differ_bit = 1;
        while(!(differ_bit & ans1_2)) differ_bit <<= 1;
        int ans1 = ans1_2, ans2 = ans1_2;
        for(int num : nums) {
            if(num & differ_bit) ans1 ^= num; 
            else ans2 ^= num;
        }
        return {ans1, ans2};
    }
};