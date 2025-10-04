class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> arr(3, "   ");
        for(int i=0; i<moves.size(); i++)
            arr[moves[i][0]][moves[i][1]] = (i&1 ? 'B' : 'A');

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }

        for(int i=0; i<3; i++)
            if(arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
                return string(1, arr[i][0]);
        
        for(int j=0; j<3; j++)
            if(arr[0][j] != ' ' && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
                return string(1, arr[0][j]);
        
        if(arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
            return string(1, arr[0][0]);

        if(arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
            return string(1, arr[0][2]);
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};