class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i =0; i< gifts.size(); i++){
            pq.push(gifts[i]);
        }
        while(k--){
          int topElement = pq.top();
          pq.pop();
          pq.push(sqrt(topElement));  
        }
        long long sum=0;
        for(int i =0;i<gifts.size();i++){
            sum += pq.top();
            pq.pop();
        }
        return sum;
        
    }
};