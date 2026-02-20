class Solution {
public:
    bool solveUsingRec(vector<int>&nums , int index, int sum , int target){
        if(index >= nums.size()){
            return 0;
        }
        if(sum > target){
            return 0;
        }
        if(sum == target){
            return true;
        }

        bool include = solveUsingRec(nums , index +1, sum + nums[index], target);
        bool exclude = solveUsingRec(nums , index+1, sum , target);
        
        return include || exclude;
    }

    bool solveUsingMem(vector<int>&nums , int index , int sum , int target , vector<vector<int>>&dp){
        if(index >= nums.size()){
            return 0;
        }
        if(sum > target){
            return 0;
        }
        if(sum == target){
            return true;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        bool include = solveUsingMem(nums , index +1, sum + nums[index], target, dp);
        bool exclude = solveUsingMem(nums , index+1, sum , target, dp);
        
        dp[index][sum] =  include || exclude;
        return dp[index][sum];


    }


    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i =0; i <n; i++){
            totalSum += nums[i];
        }
        
        if(totalSum %2 ==1){
            return false;
        }
        int target = totalSum /2;
        // bool ans = solveUsingRec(nums , 0, 0, target);
        // return ans;
        vector<vector<int>>dp(n+1, vector<int>(target + 1 ,-1));
        bool ans = solveUsingMem(nums , 0 , 0, target , dp);
        return ans ;
    }
};