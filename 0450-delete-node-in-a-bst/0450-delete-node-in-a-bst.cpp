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
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL)return root->right;
        if(root->right==NULL)return root->left;
        TreeNode*temp=root->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=root->right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(root==NULL)return NULL;
        if(root->val==k)return helper(root);
        TreeNode* temp=root;
        while(root!=NULL){
            if(root->val>k){
                if(root->left!=NULL && root->left->val==k){
                    root->left=helper(root->left);
                }else{
                    root=root->left;
                }
            }else{
                if(root->right!=NULL && root->right->val==k){
                    root->right=helper(root->right);
                }else{
                    root=root->right;
                }
            }

        }
        return temp;
    }
};