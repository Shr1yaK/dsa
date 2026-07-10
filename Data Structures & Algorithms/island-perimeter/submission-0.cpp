class Solution {
public:
    int dfs (int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) 
            return 1;
        
        if (visited[row][col]==true)
            return 0;
        
        visited[row][col]=true;
        return dfs (row, col+1, grid, visited) + dfs (row+1, col, grid, visited) + dfs(row-1, col, grid, visited) + dfs (row, col-1, grid, visited);
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (grid[i][j]==1)
                    return dfs(i,j, grid, visited);
            }
        }
        return 0;
    }
};