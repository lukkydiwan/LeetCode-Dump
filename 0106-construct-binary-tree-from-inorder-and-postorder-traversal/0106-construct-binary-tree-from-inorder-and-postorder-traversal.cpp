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
    TreeNode * build(int st, int end,int curr,vector<int> &inorder, vector<int> &postorder, unordered_map<int,int> &m){
        if(st>end)return NULL;
        TreeNode* node=new TreeNode(postorder[curr]);
        int idx=m[postorder[curr]];
        int size=end-idx;
        node->right=build(idx+1,end,curr-1,inorder,postorder,m);
        node->left=build(st,idx-1,curr-size-1,inorder,postorder,m);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return NULL;
        unordered_map<int,int> m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=build(0,inorder.size()-1,inorder.size()-1,inorder,postorder,m);
        return root;
    }
};