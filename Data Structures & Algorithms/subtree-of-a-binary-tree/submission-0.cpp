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
    bool isSame(TreeNode* p, TreeNode* q) 
    {
        if (p == nullptr && q == nullptr)
            return true;
        
        if (p == nullptr || q == nullptr)
            return false;

        if (p->val!=q->val)
            return false;

        bool sameleft = isSame(p->left, q->left);
        bool sameright = isSame(p->right, q->right);

        return sameleft && sameright;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (root == nullptr)
            return false;

        if (isSame(root, subRoot))
            return true;

        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot) ;
    }
};