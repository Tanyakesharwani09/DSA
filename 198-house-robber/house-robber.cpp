class Solution {
public:
    // int solveUsingRecursion(vector<int>&nums, int index, vector<int>&dp){
    //     //bc
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     //ans already exist
    //     if(dp[index] != -1){
    //         return dp[index];
    //     }
    //     int include = nums[index] + solveUsingRecursion(nums, index + 2, dp);
    //     int exclude = 0 + solveUsingRecursion(nums, index + 1,dp);
    //     dp[index] = max(include , exclude);
    //     return dp[index];
    // }

    int solveUsingTabulation(vector<int>&nums){
        //step1
        int n = nums.size();
        vector<int>dp(n, -1);
       
       //step2
       dp[n-1] = nums[n-1];
       for(int index = n-2; index>=0; index--){
            int tempAns =0;
            if(index +2 <n){
                tempAns = dp[index +2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include , exclude);
       }
       return dp[0];
    }
       

    int rob(vector<int>& nums){
        int ans = solveUsingTabulation(nums);
        return ans;
        
    }
};