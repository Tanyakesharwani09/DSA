class Solution {
public:
    int solveUsingRec(int n, vector<int>&dp){
         if(n==1) return 1;
       else if (n==2) return 2;

       if(dp[n] != -1){
        return dp[n];
       }
        int ans;
        ans=solveUsingRec(n-1,dp) + solveUsingRec(n-2,dp); 
        dp[n] = ans;
        return dp[n];
    }
    int climbStairs(int n) {

        vector<int>dp(n+1 , -1);
        return solveUsingRec(n, dp);
    }
};