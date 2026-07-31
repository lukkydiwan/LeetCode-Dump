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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode* >q;
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> l;
            int size=q.size();         
            for(int i=0; i<size; i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                l.push_back(node->val);
            }
            if(ans.size()%2==0){
                ans.push_back(l);
            }else{
                reverse(l.begin(),l.end());
                ans.push_back(l);
            }


        }
        return ans;
    }
};