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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,
                     int &postEnd,
                     int inStart, int inEnd,
                     unordered_map<int, int>& rec) {
        if (postEnd < 0 || inStart > inEnd) return nullptr;

        int val = postorder[postEnd];
        postEnd--;
        TreeNode* root = new TreeNode(val);
        int position = rec[val];

        root->right = helper(postorder, inorder , postEnd , position + 1 , inEnd, rec);

        root->left = helper(postorder, inorder , postEnd , inStart , position-1 , rec);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> rec;
        for (int i = 0; i < inorder.size(); i++) {
            rec[inorder[i]] = i;
        }
        int size = inorder.size() -1;
        return helper(postorder, inorder ,size, 0, size, rec);
    }

};