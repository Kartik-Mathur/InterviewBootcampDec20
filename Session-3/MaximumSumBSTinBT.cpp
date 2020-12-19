// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
class Solution {
public:
    class x{
        public:
        int sum,largest,smallest;
        x(){
            sum = 0;
            smallest = INT_MAX;
            largest = INT_MIN;
        }
    };
    x solve(TreeNode* root,int &msum){
        x ans;
        if(!root) return ans;
        
        // recursive case
        x left = solve(root->left,msum);
        x right = solve(root->right,msum);
        int sum = left.sum+right.sum+root->val;
        
        if(root->val>left.largest && root->val<right.smallest){
            msum = max(msum,sum);
            ans.largest = max(root->val,right.largest);
            ans.smallest = min(root->val,left.smallest);
            ans.sum = sum;
        }
        else{
            ans.largest = INT_MAX;
            ans.smallest = INT_MIN;
            ans.sum = 0;
        }
        return ans;
    }
    
    
    int maxSumBST(TreeNode* root) {
        int msum = 0;
        solve(root,msum);
        return msum;
    }
};
