class Solution {
public:
    bool solveUsingRec(string s,  unordered_set<string>&dict){
       if(s.length() ==0){
        return true;
       }

       for(int i= 0; i<s.length(); i++){
            string left = s.substr(0, i+1);

            if(dict.find(left) != dict.end()){
                string right = s.substr(i+1);
                
                bool ans = solveUsingRec(right , dict);
                if(ans == 1){
                    return true;
                }
            }
       }
       return false;
    }

    bool solveUsingMem(int start ,string&s,  unordered_set<string>&dict, vector<int>&dp){
       if(start == s.length()){
        return true;
       }

       if(dp[start] != -1){
        return dp[start];
       }

       for (int end = start; end < s.length(); end++) {

            string left = s.substr(start, end - start + 1);

            if (dict.find(left) != dict.end()) {

                bool result = solveUsingMem(end + 1, s, dict, dp);

                if (result == true) {
                    dp[start] = 1;
                    return true;
                }
            }
        }
       dp[start] = 0;
       return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // return solveUsingRec(s, dict);
        vector<int>dp(s.length(), -1);
        return solveUsingMem(0, s, dict, dp);  
    }
};