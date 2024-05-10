class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        stack<pair<int, int>> st;
        for(int i=0; i<t.size(); i++){
            while(!st.empty() && t[i] > st.top().first){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({t[i], i});
        }
        return ans;
    }
};