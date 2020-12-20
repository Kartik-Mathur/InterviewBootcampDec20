// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)     {
        // base case
        if(!root) return root;
        
        // recursive case
        if(root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left and right) return root;
        if(left) return left;
        return right;
    }
};
