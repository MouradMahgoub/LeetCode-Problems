class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<profit.size(); i++)
            pq.push({profit[i], difficulty[i]});
        multiset<int> st(worker.begin(), worker.end());
        int ans  = 0;
        while(!pq.empty()){
            auto [prof, diff] = pq.top();
            auto it = st.lower_bound(diff);
            while(it != st.end()){
                ans += prof;
                st.erase(it);
                it = st.lower_bound(diff);
            }
            pq.pop();
        }
        return ans;
    }
};