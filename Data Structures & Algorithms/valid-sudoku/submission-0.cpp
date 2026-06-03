class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i<9; i++)
        {
            unordered_set <char> row;

            for (int j = 0; j<9; j++)
            {
                char val = board[i][j];

                if (val == '.')
                    continue;
                
                if (row.find(val)!=row.end())
                    return false;

                row.insert(val);
            }
        }

        for (int i = 0; i<9; i++)
        {
            unordered_set <char> col;

            for (int j = 0; j<9; j++)
            {
                char val = board[j][i];

                if (val == '.')
                    continue;
                
                if (col.find(val)!=col.end())
                    return false;

                col.insert(val);
            }
        }

        for (int row = 0; row<9; row=row+3)
        {
            for (int col = 0; col<9; col=col+3)
            {
                unordered_set <char> box;
                
                for (int i = row; i<row+3; i++)
                {
                    for (int j = col; j<col+3; j++)
                    {
                        char val = board[i][j];

                        if (val == '.')
                            continue;
                        
                        if (box.find(val)!=box.end())
                            return false;

                        box.insert(val);
                    }
                }
            }
        }

        return true;  
    }
};