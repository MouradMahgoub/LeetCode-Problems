class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int, int>, int> mp;
        for(auto obstacle : obstacles) mp[{obstacle[0], obstacle[1]}]++;
        int x[] = {0, 1, 0, -1};
        int y[] = {1, 0, -1, 0};
        int dir = 0, ans=0;
        int currX=0, currY=0;
        for(auto move : commands){
            if(move == -1){
                dir = (dir+1)%4;
            }else if(move == -2){
                dir = (dir-1+4)%4;
            }else{
                for(int i=0; i<move; i++){
                    currX += x[dir];
                    currY += y[dir];
                    if(mp[{currX, currY}]){
                        currX -= x[dir];
                        currY -= y[dir];
                        break;
                    }
                }
            }
            ans = max(ans, currX*currX + currY*currY);
        }
        return ans;
    }
};