class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long> maxPoints(m);
        for(int i=0; i<m; i++) maxPoints[i] = points[0][i];
        for(int row=0; row<n-1; row++){
            vector<long> maxL(m), maxR(m);
            vector<long> currRow = maxPoints;
            maxL[0] = currRow[0];
            for(int i=1; i<m; i++) 
                maxL[i] = max(maxL[i-1] - 1, currRow[i]);
            maxR[m-1] = currRow[m-1];
            for(int i=m-2; i>=0; i--) 
                maxR[i] = max(maxR[i+1] - 1, currRow[i]);
            for(int i=0; i<m; i++)
                maxPoints[i] = (long)max(maxL[i], maxR[i]) + (long)points[row+1][i];
        }
        long ans=0;
        for(int i=0; i<m; i++)
            ans = max(ans, maxPoints[i]);
        return ans;
    }
};