class Solution {
public:
    int solveUsingRecursion(vector<int>&nums, int index, vector<int>&dp){
        //bc
        if(index >= nums.size()){
            return 0;
        }
        //ans already exist
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solveUsingRecursion(nums, index + 2, dp);
        int exclude = 0 + solveUsingRecursion(nums, index + 1,dp);
        dp[index] = max(include , exclude);
        return dp[index];
    }

    int rob(vector<int>& nums){
        vector<int>dp(nums.size(), -1);
        int index= 0;
        int ans = solveUsingRecursion(nums,index,dp);
        return ans;
        
    }
};