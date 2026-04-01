class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start =0 , end = n-1;
        int mid;
        int ans1 = -1 ;
        int ans2 = -1;
        while(start <= end){
            mid = start + (end - start)/2;
            if(target == nums[mid]){
                ans1 = mid;
                end = mid -1;
            }
            else if(target < nums[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        start=0, end = n-1;
        while(start <= end){
            mid = start + (end - start)/2;
            if(target == nums[mid]){
                ans2 = mid;
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return {ans1 , ans2};
    }
};