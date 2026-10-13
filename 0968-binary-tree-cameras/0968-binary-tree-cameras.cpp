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
    void findP(TreeNode* root, map<TreeNode* , TreeNode*> &parent){
        if(root==NULL)return ;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        parent[left]=root;
        parent[right]=root;
        findP(root->left,parent);
        findP(root->right,parent);
    }
    void ans(TreeNode* root, map<TreeNode*, TreeNode*> &parent, map<TreeNode*, bool> &cam, int &c){
        if(root==NULL)return;
        ans(root->left,parent,cam,c);
        ans(root->right,parent,cam,c);
        if(!cam[root] && !cam[parent[root]] && !cam[root->left] && !cam[root->right]){
            c++;
            cam[parent[root]]=true;
        }
    }
    int minCameraCover(TreeNode* root) {
        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,bool> cam;
        findP(root,parent);
        int c=0;
        ans(root,parent,cam,c);
        return c;   
    }
};