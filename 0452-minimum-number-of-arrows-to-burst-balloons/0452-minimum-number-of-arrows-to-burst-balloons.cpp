class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        for(auto v : points) cout << v[0] << " " << v[1] << "\n";
        int ans = 1;
        int lastEnd = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(lastEnd >= points[i][0]) continue;
            ans++;
            lastEnd = points[i][1];
        }
        return ans;
    }
};