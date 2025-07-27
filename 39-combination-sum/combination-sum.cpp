class Solution {
public:
    void combinationSum_Helper(vector<int>&candidates, int target , vector<int>&output , vector<vector<int>>&ans , int index ){
        //base case
        if(target ==0){
            ans.push_back(output);
            return;
        }
        if(target <0){
            return;
        }
        //1 case solve
        for(int i =index ; i< candidates.size() ; i++){
            output.push_back(candidates[i]);
            combinationSum_Helper(candidates , target - candidates[i] , output , ans , i);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        combinationSum_Helper(candidates , target , output , ans , 0);
        return ans;
    }
};