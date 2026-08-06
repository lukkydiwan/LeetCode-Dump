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
    bool ans(TreeNode* root, long maxi, long mini){
        if(root==NULL)return true;
        if(root->val>=maxi || root->val<=mini) return false;
        return ans(root->left,root->val,mini) && ans(root->right,maxi,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return ans(root,LONG_MAX,LONG_MIN);
    }
};