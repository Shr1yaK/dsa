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
    TreeNode* build (vector<int> preorder, vector<int> inorder, int prestart, int prelast, int instart, int inlast)
    {
        if (prestart>prelast || instart>inlast)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[prestart]);

        int rootIndex = instart;

        while (inorder[rootIndex] != root->val)
            rootIndex++;
        
        int leftSize = rootIndex - instart;

        root->left = build(preorder, inorder, prestart + 1, prestart + leftSize, instart, rootIndex - 1);

        root->right = build(preorder, inorder, prestart + leftSize + 1, prelast, rootIndex + 1,inlast);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};