class Solution {
public:
    // int solveUsingMem(vector<int>&nums, int s, int e, vector<int>&dp){
    //     if(s > e){
    //         return 0;
    //     }
    //     //if already exist
    //     if(dp[s] != -1){
    //         return dp[s];
    //     }

    //     //include
    //     int include= nums[s] + solve(nums , s + 2, e, dp);
    //     int exclude = 0 + solve(nums , s +1 , e, dp);

    //     int ans = max(include , exclude);
    //     dp[s] = ans;
    //     return dp[s];
    // }

    // int solveUsingRec(vector<int>&nums, int s, int e){
    //     if(s > e){
    //         return 0;
    //     }

    //     //include
    //     int include= nums[s] + solveUsingRec(nums , s + 2, e);
    //     int exclude = 0 + solveUsingRec(nums , s +1 , e);

    //     int ans = max(include , exclude);
    //     return ans;
    // }

    // int solveUsingTab(vector<int>&nums ,int s, int e){
    //     int n = nums.size();
    //     vector<int>dp(n+2 , 0);
    //     // vector<int>dp2(n , 0);
    //     int ans =0;
    //     for(int i =e; i>=s ; i--){

    //         int include = nums[i] + dp[i+2];
    //         int exclude = 0 + dp[i+1];
    //         dp[i] = max(include , exclude);
    //     }
    //     return dp[s];
    // }


    int solveUsingTabSO(vector<int>&nums ,int s, int e){
        int prev = 0;
        int curr =0;
        for(int i =e; i>=s ; i--){

            int include = nums[i] + prev;
            int exclude = 0 + curr;
            int ans = max(include , exclude);

            prev = curr;
            curr = ans;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        // vector<int>dp1(n, -1);
        // vector<int>dp2(n, -1);

        //first included
        // int ans1 = solve(nums , 0 , n-2 , dp1);
        // //last included
        // int ans2 = solve(nums , 1 , n-1 , dp2);
        // int ans = max(ans1 , ans2);
        // return ans;

        // int ans1 = solveUsingTab(nums , 0 , n-2);
        // int ans2 = solveUsingTab(nums , 1, n-1);
        // int ans =  max(ans1 , ans2);
        // return ans;

        int ans1 = solveUsingTabSO(nums , 0 , n-2);
        int ans2 = solveUsingTabSO(nums , 1, n-1);
        int ans =  max(ans1 , ans2);
        return ans;
        
    }
};