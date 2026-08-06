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
    TreeNode* build(int st, int end, vector<int> &preorder){
        if(st>end)return NULL;
        TreeNode* node= new TreeNode(preorder[st]);
        int i=st+1;
        while(i<preorder.size() && preorder[i]<preorder[st]){
            i++;
        }
        node->left=build(st+1,i-1,preorder);
        node->right= build(i,end,preorder);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode* root=new TreeNode(preorder[0]);
        return build(0,preorder.size()-1,preorder);
    }
};