class Solution {
public:
    // bool isIncreasing(int k , int s , int e, vector<int>&nums){
    //     for(int i=s +1 ; i<e; i++){
    //         if(nums[i] <= nums[i - 1]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     for(int start=0; start + 2*k <= n; start++){
    //         bool first = isIncreasing(k , start , start + k, nums);
    //         bool second = isIncreasing(k, start + k, start + 2*k, nums);

    //         if(first && second){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool hasIncreasingSubarrays(vector<int>&nums, int k){
        int n = nums.size();

        int currRun =1;
        int prevRun = 0;

        for(int i =1; i<n; i++){
            if(nums[i] > nums[i-1]){
                currRun++;
            }
            else{ // increasing order break ho gya yaha par
                prevRun = currRun;
                currRun =1;
            }

            if(currRun >= 2*k){
                // we can accomodate two subarrays in it length >= k
                return true;
            }

            if(min(currRun , prevRun) >= k){
                return true;
            }
        }
        return false;

    }
};