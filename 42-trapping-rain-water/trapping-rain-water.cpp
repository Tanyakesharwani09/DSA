class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        int l =0 , r = n-1;
        int lmax=0, rmax=0;

        while(l <r){
            lmax = max(lmax , height[l]);
            rmax = max(rmax , height[r]);

            if(lmax < rmax){
                waterTrapped += lmax - height[l];
                l++;
            }
            else{
                waterTrapped += rmax - height[r];
                r--;
            }
        }
        return waterTrapped;
    }    
};