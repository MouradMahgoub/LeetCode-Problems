class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorOfBall;
        unordered_map<int, int> numOfBallswithColor;
        int n = queries.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            int ball = queries[i][0], color = queries[i][1];
            if(colorOfBall.find(ball) != colorOfBall.end()){
                int oldColor = colorOfBall[ball];
                numOfBallswithColor[oldColor]--;
                if(numOfBallswithColor[oldColor] == 0) numOfBallswithColor.erase(oldColor);
            }
            colorOfBall[ball] = color;
            numOfBallswithColor[color]++;
            ans[i] = numOfBallswithColor.size();
        }
        return ans;
    }
};