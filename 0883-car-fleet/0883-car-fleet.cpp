class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> v(n);
        for(int i=0; i<n; i++) v[i] = {position[i], (target-position[i])/(1.0*speed[i])};
        sort(v.begin(), v.end());
        stack<double> st;
        for(int i=n-1; i>=0; i--){
            if(!st.empty() && v[i].second <= st.top()) continue;
            st.push(v[i].second);
        }
        return st.size();
    }
};
        // int ans=1;
        // for(int i=n-1; i>=1; i--){
        //     if(v[i].second >= v[i-1].second){
        //         v[i-1].second = v[i].second;
        //         continue;
        //     }
        //     ans++;
        // }
        // return ans;