class Solution {
public:
// vector<int> getSneakyNumbers(vector<int>& nums) {
//     map<int, int> mp;
//     vector<int> ans;

//     for (int i = 0; i < nums.size(); i++) {
//         mp[nums[i]]++;
//         if (mp[nums[i]] == 2) { // appears the second time
//             ans.push_back(nums[i]);
//         }
//     }

//     return ans;
// }
    vector<int>getSneakyNumbers(vector<int>&nums){
        int n = nums.size() -2;
        int sum =0; 
        int sqSum =0;

        for(int i :nums){
            sum+= i;
            sqSum += i*i;
        }
        //x + y = a
        // x^2 + y^2 =b;

        int a = sum -(n * (n-1))/2;
        int b = sqSum - ((n-1) * (n) * (2*n -1))/6;

        //xy = (a^2 -b)/2;
        int c = (a*a -b)/2;

        //t^2 -at +c =0;

        int x =(a + sqrt(a*a - 4*c))/2;
        int y =(a - sqrt(a*a - 4*c))/2;

        return {x , y};

    }

};