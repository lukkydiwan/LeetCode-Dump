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
    int ans(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int l=ans(root->left);
        int r=ans(root->right);
        if(l==-1 || r==-1)return -1;
        if(abs(r-l)>1)return -1;
        return max(l,r)+1;

    }
    bool isBalanced(TreeNode* root) {
        if(ans(root)==-1)return false;
        return true;
    }
};