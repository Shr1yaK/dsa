class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        //base cases
        if (row < 0 || row >= rows || col < 0 || col >= cols)   return;
        if (visited[row][col]) return;
        visited[row][col]=true;

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto [dr, dc] : directions)
        {
            int newRow = row + dr;
            int newCol = col + dc;
            
            // bounds
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)   continue;
            if (visited[newRow][newCol])    continue;
            if (heights[newRow][newCol] < heights[row][col])    continue;

            dfs(newRow, newCol, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        // pacific
        for (int c = 0; c < cols; c++)
        {
            dfs(0, c, heights, pacific);
            dfs(rows - 1, c, heights, atlantic);
        }
            
        // atlantic
        for (int r = 0; r < rows; r++)
        {
            dfs(r, 0, heights, pacific);
            dfs(r, cols-1, heights, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;

    }
};