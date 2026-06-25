/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>>* g;

    Node* build(int row, int col, int size)
    {
        // Check if entire square is uniform
        bool same = true;
        int firstVal = (*g)[row][col];

        for (int i = row; i < row + size; i++)
        {
            for (int j = col; j < col + size; j++)
            {
                if ((*g)[i][j] != firstVal)
                {
                    same = false;
                    break;
                }
            }

            if (!same)
                break;
        }

        // Base case: all cells identical
        if (same)
            return new Node(firstVal, true);

        // Otherwise split into 4 quadrants
        int half = size / 2;

        Node* topLeft =
            build(row, col, half);

        Node* topRight =
            build(row, col + half, half);

        Node* bottomLeft =
            build(row + half, col, half);

        Node* bottomRight =
            build(row + half, col + half, half);

        // Internal node
        return new Node(
            true,               // value can be anything
            false,              // not a leaf
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid)
    {
        g = &grid;

        int n = grid.size();

        return build(0, 0, n);
    }
};