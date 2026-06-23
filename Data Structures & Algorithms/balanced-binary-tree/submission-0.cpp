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
    int dfs(TreeNode* root)
    {
        if (root==nullptr)
            return 0;
        
        int lefth = dfs(root->left);
        int righth = dfs(root->right);

        if(lefth == -1 || righth == -1)
            return -1;
        
        if(abs(lefth - righth) > 1)
            return -1;

        return 1+max(lefth, righth);
    }
    bool isBalanced(TreeNode* root) 
    {
        int balanced = dfs(root);
        if (balanced!=-1) return true;
        return false;
    }
};