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
    void a(TreeNode* root, int i, vector<int> &ans){
        if(root==NULL)return;
        if(ans.size()==i)ans.push_back(root->val);
        a(root->right,i+1,ans);
        a(root->left,i+1,ans);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        a(root,0,ans);
        return ans;
    }
};