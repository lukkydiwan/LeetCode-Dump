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
    void parent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &m){
        if(root==NULL)return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    m[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    m[node->right]=node;
                }
                      
            }
        }
        return;
    }
    void an(TreeNode* root, int k, unordered_map<TreeNode* , TreeNode*>&m,  unordered_map<TreeNode*,bool> &vis, vector<int> &ans){
        if(k==0){
            ans.push_back(root->val);
            return;
        }if(k<0)return;
        vis[root]=true;
        if(root->left && !vis[root->left]){
            an(root->left,k-1,m,vis,ans);
        }
        if(root->right && !vis[root->right]){
            an(root->right,k-1,m,vis,ans);
        }
        if(m[root] && !vis[m[root]]){
            an(m[root],k-1,m,vis,ans);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        unordered_map<TreeNode* , TreeNode*> m;
        vector<int> ans;
        if(root==NULL)return ans;
        parent(root,m);
        unordered_map<TreeNode*,bool> vis;
        vis[t]=true;
        an(t,k,m,vis,ans);
        return ans;
    }
};