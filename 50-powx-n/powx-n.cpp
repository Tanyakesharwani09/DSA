class Solution {
public:
    double myPow(double x, int n) {
        //basecase
    //    if(n==0||x==1){
    //     return 1;
    //    }
    //    if(x==0){
    //     return 0;
    //    }
    //    if(n>0){
    //     double ans= x * myPow(x,n-1);
    //     return ans;
    //    }
    //   else{
    //     double ans = (1.0/x)* myPow(x,n+1);
    //     return ans;
    //    }
    // if(n<0)
    //         return myPow(1/x,abs(n));

    //     return (n%2==0 ? myPow(x*x,n/2) : x*myPow(x*x,n/2));
    // }
        // if(x==0) return x;
        // if(n==0) return 1;

        // if(n&1){
        //     if(n>0) return x * pow(myPow(x,n/2), 2);
        //     else return (1/x) * pow(myPow(x,n/2), 2);
        // }
        // else return pow(myPow(x,n/2), 2);
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
        }
        else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
    }    
};