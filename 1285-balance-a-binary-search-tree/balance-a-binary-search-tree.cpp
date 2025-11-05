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
    void inOrderTraversal(vector<int>&inorder , TreeNode*root){
        if(!root) return ;
        inOrderTraversal(inorder , root->left);
        inorder.push_back(root->val);
        inOrderTraversal(inorder , root->right);
    }

    TreeNode* buildTree(vector<int>&inorder, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (start + end)/2;
        TreeNode*root = new TreeNode(inorder[mid]);
        root->left = buildTree(inorder , start , mid -1);
        root->right = buildTree(inorder , mid+1 , end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
       vector<int>inorder;
       inOrderTraversal(inorder , root);
       return buildTree(inorder , 0  , inorder.size() -1); 
    }
};