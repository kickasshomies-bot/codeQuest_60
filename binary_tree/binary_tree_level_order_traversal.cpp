// link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //what are the requirements???
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int popLimit = q.size();
            vector<int>temp;
            for(int i=0;i<popLimit;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left != nullptr)q.push(front->left);
                if(front->right != nullptr)q.push(front->right);
                temp.push_back(front->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

