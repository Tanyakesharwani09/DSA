class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;

        for(int i =0; i<piles.size(); i++){
            pq.push(piles[i]);
        }
        while(k--){
            int topElement = pq.top();
            pq.pop();

            topElement = topElement - topElement/2;
            pq.push(topElement);
        }
        int sum =0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};