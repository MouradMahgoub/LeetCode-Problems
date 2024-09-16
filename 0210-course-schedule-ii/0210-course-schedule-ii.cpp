class Solution {
public:
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<bool> inStack;
    bool cycle = false;
    vector<int> ans;

    void dfs (int node) {
        visited[node] = true;
        inStack[node] = true;

        for(int nei : adjList[node]){
            if(!visited[nei])
                dfs(nei);
            else if(inStack[nei])
                cycle = true;
        }

        inStack[node] = false;
        ans.push_back(node);
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjList.resize(numCourses);
        visited.resize(numCourses, false);
        inStack.resize(numCourses, false);

        for(auto preq : prerequisites){
            int u = preq[0], v = preq[1];
            adjList[u].push_back(v);
        }

        for(int i=0; i<numCourses; i++){
            if(!visited[i])
                dfs(i);
        }

        // reverse(ans.begin(), ans.end());

        return cycle ? vector<int>() : ans;
    }
};