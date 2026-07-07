class Solution {
public:
    long long reverse(int n){
        long long x= 0;
        while(n){
            int digit = n %10;
            x = 10 * x + digit;
            n = n/10;
        }
        return x;
    }
    long long sumAndMultiply(int n) {
        int i =0;
        int x =0;
        long long sum =0;
        while(n){
            int digit = n%10;
            if(digit != 0){
                x = 10*x + digit;
                sum = sum + digit;
            }
            n = n/10;
        }
        long long nonZero = reverse(x);
        return nonZero * sum;
        
    }
};