class Solution {
public:
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     map<int,int>mpp;
    //     vector<int>ans;

    //     for(int i =0; i<n ; i++){
    //         mpp[nums[i]]++;
    //     }
    //     for(auto it: mpp){
    //         if(it.second > n/3){
    //             ans.push_back(it.first);
    //         }
    //     }
    //     return ans;
        
    // }

    //  vector<int> majorityElement(vector<int>& nums){

    //  }
//     vector<int> majorityElement(vector<int> v) {
//     int n = v.size(); //size of the array
//     vector<int> ls; // list of answers

//     for (int i = 0; i < n; i++) {
//         //selected element is v[i]:
//         // Checking if v[i] is not already
//         // a part of the answer:
//         if (ls.size() == 0 || ls[0] != v[i]) {
//             int cnt = 0;
//             for (int j = 0; j < n; j++) {
//                 // counting the frequency of v[i]
//                 if (v[j] == v[i]) {
//                     cnt++;
//                 }
//             }

//             // check if frquency is greater than n/3:
//             if (cnt > (n / 3))
//                 ls.push_back(v[i]);
//         }

//         if (ls.size() == 2) break;
//     }

//     return ls;
// }

    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;

        for(int i =0; i<n; i++){
            if(cnt1==0 && el2 != nums[i]){
                cnt1 =1;
                el1 = nums[i];
            }

            else if(cnt2 ==0 && el1 != nums[i]){
                cnt2=1;
                el2 =nums[i];
            }
            else if( el1 == nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else{
                cnt1-- , cnt2--;
            }

        }
        vector<int>ls;
        cnt1=0,cnt2=0;
        int mini = int(n/3) +1;
        for(int i=0 ; i< n ; i++){
            if (el1 == nums[i]) cnt1++;
            if(el2 == nums[i] ) cnt2++;
        }
         if(cnt1 >= mini) ls.push_back(el1);
            if(cnt2 >= mini) ls.push_back(el2);
        return ls;
    }

};