class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size() ;
        int *dp = new int[n];
        
        for(int i = 0 ; i < n ; i++) dp[i] = 1;
        int ans = INT_MIN,x = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <=i - 1; j ++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                    // ans = max(ans,dp[i]);
                    if(dp[i]>ans){
                        ans = dp[i];
                        x = i;
                    }
                }
            }
        }
        int ans1 = ans;
        // Print the lis
        while(dp[x]>=1){
            cout<<nums[x]<<' ';
            if(dp[x] == 1) break;
            // update the value of x
            int i = x-1;
            while(true){
                if(dp[i] == dp[x]-1 and nums[x]>nums[i]){
                    x = i;
                    break;
                }
                i--;
            }
        }
        
        return ans1;
    }
};