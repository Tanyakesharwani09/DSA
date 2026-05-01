class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f =0, n = nums.size();
        int sum =accumulate(nums.begin(), nums.end(), 0);

        for(int i =0; i<n; i++){
            f += i*nums[i];
        }

        int maxi = f;
        for(int i = 1; i<n ; i++){
            f += sum - n* nums[n-i];
            maxi = max(maxi ,f);
        }
        return maxi;


        
    }
};