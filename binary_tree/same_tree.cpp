// problem link
// https://leetcode.com/problems/same-tree/

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
    bool isSame = true; // by default we assume both trees are same
    void helper(TreeNode* p, TreeNode* q){
        
        //if node is leaf node
        if(p==nullptr && q==nullptr)return;
        
        //this one handles if two of the nodes are valid 
        //or not 
        //we are certain that both nodes are valid
        if((p==nullptr && q) || (p && q==nullptr)||(p->val != q->val)){
            isSame = false;
            return;
        }
        helper(p->left,q->left);
        helper(p->right,q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        helper(p,q);
        return isSame;
    }
};