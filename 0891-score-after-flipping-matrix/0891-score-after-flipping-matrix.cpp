class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0; i<rows; i++){
            if(grid[i][0] == 1) continue;
            for(int j=0; j<cols; j++){
                grid[i][j] ^= 1;
            }
        }
        int sum = 0;
        for(int j=0; j<cols; j++){
            int numOnes = 0;
            for(int i=0; i<rows; i++){
                numOnes += grid[i][j];
            }
            numOnes = max(numOnes, rows-numOnes);
            sum +=  numOnes*pow(2, cols-1-j);
        }
        return sum;
    }
};