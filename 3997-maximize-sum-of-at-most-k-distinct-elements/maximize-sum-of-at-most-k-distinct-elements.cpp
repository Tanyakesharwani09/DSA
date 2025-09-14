class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.rbegin() , nums.rend());
        int i =1;
        ans.push_back(nums[0]);
        k--;

        while(k>0 && i<n){
            if(nums[i] != nums[i-1]){
                ans.push_back(nums[i]);
                k--;
            }
            i++;
        }
        return ans ;
    }
};