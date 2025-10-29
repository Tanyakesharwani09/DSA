class Solution {
public:
    // long long removeZeros(long long n) {
    //     string input = to_string(n);
    //     string ans ="";
    //     for(int i=0; i< input.size() ;  i++){
    //         if(input[i] != '0'){
    //             ans = ans + input[i];
    //         }
    //     }
    //     long long finalAns = stoll(ans);
    //     return finalAns;
    // }
    long long removeZeros(long long n){
        long long ans =0 , multi = 1;
        while(n > 0){
            int a = n%10;
            if(a != 0){
                ans += a * multi;
                multi *= 10;
            }
            n = n/10;
        }
        return ans;
        
    }

};