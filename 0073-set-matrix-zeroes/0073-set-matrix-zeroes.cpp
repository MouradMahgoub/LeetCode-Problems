class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        int n = matrix.size(), m = matrix[0].size();
        bool rf = false, cf = false;
        for(int i=0; i<n; i++) if(matrix[i][0] == 0) rf = true;
        for(int j=0; j<m; j++) if(matrix[0][j] == 0) cf = true;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++)
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
        if(rf) for(int i=0; i<n; i++) matrix[i][0] = 0;
        if(cf) for(int j=0; j<m; j++) matrix[0][j] = 0;
    }
};
        // for(int i : rows)
        //     for(int j=0; j<m; j++)
        //         matrix[i][j] = 0;
        // for(int j : cols)
        //     for(int i=0; i<n; i++)
        //         matrix[i][j] = 0;