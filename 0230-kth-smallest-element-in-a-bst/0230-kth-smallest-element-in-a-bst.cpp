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
    int a(TreeNode* root, int k,vector<int> &v){
        if(root==NULL) return -1;
        int l=a(root->left,k,v);
        if(l!=-1)return l;
        v.push_back(root->val);
        if(v.size()==k)return v.back();
        int r=a(root->right,k,v);
        if(r!=-1)return r;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        return a(root,k,v);
    }
};