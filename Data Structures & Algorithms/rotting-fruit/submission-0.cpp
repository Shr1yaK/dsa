class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        int fresh = 0;  

        for (int i = 0; i < rows; i++) // push rotten positions first
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)    q.push({i, j});
                else if (grid[i][j] == 1)   fresh++;
            }
        }
        
        if (fresh == 0) return 0;

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                // process one rotten orange
                auto [row, col] = q.front();
                // int row = q.front.first();
                // int col = q.front.second();
                q.pop();

                for (auto [dr, dc] : directions)
                {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    if (newRow<0 || newRow>=rows || newCol<0 || newCol>=cols) continue;
                    if (grid[newRow][newCol] != 1)  continue;
                    grid[newRow][newCol] = 2;
                    fresh--;
                    q.push({newRow, newCol});
                }
            }
            minutes++;
            if (fresh == 0) return minutes;
        }
        
        return -1;
    }
};