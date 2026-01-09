class Solution {
public:
    // int solve(vector<int>&coins, int amount){
    //     if(amount ==0){
    //         return 0;
    //     }
    //     int mini = INT_MAX;

    //     for(int i=0; i<coins.size(); i++){
    //         if(amount - coins[i]>=0){
    //             int recursionKaAns = solve(coins, amount - coins[i]);
    //             if(recursionKaAns != INT_MAX){
    //                 int ans = 1 + recursionKaAns;
    //                 mini = min(mini, ans);
    //             }
    //         }
    //     }
    //     return mini;
    // }

    // int solveUsingMem(vector<int>&coins, int amount, vector<int>&dp){
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(dp[amount] != -1){
    //         return dp[amount];
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0; i<coins.size(); i++){
    //         if(amount - coins[i]>=0){
    //             int recursionKaAns = solveUsingMem(coins, amount - coins[i],dp);
    //             if(recursionKaAns != INT_MAX){
    //                 int ans = 1 + recursionKaAns;
    //                 mini = min(mini, ans);
    //             }
    //         }
    //     }
    //     dp[amount] = mini;
    //     return dp[amount];
    // }


    int solveUsingTabulation(vector<int>&coins, int amount){
        vector<int>dp(amount+1, INT_MAX);

        dp[0] = 0;

        for(int value = 1; value <= amount;  value++){
            int mini = INT_MAX;
            for(int i =0; i<coins.size(); i++){
                if(value - coins[i] >=0){
                    int recursionKaAns = dp[value - coins[i]];
                    if(recursionKaAns != INT_MAX){
                        int ans = 1 + recursionKaAns;
                        mini = min(mini ,ans);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
    //    int ans = solve(coins, amount);
    //    if(ans == INT_MAX){
    //         return -1;
    //    }
    //     return ans;

        // vector<int>dp(amount+1, -1);
        // int ans = solveUsingMem(coins, amount , dp);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;

        int ans = solveUsingTabulation(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};