class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            int newIndx = i;
            while(!st.empty() && heights[i] < heights[st.top()]){
                newIndx = st.top();
                ans = max(ans, (i - st.top())*heights[st.top()]);
                st.pop();
            }
            heights[newIndx] = heights[i];
            st.push(newIndx);
        }
        while(!st.empty()){
            ans = max(ans, (n - st.top())*heights[st.top()]);
            st.pop();
        }
        return ans;
    }
};


        // stack<pair<int, int>> st;
        // int ans = 0, n = heights.size();
        // for(int i=0; i<n; i++){
        //     int indx = i;
        //     while(!st.empty() && heights[i] < st.top().first) {
        //         indx = st.top().second;
        //         int hei = st.top().first, width = i - indx;
        //         ans = max(ans, hei*width);
        //         st.pop();
        //     }
        //     st.push({heights[i], indx});
        // }
        // while(!st.empty()){
        //     ans = max(ans, (st.top().first)*(n-st.top().second));
        //     st.pop();
        // }
        // return ans;