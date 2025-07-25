class Solution {
public:
    void print(int i , vector<int>&nums, vector<int>&output,  vector<vector<int>>&ans ){
        if( i == nums.size()){
            ans.push_back(output);
            return;
        }
        output.push_back(nums[i]);
        print(i+1 , nums , output , ans);

        output.pop_back();
        print(i+1 , nums , output , ans);


    }
   
    vector<vector<int>>subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>output;
        print(0 , nums ,output , ans);
        return ans;
       
    }
};