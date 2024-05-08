class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;
        for(int i : nums) st.insert(i);
        for(int i : nums){
            if(!st.count(i-1)){
                int temp = 0;
                while(st.count(i)){
                    i++;
                    temp++;
                }
                ans = max(ans, temp); 
            }
        }
        return ans;
    }
};