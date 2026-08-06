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
    TreeNode* ans(TreeNode* root, TreeNode* maxi, TreeNode* mini){
        if(root==NULL)return NULL;
        if(root->val==maxi->val)return maxi;
        if(root->val==mini->val)return mini;
        if(root->val>mini->val && root->val<maxi->val)return root;
        else if(root->val>maxi->val){
            return ans(root->left,maxi,mini);
        }else return ans(root->right,maxi,mini);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *maxi = (p->val > q->val) ? p : q;
        TreeNode *mini = (p->val < q->val) ? p : q;
        return ans(root,maxi,mini);
    }
};