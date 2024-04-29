class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> minDist(n, vector<int>(n, 1e7));
        for(int i=0; i<n; i++) minDist[i][i] = 0;
        for(auto e : edges){
            minDist[e[0]][e[1]] = e[2]; 
            minDist[e[1]][e[0]] = e[2]; 
        }
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
        int ans = n-1, minCount = n; 
        for(int i=0; i<n; i++){    
            int count = 0;
            for(int j=0; j<n; j++)
                if(minDist[i][j] <= distanceThreshold) count++;
            if(count <= minCount){
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }
};