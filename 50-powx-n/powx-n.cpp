// class Solution {
// public:
//     double myPow(double x, int n) {
//         //basecase
//     //    if(n==0||x==1){
//     //     return 1;
//     //    }
//     //    if(x==0){
//     //     return 0;
//     //    }
//     //    if(n>0){
//     //     double ans= x * myPow(x,n-1);
//     //     return ans;
//     //    }
//     //   else{
//     //     double ans = (1.0/x)* myPow(x,n+1);
//     //     return ans;
//     //    }
//     // if(n<0)
//     //         return myPow(1/x,abs(n));

//     //     return (n%2==0 ? myPow(x*x,n/2) : x*myPow(x*x,n/2));
//     // } 
//         // if(x==0) return x;
//         // if(n==0) return 1;

//         // if(n&1){
//         //     if(n>0) return x * pow(myPow(x,n/2), 2);
//         //     else return (1/x) * pow(myPow(x,n/2), 2);
//         // }
//         // else return pow(myPow(x,n/2), 2);

//         //iterative
//     //     double ans = 1.0;
//     //     long long pow = n;
//     //     if (pow < 0) pow = -1 * pow;
//     //     while (pow) {
//     //     if (pow % 2) {
//     //         ans = ans * x;
//     //         pow = pow - 1;
//     //     }
//     //     else {
//     //         x = x * x;
//     //         pow = pow / 2;
//     //     }
//     // }
//     // if (n < 0) ans = (double)(1.0) / (double)(ans);
//     // return ans;

//     // if(n == 0)
//     //     return 1;
//     // if(n == 1)
//     //     return x; 
//     // if(n == -1)
//     //     return 1/x;
//     // double halfPower = myPow(x,n/2);
//     // double result = halfPower * halfPower;

//     // if(n%2 != 0)
//     // {
//     //     if(n > 0)
//     //         result = result * x;
//     //     else
//     //         result = result / x;
//     // }
//     // return result;
//     // }   

// //     double myPow(double x, int n)
// // {
// //     int power = abs(n);
// //     if(n==0){
// //         return 1;
// //     }
// //     double ans = 1;
// //     for(int i=0; i<power; i++){
// //         ans = ans*x;
// //     }
// //     if(n<0){
// //         return (1/ans);
// //     }
// //     return ans;
// // } 

//         if (n<0){
//             n=-n;
//             x=1/x;
//         }
//         double ans = 1;

//         while(n > 0){
//             if(n % 2 == 1){
//                 ans =ans* x;
//             }
//             x=x*x;
//             n=n/2;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    double myPow(double x, long long n) {    if (n<0){
            n=-n;
            x=1/x;
        }
        double ans = 1;
        while(n > 0){
            if(n % 2 == 1){
                ans =ans* x;
            }
            x=x*x;
            n=n/2;
        }
        return ans;
    }
};