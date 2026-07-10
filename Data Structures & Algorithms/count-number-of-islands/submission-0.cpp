class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols)   return;

        if (grid[row][col]=='0')    return;
        if (visited[row][col])    return;

        visited[row][col]=true;
        
        dfs (row, col+1, grid, visited);
        dfs (row, col-1, grid, visited);
        dfs (row+1, col, grid, visited);
        dfs (row-1, col, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (grid[i][j]=='1' && visited[i][j]==false)
                {
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};