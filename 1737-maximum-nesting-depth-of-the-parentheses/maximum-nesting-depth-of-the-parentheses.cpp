class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        int openBracket =0;
        for(char &ch :s){ 
            if(ch == ')'){
                openBracket--;
            }
            else if(ch== '('){
                openBracket++;
            }
            ans = max(ans , openBracket);
        }
        return ans ;
        
    }
};