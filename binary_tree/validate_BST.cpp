// link : https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        if(root ==nullptr)return true;
        // check -> f(root->left) && f(root->right)
        //we'll simply check if the left node is lesser than curr root
        // right node is greater than current root
        return helper(root,NULL,NULL);
    }
    bool helper(TreeNode* root, TreeNode *leftBound, TreeNode *rightbound){
        if(root ==nullptr)return true;
        if((leftBound && leftBound->val >= root->val) || (rightbound && rightbound->val <= root->val))return false;
        //first do call for left child
        //second call for right child
        return helper(root->left,leftBound,root) && helper(root->right,root,rightbound);
    }
};