class Solution {
public:
    vector<vector<int> > ans;
    
    void solve(TreeNode* root, int sum, vector<int> &x,int cs){
        // base case
        if(!root) return;
        if(!root->left and !root->right and sum == (cs+root->val)){
            // I am on a leaf node
            x.push_back(root->val);
            ans.push_back(x);
            x.pop_back();
            return;
        }
        // recursive case
        x.push_back(root->val);
        solve(root->left,sum,x,cs+root->val);
        solve(root->right,sum,x,cs+root->val);
        x.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return ans;
        vector<int> x;
        solve(root,sum,x,0);
        return ans;
    }
};