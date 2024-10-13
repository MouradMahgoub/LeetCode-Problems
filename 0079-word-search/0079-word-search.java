class Solution {

    private boolean[][] visited; 

    private boolean valid (int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i <= n-1 && j <= m-1;
    } 

    private boolean dfs (int i, int j, String temp, char[][] board, String word) {
        if(temp.length() == word.length()) 
            return true;
        if(!valid(i, j, board.length, board[0].length) 
        || board[i][j] != word.charAt(temp.length()) || visited[i][j]) 
            return false;
        visited[i][j] = true;
        temp += board[i][j];
        boolean ans =  dfs(i+1, j, temp, board, word)
                    || dfs(i, j+1, temp, board, word)
                    || dfs(i-1, j, temp, board, word)
                    || dfs(i, j-1, temp, board, word);
        visited[i][j] = false;
        return ans;
    }

    public boolean exist(char[][] board, String word) {
        visited = new boolean[board.length][board[0].length];
        for(int i=0; i<board.length; i++)
            for(int j=0; j<board[0].length; j++)
                if(dfs(i, j, "", board, word))
                    return true;
        return false;
    }
}