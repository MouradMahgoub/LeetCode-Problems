class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> st;
        vector<int> ans(t.size(), 0);
        for(int i=0; i<t.size(); i++){
            while(!st.empty() && t[i] > st.top().second){
                ans[st.top().first] = i - st.top().first; 
                st.pop();
            }
            st.push({i, t[i]});
        }
        return ans;
    }
};