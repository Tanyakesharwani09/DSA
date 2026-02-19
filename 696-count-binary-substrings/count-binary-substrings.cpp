class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int>ans;
        int i =0;
        while(i < n) {
            int cnt = 1;
            
            // count consecutive same characters
            while(i + 1 < n && s[i] == s[i + 1]) {
                cnt++;
                i++;
            }
            
            ans.push_back(cnt);
            i++;   // move to next new group
        }
        int finalAns =0;
        for(int i =1; i <ans.size(); i++){
            finalAns += min(ans[i-1], ans[i]);
        }
        return finalAns;
    }
};