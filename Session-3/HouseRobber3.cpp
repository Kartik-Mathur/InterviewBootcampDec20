class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        // base case
        if(!root) return {0,0};
        
        // recursive case
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // I will rob the root node
        int RobberyKari = root->val+left.second+right.second;
        // I will not rob the root node
        int op1 = left.first + right.first;
        int op2 = left.first + right.second;
        int op3 = left.second + right.first;
        int op4 = left.second + right.second;
        int RobberyNahiKari = max(op1,max(op2,max(op3,op4)));
        // pair<int,int> p;
        // p.first = RobberyKari;
        // p.second = RobberyNahiKari;
        // return p;
        return {RobberyKari,RobberyNahiKari};
    }
    
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first,ans.second);
    }
};