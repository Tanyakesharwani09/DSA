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
   int findKthSmallest(TreeNode* root, int &k) {
    if (root == NULL) {
        return -1;
    }

    // Search in the left subtree
    int leftAns = findKthSmallest(root->left, k);
    if (leftAns != -1) {
        return leftAns;
    }

    // Visit current node
    k--;
    if (k == 0) {
        return root->val;
    }

    // Search in the right subtree
    return findKthSmallest(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    return findKthSmallest(root, k);
}

};