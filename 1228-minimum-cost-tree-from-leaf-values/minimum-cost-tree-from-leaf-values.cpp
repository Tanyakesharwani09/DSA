class Solution {
public:

    int solveUsingRec(vector<int>&arr,  map<pair<int,int>, int>&maxi, int left , int right){
        //leaf node
        if(left == right){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = left; i<right; i++){
            ans = min(ans, maxi[{left, i}]* maxi[{i+1, right}] + solveUsingRec(arr, maxi, left ,i) + solveUsingRec(arr, maxi , i+1, right));
        }
        return ans ;
    }

    int solveUsingMem(vector<int>&arr,  map<pair<int,int>, int>&maxi, int left , int right, vector<vector<int>>&dp){
        //leaf node
        if(left == right){
            return 0;
        }

        if(dp[left][right] != -1){
            dp[left][right];
        }
        int ans = INT_MAX;
        for(int i = left; i<right; i++){
            ans = min(ans, maxi[{left, i}]* maxi[{i+1, right}] + solveUsingMem(arr, maxi, left ,i,dp) +    solveUsingMem(arr, maxi , i+1, right,dp));
        }
        dp[left][right] = ans;
        return dp[left][right] ;
    }

    int solveUsingTab(vector<int>&arr, map<pair<int,int>, int>&maxi){
        int n = arr.size();
        vector<vector<int>>dp(n+2 , vector<int>(n+1 , 0));

        for(int s_index = n; s_index>=0; s_index--){
            for(int e_index =0; e_index <= n-1; e_index++){
                if(s_index >= e_index){
                    continue;
                }
                int ans = INT_MAX;
                for(int i = s_index; i<e_index; i++){
                    ans = min(ans, (maxi[{s_index, i}]*maxi[{i+1, e_index}]) + dp[s_index][i] + dp[i+1][e_index]);
                }
                dp[s_index][e_index] = ans;
            }
        }
        return dp[0][n-1];

    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int>maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];
            for(int j =i+1; j<arr.size(); j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        // return solveUsingRec(arr, maxi , 0 , arr.size()-1);
        // int n = arr.size();
        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return solveUsingMem(arr, maxi ,0 , arr.size()-1 , dp);
        return solveUsingTab(arr, maxi);
    }
};