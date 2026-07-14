class Solution {
public:
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {    
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) // push treasure positions first
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty())
        {
            pair<int,int> current = q.front();
            int row = current.first;
            int col = current.second;
            q.pop();
            for (auto [dr,dc] : directions)
            {
                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow < 0 || newRow >= rows || newCol<0 || newCol>= cols)  continue;
                if (grid[newRow][newCol]!=INF)  continue;
                // if (grid[newRow][newCol]==-1)   continue;

                grid[newRow][newCol]=grid[row][col]+1;
                q.push({newRow, newCol});
            }
        }
    }
};
