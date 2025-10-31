class Solution {
public:
vector<int> getSneakyNumbers(vector<int>& nums) {
    map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
        if (mp[nums[i]] == 2) { // appears the second time
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

};