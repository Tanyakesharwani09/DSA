class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // for(int i=0; i<nums.size() -1 ; i++){
        //     if(nums[i] == 0){
        //         int j =i;
        //         while(j<nums.size()){
        //             nums[j] = nums[i+1];
        //             nums[j+1] =0;
        //             j++;
        //         }
        //     }
        // }

        for(int i=0; i<nums.size() -1 ; i++){
            if(nums[i] == 0){
                for(int j = i+1; j <nums.size(); j++){
                    if(nums[j] !=0){
                        swap(nums[i] , nums[j]);
                        break;
                    }
                }
            }
        }
    }
};