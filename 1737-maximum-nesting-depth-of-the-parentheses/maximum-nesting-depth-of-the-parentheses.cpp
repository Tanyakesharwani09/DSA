class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        int openBracket =0;
        for(int i =0 ; i <s.size() ; i++){ 
            if(s[i] == ')'){
                openBracket--;
            }
            else if(s[i] == '('){
                openBracket++;
            }
            ans = max(ans , openBracket);
        }
        return ans ;
        
    }
};