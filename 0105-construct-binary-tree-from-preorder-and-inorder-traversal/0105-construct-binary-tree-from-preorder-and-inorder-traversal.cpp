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
    TreeNode* build(int i, int j, int st,vector<int> & preorder, vector<int> &inorder, unordered_map<int,int> &m){
        if(i>j)return NULL;
        TreeNode* root=new TreeNode(preorder[st]);
        int idx=m[preorder[st]];
        int size=m[preorder[st]]-i;
        root->left=build(i,m[preorder[st]]-1,st+1,preorder,inorder,m);
        root->right=build(idx+1,j,st+size+1,preorder,inorder,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        unordered_map<int,int> m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=build(0, preorder.size()-1,0, preorder,inorder,m);
        return root;
    }
};