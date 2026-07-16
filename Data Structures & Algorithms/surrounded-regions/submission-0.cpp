class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col)
    {
        if (row<0 || col<0 || row>=board.size() || col>=board[0].size()) return;
        if (board[row][col]!='O') return;
        board[row][col]='S';
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }

    void solve(vector<vector<char>>& board) 
    {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r<rows; r++)
        {
            if (board[r][0]=='O')   dfs(board,r,0);
            if (board[r][cols-1]=='O')  dfs(board,r,cols-1);
        }

        for (int c = 0; c<cols; c++)
        {
            if (board[0][c]=='O')   dfs(board,0,c);
            if (board[rows-1][c]=='O')  dfs(board,rows-1,c);
        }

        for (int r = 0; r<rows; r++)
        {
            for (int c = 0; c<cols; c++)
            {
                if (board[r][c]=='O')   board[r][c]='X';
                else if (board[r][c]=='S')   board[r][c]='O';
            }
        }
    }
};