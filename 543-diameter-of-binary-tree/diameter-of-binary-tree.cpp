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
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int height = max(leftHeight , rightHeight) +1;
        return  height;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = maxDepth(root->left) + maxDepth(root->right);

        int ans = max(option3 , max(option1 , option2));
        return ans;
    }
};