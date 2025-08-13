class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int start_row = x , start_col = y ;
        int end_row = x+k-1 , end_col = y+k -1;
        
        while(start_row < end_row){
            for(int i = start_col ; i<=end_col ; i++){
                swap(grid[start_row][i] , grid[end_row][i]);
            }
            start_row++;
            end_row--;
        }
    return grid;  
    }
};