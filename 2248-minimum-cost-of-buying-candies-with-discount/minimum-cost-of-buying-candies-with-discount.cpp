class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int minCost =0;
        for(int i = cost.size() -1; i>=0;){
            minCost += cost[i];
            if(i>=1)
                minCost += cost[i-1];

            i = i-3;
            
        }
        return minCost;
        
    }
};