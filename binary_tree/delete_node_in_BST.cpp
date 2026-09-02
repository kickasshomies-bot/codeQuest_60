// link : https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode *findLargest(TreeNode* root){
        if(root->right == nullptr)return root;
        return findLargest(root->right);
    }
    TreeNode* helper(TreeNode *root){
        //case 1
        // if 4->left is null simply return right pointer
        if(root->left == nullptr){
            return root->right;
        }
        else if(root->right == nullptr){
            return root->left; //left of 4
        }
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        TreeNode *largestNodeLST = findLargest(l);
        largestNodeLST->right = r;
        return l;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *iter = root;
        if(root==nullptr)return nullptr;
        //case where we want to delete the root
        if(root->val == key){
            return helper(root);
        }
        while(iter){
            if(key < iter->val){
                //check if left node of current node is our
                //target or not
                if(iter->left != nullptr && iter->left->val ==key){
                    iter->left = helper(iter->left);
                    return root;
                }
                else{
                    iter = iter->left;
                }
            }
            else if(key > iter->val){
                //go right
                if(iter->right != nullptr && iter->right->val ==key){
                    iter->right = helper(iter->right);
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