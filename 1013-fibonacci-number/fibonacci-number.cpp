class Solution {
public:
    // int solveUsingMem(int n , vector<int>&dp){
    //     if(n==0||n==1) return n;
    //     //step 3
    //     if(dp[n] != 0){
    //         return dp[n];
    //     }

    //     //step 2
    //     dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
    //     return dp[n];

    // }

    int solveUsingTabulation(int n){
        //step 1
        vector<int>dp(n+1, 0);

        //step 2
        dp[0]= 0;
        if(n == 0 ){
            return dp[0];
        }
        dp[1] = 1;

        //step 3
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int fib(int n) {
        //step 1
    //    vector<int>dp(n+1,0);
    //    int ans = solveUsingMem(n , dp);
        int ans = solveUsingTabulation(n);
        return ans;
    }
};