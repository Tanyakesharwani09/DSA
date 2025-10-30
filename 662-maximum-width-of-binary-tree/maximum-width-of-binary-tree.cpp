/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(!root){
//             return 0;
//         }
//         int ans =0;
//         queue<pair<TreeNode* , int>> q;
//         q.push({root , 0});

//         while(!q.empty()){
//             int size = q.size();
//             int mmin = q.front().second;
//             int first , last;

//             for(int i =0; i<size; i++){
//                 int cur_id = q.front().second - mmin;
//                 TreeNode* root = q.front().first;
//                 q.pop();

//                 if(i==0){
//                     first = cur_id;
//                 }
//                 if(i == size -1){
//                     last = cur_id;
//                 }
//                 if(root->left){
//                     q.push({root->left ,  2 * cur_id + 1});
//                 }
//                 if(root->right){
//                     q.push({root->right ,  2 * cur_id + 2});
//                 }
//             }
//             ans = max(ans , last - first + 1);

//         }
//         return ans;
//     }
// };

						// \U0001f609\U0001f609\U0001f609\U0001f609Please upvote if it helps \U0001f609\U0001f609\U0001f609\U0001f609
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        long long res = 1;
        queue<pair<TreeNode*, long long>> q;
        
        // I am using intialising list
        q.push({root, 0});      // also can use make_pair
        
        while(!q.empty())
        {
            long long cnt = q.size();
            // start is the index of root node for first level
            long long start = q.front().second;
            long long end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                // we will use it while inserting it children
                // left child will be 2 * idx + 1;
                // right chils will be 2 * idx + 2;
                long long idx = p.second - start;
                
                q.pop();
                
                // if  left child exist
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                // if right child exist
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return res;
        
    }
};