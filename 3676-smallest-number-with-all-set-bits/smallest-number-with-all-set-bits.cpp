class Solution {
public:
    int smallestNumber(int n) {
        int pow =0;
        while(true){
            if(((1<<pow) - 1) >=n ) return ((1<<pow) - 1);
            pow++;
        }
    }
};