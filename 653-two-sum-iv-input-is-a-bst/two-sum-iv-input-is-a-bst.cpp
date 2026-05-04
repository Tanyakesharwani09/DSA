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
    // bool findTarget(TreeNode* root, int k) {
        
    // }

    void inorderTraverse(TreeNode* root, vector<int>&inorder){	
	if(root == NULL){
		return;
    }
    inorderTraverse(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraverse(root->right , inorder);

    }

    bool findTarget(TreeNode*root, int k ){
	    if(root == NULL){
		    return false; 
        }
        if(root ->left == NULL && root->right == NULL){
	        return false;
        }
        vector<int>inorder;   // [2 , 3,4 , 5, 6 ,7]    k=10
        inorderTraverse(root, inorder);

        int left =0;
        int right = inorder.size() - 1;  //5

        while(left < right){

	        if (( inorder[left] + inorder[right]) == k){
		        return true;
            }    

            else if(( inorder[left] + inorder[right]) < k){    //k =10
                left++;
            }
            else{
	            right-- ;
            }
        }
        return false;

    }
};