// class Solution {
// public:
//     //vector<int>& nums2;
//     int findnums1(int curr){
//         for(int i=0;i<nums2.size();i++){
//             if(curr==nums2[i]){
//                 return i;
//             }
//         }
//         return 0;
//     }
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//       stack<int>s;
//       s.push(-1);
//       vector<int>ans(nums1.size());
//       for(int i =nums1.size(); i>=0; i--){
//         int curr = nums1[i];
//         int newCurr=findnums1(curr);
//         while(s.top()!=-1 && nums2[s.top()] >= newCurr){
//             s.pop();
//         }
//         ans[i]=s.top();
//         s.push(i);
//       }  
//       return ans;
//     }
// };

class Solution {
public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//       stack<int>st;
//       vector<int>v;
//         int j=0;
//       for(int i=nums2.size()-1;i>=j;i--){
//         if(st.size()==0){
//             v.push_back(-1);
//         }
//         else if(st.size()>0 && st.top()>=nums2[i]){
//             v.push_back(st.top());
//         }
//         else if(st.size()>0 && st.top()<=nums2[i]){
//             while(st.size()>0 && st.top()<=nums2[i]){
//                 st.pop();
//             }
//             if(st.size()==0){
//                 v.push_back(-1);
//             }
//             else
//             {
//                 v.push_back(st.top());
//             }
//         }
//         st.push(nums2[i]);
//     }
//     reverse(v.begin(),v.end());
//     vector<int>ans;
//     for(int i=0;i<nums1.size();i++){
//         for(int j=0;j<nums2.size();j++){
//             if(nums1[i]==nums2[j]){
//                 ans.push_back(v[j]);
//             }
//         }
//     }
//     return ans;
//     }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nextGreater(nums2.size());
    stack<int> st;
    
    // Build next greater elements for nums2
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        nextGreater[i] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }
    
    // Find results for nums1
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums2[j] == nums1[i]) {
                result.push_back(nextGreater[j]);
                break;
            }
        }
    }
    
    return result;
}
};