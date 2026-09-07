// link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *iter = root;
        if(p->val < iter->val && q->val < iter->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(p->val > iter->val && q->val > iter->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        //which kind of scenarios will reach here?
        return root;
    }
};