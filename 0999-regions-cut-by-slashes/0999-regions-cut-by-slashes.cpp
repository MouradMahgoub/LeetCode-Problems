class Solution {
public:
    map<char, vector<vector<int>>> mp;
    vector<vector<int>> adj;
    int n, m;
    
    void build_graph(vector<string>& grid){
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                auto arr = mp[grid[i][j]];
                for(int ii=i*3; ii<i*3+3; ii++)
                    for(int jj=j*3; jj<j*3+3; jj++)
                        adj[ii][jj] = arr[ii-i*3][jj-j*3];
            }
        }
    }

    vector<vector<bool>> visited;
    bool valid (int i, int j) {
        return i<n && j<m && i>=0 && j>=0;
    }

    void dfs (int i, int j) {
        if(!valid(i, j) || visited[i][j]) return;
        visited[i][j] = true;
        if(adj[i][j] == 0) {
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        mp[' '] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        mp['/'] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
        mp['\\'] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n=grid.size()*3, m=grid[0].size()*3;
        adj.resize(n, vector<int>(m));
        visited.resize(n, vector<bool>(m, false));
        build_graph(grid);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(adj[i][j] == 0 && !visited[i][j]){
                    dfs(i, j);
                    ans++;
                }
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        return ans;   
    }
};