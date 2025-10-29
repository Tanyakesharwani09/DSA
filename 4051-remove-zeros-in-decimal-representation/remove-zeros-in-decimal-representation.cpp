class Solution {
public:
    long long removeZeros(long long n) {
        string input = to_string(n);
        string ans ="";
        for(int i=0; i< input.size() ;  i++){
            if(input[i] != '0'){
                ans = ans + input[i];
            }
        }
        long long finalAns = stoll(ans);
        return finalAns;
    }
};