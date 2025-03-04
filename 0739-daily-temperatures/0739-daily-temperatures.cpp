class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> ans(t.size(), 0);
        for(int i=0; i<t.size(); i++){
            while(!st.empty() && t[i] > t[st.top()]){
                ans[st.top()] = i - st.top(); 
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};