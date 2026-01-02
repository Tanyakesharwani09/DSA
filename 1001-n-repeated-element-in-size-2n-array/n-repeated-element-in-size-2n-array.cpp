class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i =0; i<nums.size(); i++){
            int element = nums[i];
            if(mp[element] > 0){
                return element;
            }
            mp[element]++;
        }
        return 0;
        
    }
};