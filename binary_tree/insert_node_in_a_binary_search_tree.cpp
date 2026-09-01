// link : https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/2126363157/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //always start from root
        if(root==nullptr){
            TreeNode *tempRoot = new TreeNode(val);
            return tempRoot;
        }
        TreeNode *iter = root;
        while(iter){
            // check going left property
            // It is guaranteed that the new value does not exist in
            //the original BST.
            //because of this property you don't need to check
            //for equal values
            if(val < iter->val ){
                if(iter->left == nullptr){
                    TreeNode *temp = new TreeNode(val);
                    iter->left = temp;
                    return root;
                }
                else{
                    iter = iter->left;
                }
            }
            else{
                if(iter->right == nullptr){
                    TreeNode *temp = new TreeNode(val);
                    iter->right = temp;
                    return root;
                }
                else{
                    iter = iter->right;
                }
            }
        }
        return root;
    }
};