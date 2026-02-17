class Solution {
public:
    int solveUsingRecursion(int start, int end){
        if(start>=end){
            return 0;
        }
        int maxi =INT_MAX;
        for(int i = start; i<=end;  i++){
            maxi= min(maxi , i + max(solveUsingRecursion(start , i-1), solveUsingRecursion(i+1 , end)));
        }
        return maxi;
    }

    int solveUsingMem(int start , int end , vector<vector<int>>&dp){
        if(start >=end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int maxi =INT_MAX;
        for(int i = start; i<=end;  i++){
            maxi= min(maxi , i + max(solveUsingMem(start , i-1, dp), solveUsingMem(i+1 , end, dp)));
        }
        dp[start][end] = maxi;
        return dp[start][end];
    }

    int solveUsingTabulation(int n){
        vector<vector<int>>dp(n+2 , vector<int>(n+2, 0));

        for(int start = n; start >=1; start--){
            for(int end = start; end <=n; end++){
                if(start == end){
                    continue;
                }
                else{
                    int maxi =INT_MAX;
                    for(int i = start; i<=end;  i++){
                        maxi= min(maxi , i + max(dp[start][i-1], dp[i+1][end]));
                    }
                    dp[start][end] = maxi;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        
        // int ans = solveUsingRecursion(1, n);
        // vector<vector<int>>dp(n+1 , vector<int>(n+1, -1));
        // int ans = solveUsingMem(1, n, dp);

        int ans = solveUsingTabulation(n);
        return ans;
        
    }
};