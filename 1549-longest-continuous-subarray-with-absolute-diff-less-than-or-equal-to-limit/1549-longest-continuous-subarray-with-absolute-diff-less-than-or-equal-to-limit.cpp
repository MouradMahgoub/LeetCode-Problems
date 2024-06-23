class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0, r=0;
        multiset<int> st;
        for(l=0, r=0; r<nums.size(); r++){
            st.insert(nums[r]);
            int maxi = *prev(st.end()), mini = *st.begin();
            if(maxi - mini > limit){
                st.erase(st.find(nums[l]));
                l++;
            }
        }
        return r - l;
    }
};