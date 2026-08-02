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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=1;
        queue<pair<TreeNode*,long long>>q;
        if(root==NULL)return ans;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long maxi=0,mini=INT_MAX;
            for(int i=0; i<size; i++){
                auto [node,level]=q.front();
                maxi=max(level,maxi);
                mini=min(mini,level);
                q.pop();
                level-=mini;
                if(node->left)q.push({node->left,2*(level)+1});
                if(node->right)q.push({node->right,2*(level)+2});

            }
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
};