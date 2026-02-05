class Solution {
public:
    int solve(vector<int>&nums, int s, int e, vector<int>&dp){
        if(s > e){
            return 0;
        }

        //if already exist
        if(dp[s] != -1){
            return dp[s];
        }

        //include
        int include= nums[s] + solve(nums , s + 2, e, dp);
        int exclude = 0 + solve(nums , s +1 , e, dp);

        int ans = max(include , exclude);
        dp[s] = ans;
        return dp[s];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n==1){
            return nums[0];
        }

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);

        //first included
        int ans1 = solve(nums , 0 , n-2 , dp1);

        //last included
        int ans2 = solve(nums , 1 , n-1 , dp2);

        int ans = max(ans1 , ans2);
        return ans;
        
    }
};