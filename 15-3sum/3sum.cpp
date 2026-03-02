//class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>ans;
//         vector<vector<int>> output;
//         sort(nums.begin(), nums.end());
        
//         for(int i =0; i<nums.size()-2; i++){
//             for(int j=i+1; j<nums.size()-1; j++){
//                 for(int k=j+1; k<nums.size(); k++){
                    
//                     if((nums[i] + nums[j] + nums[k]==0)&& i != j && k!=j && j != k){
//                         ans.insert({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
//         for(auto it : ans){
//             output.push_back(it);
//         }
//         return output;

//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) 
//     {
        //BRUTE FORCE (USING 3 LOOP):
        // set<vector<int>>st;
        // int n = nums.size();
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=i+1;j<n;j++)
        //     {
        //         for (int k=j+1;k<n;k++)
        //         {
        //             if (nums[i] + nums[j] + nums[k] == 0)
        //             {
        //                 vector<int>v = {nums[i], nums[j] , nums[k]};
        //                 sort(v.begin(),v.end());
        //                 st.insert(v);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans{st.begin() , st.end()};
        // return ans;
//         set<vector<int>>st;
//         int n = nums.size();
//         for (int i=0;i<n;i++)
//         {
//             set<int>s;
//             for (int j=i+1;j<n;j++)
//             {
//                 int req = -(nums[i] + nums[j]);
//                 if (s.find(req) != s.end())
//                 {
//                     vector<int>v = {nums[i], nums[j] , req};
//                     sort(v.begin(),v.end());
//                     st.insert(v);
//                 }
//                 s.insert(nums[j]);
//             }
//         }
//         vector<vector<int>>ans{st.begin() , st.end()};
//         return ans;
//     }
// };   

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        

    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    int sum= 0;
    for(int i = 0;i< nums.size();i++){
         if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
        
       int left = i+1;
       int right = n -1;
        while(left < right){
        sum = nums[i] + nums[left] + nums[right];
             if(sum < 0){
                left++;
            }
            else if(sum >0) {
                right--;
            }else {
            
                result.push_back({nums[i],nums[left],nums[right]});
                 
               
                left++;
                right--;
                while (nums[left] == nums[left-1] && left < right) {
                        left++;
                }
                while(nums[right] == nums[right +1] && left <right){
                    right--;
                }
            }
           
        }
    }
    return result;
}


};