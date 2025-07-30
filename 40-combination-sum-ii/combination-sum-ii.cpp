class Solution {
public:
    void combinationSum_helper(vector<int>& candidates ,int target,  vector<vector<int>>&ans,   vector<int>&output, int index ){
        if(target ==0){
            ans.push_back(output);
            return ;
        }
        if(target <0){
            return;
        }

        for(int i=index ; i<candidates.size() ; i++){
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }
            output.push_back(candidates[i]);
            combinationSum_helper(candidates , target-candidates[i], ans , output ,i+1);
            output.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        combinationSum_helper(candidates , target , ans , output ,0);
        return ans;
        
    }
};