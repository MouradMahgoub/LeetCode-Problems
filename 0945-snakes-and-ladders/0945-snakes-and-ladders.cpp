class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int curr = 1, indx = 0;    
        unordered_map<int, pair<int, int>> mp;
        for(int i=n-1; i>=0; i--){
            if(indx%2 == 0){
                for(int j=0; j<n; j++)
                    mp[curr++] = {i, j};
            }else{
                for(int j=n-1; j>=0; j--)
                    mp[curr++] = {i, j};
            }
            indx++;
        }
        vector<bool> visited(n*n+1, false);
        queue<int> q;
        q.push(1);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front(); q.pop();
                auto [i, j] = mp[curr];
                if(board[i][j] != -1) curr = board[i][j];
                if(curr == n*n) return ans;
                for(int i=1; i<=6 && curr+i<=n*n; i++){
                    if(visited[curr+i]) continue; 
                    q.push(curr+i);
                    visited[curr+i] = true;
                }
            }
            ans++;
        }
        return -1;
    }
};