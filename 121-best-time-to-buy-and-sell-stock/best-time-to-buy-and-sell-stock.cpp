class Solution {
public:
    // int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // int mini =prices[0];
        // int start =0;
        // for(int i=1; i<n; i++){
        //     if(mini > prices[i]){
        //         mini=prices[i];
        //         start =i;
        //     }
        // }
        // int ans;
        // int maxi = mini;
        // for(int i= start +1 ; i<n; i++){
        //     if(maxi < prices[i]){
        //         maxi = prices[i];
        //         ans = i;    
        //     }
        // }
        // if(maxi == mini){
        //     return 0;
        // }
        // return maxi-mini;
        // int left =0;
        // int right =n;
        // while(left < right){
        //     int diff = prices[right] - prices[left];
        // }

        //perfect code
        // int n = prices.size();
        // int mini= prices[0];
        // int maxprofit =0;

        // for(int i=1; i<n; i++){
        //     int cost = prices[i]- mini;
        //     maxprofit = max(maxprofit , cost);
        //     mini = min(mini , prices[i]);
        // }
        // return maxprofit;
    //}

    void maxProfitFinder(vector<int>&prices , int i, int&minPrice, int&maxProfit){

        //bc
        if(i==prices.size() ) return;

        //ek case solve
        if(prices[i] < minPrice) minPrice = prices[i];
        int todayProfit = prices[i] - minPrice;
        if(todayProfit > maxProfit) maxProfit = todayProfit;

        maxProfitFinder(prices , i+1, minPrice , maxProfit);
    }

    int maxProfit(vector<int>& prices){
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        maxProfitFinder(prices , 0 , minPrice , maxProfit);
        return maxProfit;

    }
};    