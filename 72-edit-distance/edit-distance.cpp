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

    int solveUsingTabulation(string&a, string&b){
        vector<vector<int>>dp(a.length()+1 ,vector<int>(b.length()+1 , -1));

        for(int row =0; row <= a.length(); row++ ){
            dp[row][b.length()] = a.length() - row;
        }
        for(int col =0; col <= b.length(); col++){
            dp[a.length()][col] = b.length() - col;
        }

        for(int i_index = a.length()-1; i_index >=0; i_index--){
            for(int j_index = b.length()-1; j_index >=0; j_index--){
                int ans =0;
                if(a[i_index] == b[j_index]){
                    ans =0+ dp[i_index +1][j_index +1];
                }
                else{
                    int insert = 1 + dp[i_index][j_index+1];
                    int del = 1 + dp[i_index+1][j_index];
                    int replace = 1 + dp[i_index+1][j_index+1];
                    ans = min(insert , min(del , replace));
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSO(string&a, string&b){
        vector<int>curr(a.length()+1 , 0);
        vector<int>next(a.length()+1 , 0);

        for(int row =0; row <= a.length(); row++ ){
            next[row] = a.length() - row;
        }

        for(int j_index = b.length()-1; j_index >=0; j_index--){
            curr[a.length()] = b.length() - j_index;
            for(int i_index = a.length()-1; i_index >=0; i_index--){
                int ans =0;
                if(a[i_index] == b[j_index]){
                    ans =0+ next[i_index +1];
                }
                else{
                    int insert = 1 + next[i_index];
                    int del = 1 + curr[i_index+1];
                    int replace = 1 + next[i_index+1];
                    ans = min(insert , min(del , replace));
                }
                curr[i_index] = ans;
            }
            //shift
            next= curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // int ans = solveUsingRecursion(word1, word2 , 0 , 0);
        // vector<vector<int>>dp(word1.length()+1 ,vector<int>(word2.length()+1 , -1));
        // int ans = solveUsingMem(word1, word2 , 0 , 0, dp);

        // int ans = solveUsingTabulation(word1 , word2);
        int ans = solveUsingTabulationSO(word1 , word2);

        return ans;
    }
};