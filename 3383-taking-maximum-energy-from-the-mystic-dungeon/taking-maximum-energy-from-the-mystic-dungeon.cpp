class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
     int n=energy.size();
     vector<int>ans(n);
     
     int maxi=INT_MIN;
     for(int i=n-1;i>=0;i--){
        if(i+k<n){
            ans[i]=ans[i+k]+energy[i];
        }
        else{
            ans[i]=energy[i];
        }

        maxi=max(maxi,ans[i]);
     }

     return maxi;   
    }
};