class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto x:amount){
            if(x)
            pq.push(x);
        }

        int ans=0;

        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a>1)
                pq.push(a-1);
            if(b>1)
                pq.push(b-1);

            ans++;
        }

        return pq.empty()?ans:ans+pq.top();
    }
};