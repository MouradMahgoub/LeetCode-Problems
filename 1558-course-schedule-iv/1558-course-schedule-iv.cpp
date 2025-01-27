class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));
        for(auto edge : prerequisites)
            isPrereq[edge[0]][edge[1]] = true;
        for(int k=0; k<numCourses; k++)
            for(int i=0; i<numCourses; i++)
                for(int j=0; j<numCourses; j++)
                    isPrereq[i][j] = isPrereq[i][j] ||
                                    (isPrereq[i][k] && isPrereq[k][j]);
        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); i++)
            ans[i] = isPrereq[queries[i][0]][queries[i][1]];
        return ans;
    }
};