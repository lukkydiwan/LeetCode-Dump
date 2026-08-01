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
    bool ans(TreeNode *left, TreeNode* right){
        if(left==NULL || right==NULL)return left==right;
        if(left->val!=right->val)return false;
        int l=ans(left->left,right->right);
        int r=ans(left->right,right->left);
        return l&&r;

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return ans(root->left,root->right);
    }
};