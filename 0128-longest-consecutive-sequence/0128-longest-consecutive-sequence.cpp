class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;
        for(int i : nums) st.insert(i);
        for(int i : nums){
            if(st.find(i-1) == st.end()){
                int temp = 1;
                while(st.find(i+1) != st.end()){
                    i++;
                    temp++;
                }
                ans = max(ans, temp); 
            }
        }
        return ans;
    }
};