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
    int Lsize(TreeNode* root){
        if(root==NULL)return 0;
        return 1+Lsize(root->left);
    }
    int Rsize(TreeNode* root){
        if(root==NULL)return 0;
        return 1+Rsize(root->right);
    }
    void a(TreeNode* root,int i,int j,map<int,map<int,multiset<int>>> &m){
        if(root==NULL){
            return ;
        }
        m[i][j].insert(root->val);
        a(root->left,i-1,j+1,m);
        a(root->right,i+1,j+1,m);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> m;
        a(root,0,0,m);
        for(auto x:m){
            vector<int> temp;
            for(auto y:x.second){
                for(auto z:y.second){
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }
        return ans;


    }
};