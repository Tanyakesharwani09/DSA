class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for(int i =0; i<strs[0].size(); i++){
            for(int j=0; j<strs.size() -1; j++){
                if(strs[j][i] > strs[j+1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs) {
//         const int n=strs.size(), m=strs[0].size();
//         int cnt=0;
//         for(int j=0; j<m; j++){
//             for (int i=0; i<n-1; i++){
//                 if(strs[i][j]>strs[i+1][j]){
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };