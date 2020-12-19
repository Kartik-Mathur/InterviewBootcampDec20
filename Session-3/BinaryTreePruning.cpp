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
    void clearTree(TreeNode*root){
        // base case
        if(!root) return;
        
        //recursive case
        clearTree(root->left);
        clearTree(root->right);
        delete root;
        return;
    }
    
    bool solve(TreeNode* root){
        // base 
        if(root == NULL) return false;
        
        // recursive
        bool KyaLeftMeiMilla = solve(root->left);
        bool KyaRightMeiMilla = solve(root->right);
        if(!KyaLeftMeiMilla){
            // clearTree(root->left);
            root->left = NULL;
        }
        if(!KyaRightMeiMilla){
            // clearTree(root->right); 
            root->right = NULL;
        }
        return KyaRightMeiMilla or KyaLeftMeiMilla or root->val;
        // if(KyaRightMeiMilla or KyaLeftMeiMilla or root->val==1) return true;
        // else return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        if(solve(root)) return root;
        return NULL;
    }
};