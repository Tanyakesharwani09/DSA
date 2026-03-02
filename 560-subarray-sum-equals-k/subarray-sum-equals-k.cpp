class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int cnt=0;
    //     for(int i=0; i<nums.size(); i++){
    //         int sum=0;
    //         for(int j = i; j<nums.size() ; j++){
    //             sum += nums[j];
    //             if(sum == k){
    //             cnt++;
    //             }
    //         }
            
    //     }
    //     return cnt;
    // }

    int subarraySum(vector<int>& nums, int k){
        int n = nums.size();
        int preSum =0, cnt=0;
        unordered_map<int , int>mp;
        mp[0] =1;
        for(int i=0; i<n ; i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mp[remove];
            mp[preSum] += 1;
        }
        return cnt;
    }
};