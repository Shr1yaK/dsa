class Solution {
public:
    int dfs (int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if (row<0 || col<0 || row>=rows || col>=cols) 
            return 0;
        if (grid[row][col]==0)
            return 0;
        if (visited[row][col])
            return 0;
        visited[row][col]=true;

        return 1+dfs (row, col+1, grid, visited)+dfs (row, col-1, grid, visited)+dfs (row+1, col, grid, visited)+dfs (row-1, col, grid, visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited (grid.size(),vector<bool>(grid[0].size(), false));
        int maxarea= 0;
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
                maxarea = max(maxarea, dfs (i,j,grid,visited));
        }
        return maxarea;
    }
};