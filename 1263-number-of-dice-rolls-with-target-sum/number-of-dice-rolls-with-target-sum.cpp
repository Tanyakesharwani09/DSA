class Solution {
public:
    int solveUsingRec(int n , int k , int target){
        if(target ==0 && n ==0){
            return 1;
        }
        if(target ==0 && n !=0){
            return 0;
        }
        if(target !=0 && n==0){
            return 0;
        }
        int ans =0;
        for(int i =1; i<=k ; i++){
            ans += solveUsingRec(n-1 , k , target-i);
        }
        return ans;
    }

    long long MOD = 1000000007;
    int solveUsingMem(int n , int k , int target,int diceUsed, int currSum,vector<vector<int>>&dp){
        if(diceUsed == n && currSum == target){
            return 1;
        }
        if(diceUsed != n && currSum == target){
            return 0;
        }
        if(diceUsed == n && currSum != target){
            return 0;
        }
        if(dp[diceUsed][currSum] != -1){
            return dp[diceUsed][currSum];
        }
        int ans =0;
        for(int face =1; face<=k ; face++){
            int recAns =0;
            if(currSum + face <= target){
                recAns = solveUsingMem(n , k , target , diceUsed+1, currSum + face, dp);
            }
            ans = (ans%MOD + recAns%MOD) %MOD; 
        }
        dp[diceUsed][currSum] = ans;
        return dp[diceUsed][currSum];
    }

    int solveUsingTab(int n , int k, int target){
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        dp[n][target] =1;

        for(int dice = n-1; dice >=0; dice--){
            for(int sum = target; sum>=0; sum--){
                int ans =0;
                for(int face  =1; face <=k; face++){
                    int recAns =0;
                    if(sum + face <= target){
                        recAns = dp[dice + 1][sum + face];
                    }
                    ans = (ans % MOD + recAns%MOD)%MOD;
                }
                dp[dice][sum] = ans;
            }
        }
        return dp[0][0];
    }
    int numRollsToTarget(int n, int k, int target) {
        // int ans = solveUsingRec(n , k , target);
        // return ans;

        // int diceUsed =0;
        // int currSum =0;
        // vector<vector<int>>dp(n+1 , vector<int>(target +1 , -1));
        // int ans = solveUsingMem(n , k , target,diceUsed, currSum , dp);
        // return ans ;

        int ans = solveUsingTab(n , k , target);
        return ans;
        
    }
};