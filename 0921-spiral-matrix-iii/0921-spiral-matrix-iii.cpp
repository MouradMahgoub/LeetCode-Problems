class Solution {
public:

    bool valid (int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int indx = 0;
        int dirX[] = {0, 1, 0, -1};
        int dirY[] = {1, 0, -1, 0};
        vector<vector<int>> ans;
        int currX = rStart, currY = cStart;
        ans.push_back({currX, currY});
        for(int k=1; k<= rows*cols*4; k++){
            for(int i=0; i<2; i++){
                for(int i=0; i<k; i++){
                    currX += dirX[indx%4];
                    currY += dirY[indx%4];
                    if(valid(currX, currY, rows, cols)) ans.push_back({currX, currY});
                }
                indx++;
            }
        }
        return ans;
    }
};