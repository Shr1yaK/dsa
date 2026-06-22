/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;
    int dfs(TreeNode* root)
    {
        if (root==nullptr)
            return 0;

        int l_height = dfs(root->left);
        int r_height = dfs(root->right);
        diameter = max(diameter,l_height + r_height);
        return 1 + max(l_height, r_height);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        dfs(root);
        return diameter;
    }
};