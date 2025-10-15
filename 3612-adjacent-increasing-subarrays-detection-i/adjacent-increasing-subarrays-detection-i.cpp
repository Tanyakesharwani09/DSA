class Solution {
public:
    bool isIncreasing(int k , int s , int e, vector<int>&nums){
        for(int i=s +1 ; i<e; i++){
            if(nums[i] <= nums[i - 1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int start=0; start + 2*k <= n; start++){
            bool first = isIncreasing(k , start , start + k, nums);
            bool second = isIncreasing(k, start + k, start + 2*k, nums);

            if(first && second){
                return true;
            }
        }
        return false;
    }
};