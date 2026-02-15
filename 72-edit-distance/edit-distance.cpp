class Solution {
public:
    int solveUsingRecursion(string&a , string&b , int i , int j){
        if ( i >= a.length())
            return (b.length() - j);
        

        if (j >= b.length()){
            return (a.length() - i);
        }
        
        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveUsingRecursion(a,b , i+1 , j+1);
        }
        else{
            int insert = 1 + solveUsingRecursion(a,b, i , j+1);
            int del = 1 + solveUsingRecursion(a,b, i+1, j);
            int replace = 1 + solveUsingRecursion(a,b,i+1 , j+1);
            ans = min(insert , min(del , replace));
        }
        return ans;
    }

    int solveUsingMem(string&a , string&b , int i  , int j, vector<vector<int>>&dp){
        if ( i >= a.length())
            return (b.length() - j);
        

        if (j >= b.length()){
            return (a.length() - i);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = 0 + solveUsingMem(a,b , i+1 , j+1,dp);
        }
        else{
            int insert = 1 + solveUsingMem(a,b, i , j+1,dp);
            int del = 1 + solveUsingMem(a,b, i+1, j,dp);
            int replace = 1 + solveUsingMem(a,b,i+1 , j+1,dp);
            ans = min(insert , min(del , replace));
        }
        dp[i][j] = ans;
        return dp[i][j];



    }

    int minDistance(string word1, string word2) {
        // int ans = solveUsingRecursion(word1, word2 , 0 , 0);
        vector<vector<int>>dp(word1.length()+1 ,vector<int>(word2.length()+1 , -1));
        int ans = solveUsingMem(word1, word2 , 0 , 0, dp);

        return ans;
    }
};