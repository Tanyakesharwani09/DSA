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
class Solution {
public:

    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int>ans;
    //     if(root ==NULL){
    //         return ans;
    //     }
    //     queue<TreeNode*>q;
    //     q.push(root);

    //     while(!q.empty()){
    //         int size = q.size();
    //         for(int i =0; i<size ; i++){
    //             TreeNode*front = q.front();
    //             q.pop();

    //             if(i == size-1){
    //                 ans.push_back(front->val);
    //             }
    //             if(front->left){
    //                 q.push(root->left);
    //             }
    //             if(front->right){
    //                 q.push(root->right);
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> result;
    //     if (!root) return result;

    //     queue<TreeNode*> q;
    //     q.push(root);

    //     while (!q.empty()) {
    //         int levelSize = q.size();
    //         for (int i = 0; i < levelSize; ++i) {
    //             TreeNode* node = q.front();
    //             q.pop();

    //             if (i == levelSize - 1) result.push_back(node->val);
    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);
    //         }
    //     }

    //     return result;
    // }

    void rightView(TreeNode* root, int level , vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        rightView(root->right , level + 1, ans);
        rightView(root->left , level + 1, ans);

    }

    vector<int>rightSideView(TreeNode* root){
        vector<int>ans;
        rightView(root , 0 , ans);
        return ans ;
    }
};

















