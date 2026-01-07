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
    long long TotalSum =0;
    long long maxproduct =0;
    long long MOD = 1e9 + 7;

    int getTotalSum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root){
            return 0;
        }

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long currSum = root->val + leftSum + rightSum;

        long long product = currSum * (TotalSum - currSum);

        maxproduct = max(maxproduct, product);
        
        return currSum;

    }
    int maxProduct(TreeNode* root) {

        TotalSum = getTotalSum(root);

        dfs(root);

        return maxproduct % MOD;
        
    }
};