class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev =0; 
        int time=0;

        for(int i =1; i<colors.size(); i++){
            if(colors[i] == colors[prev]){
                if(neededTime[prev] <neededTime[i]){
                    time += neededTime[prev];
                    prev = i;
                }
                else{
                    time += neededTime[i];
                }
            }
            else{
                prev =i;
            }
        }
        return time;
        
    }
};