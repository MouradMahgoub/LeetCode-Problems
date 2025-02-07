class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> ballColor;
        map<int, set<int>> colorBalls;
        vector<int> ans(queries.size(), 0);
        int indx = 0;
        for(auto q : queries){
            int ball = q[0], newColor = q[1];
            if(ballColor.find(ball) != ballColor.end()){
                int oldColor = ballColor[ball];
                colorBalls[oldColor].erase(ball);
                if(colorBalls[oldColor].size() == 0) colorBalls.erase(oldColor);
            }
            colorBalls[newColor].insert(ball);
            ballColor[ball] = newColor;
            ans[indx++] = colorBalls.size();
        }
        return ans;
    }
};