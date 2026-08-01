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
    bool hai(TreeNode* root, TreeNode* p){
        if(root==NULL)return false;
        if(root==p)return true;
        return hai(root->left,p) || hai(root->right,p);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(p==root){
            if(q==root)return root;
            if(hai(root,q))return root;
        }
        if(q==root){
            if(p==root)return root;
            if(hai(root,q))return root;
        }
        if((hai(root->left,p) && hai(root->right,q)) || (hai(root->left,q) && hai(root->right,p))){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        if(left)return left; 
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(right)return right;
        return NULL;
        
    }
};