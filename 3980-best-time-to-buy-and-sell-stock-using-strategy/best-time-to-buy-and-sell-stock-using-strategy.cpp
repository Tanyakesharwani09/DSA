class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k){
        int n = prices.size();
        vector<ll>profit(n);
        ll actualProfit =0;

        for(int i = 0; i<n ; i++){
            profit[i] = prices[i]*strategy[i];
            actualProfit += profit[i];
        }

        ll originalWindProfit =0;
        ll modifiedWindProfit = 0;
        ll maxGain =0;  //modifiedWindProfit - originalWindProfit

        int i =0, j=0;
        while(j<n){
            originalWindProfit += profit[j];

            if(j - i +1 > k/2){
                modifiedWindProfit += prices[j];
            }

            if(j - i + 1 > k){
                originalWindProfit -= profit[i];
                modifiedWindProfit -= prices[i + k/2];
                i++;
            }

           if(j-i+1 == k){
             maxGain = max(maxGain , modifiedWindProfit - originalWindProfit);
           }
            j++;
        }
        return actualProfit + maxGain;

    }

    // long long solve(vector<int>& prices, vector<int>& strategy, int k){

    //     long long sum = 0;
    //     for(int i =0 ; i< prices.size() ; i++){
    //         sum += prices[i]*strategy[i];
    //     }
    //     return sum;

    // }

    // long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

    //     long long ans = 0;
    //     for(int i =0 ; i< prices.size() ; i++){
    //         ans += prices[i]*strategy[i];
    //     }
        
    //     for(int i =0; i<= prices.size() - k ; i++){
    //         vector<int> temp = strategy;
    //         for(int j =i; j<k+i ; j++){
    //             if(j-i < k/2){
    //                 temp[j] = 0;
    //             }
    //             else{
    //                 temp[j] =1;
    //             }
    //         }
    //         ans = max(ans,solve(prices, temp , k));
    //     }
    //     return ans;
    // }
};