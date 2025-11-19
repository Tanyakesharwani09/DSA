class Solution {
public:
    class Info{
        public:
        int data;
        int rowIndex;
        int colIndex;
        Info(int a , int b , int c){
            this->data = a;
            this->rowIndex  = b;
            this->colIndex = c;
        }
    };

    class compare{
        public:
        bool operator()(Info*a , Info*b){
            return (a->data > b->data);
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info* , vector<Info*>, compare>pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int row=0; row< nums.size(); row++){
            Info* temp = new Info(nums[row][0], row , 0);
            pq.push(temp);

            maxi = max(maxi , nums[row][0]);
            mini  = min(mini , nums[row][0]);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()){
            Info * topNode = pq.top();
            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;

            pq.pop();

            mini = topData;

            if((maxi - mini) < (ansEnd - ansStart)){
                ansStart = mini;
                ansEnd = maxi;
            }

            //insertion
            if((topCol + 1) < nums[topRow].size()){
                Info * newElement = new Info(nums[topRow][topCol + 1], topRow , topCol +1);
                maxi = max(maxi ,nums[topRow][topCol + 1]);
                pq.push(newElement);
            }
            else{
                break;
            }
        }
        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};