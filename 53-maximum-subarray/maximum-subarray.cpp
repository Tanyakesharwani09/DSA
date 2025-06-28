class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int maxi = INT_MIN;
        int ansStart ;
        int ansEnd;
        int start;

        for(int i=0; i<n ; i++){
            if(sum==0){
                start =i;
            }
            sum = sum + nums[i];
            
            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum<0){
                sum =0;
            }
        }
        return maxi;
        
    }
};