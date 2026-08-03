/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL)ans+="#,";
            else{
                q.push(node->left);
                q.push(node->right);
                ans+=to_string(node->val)+',';
            }
        }
        return ans;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size()==0)return NULL;
        if(data=="#,")return NULL;
        queue<TreeNode*> q;
        string temp;
        vector<string> token;
        for(auto x:data){
            if(x==','){
                token.push_back(temp);
                temp="";
            }else{
                temp+=x;
            }
        }
        TreeNode* root=new TreeNode(stoi(token[0]));
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(token[i]=="#"){
                node->left=NULL;
                i++;
            }else{
                TreeNode* leftNode=new TreeNode(stoi(token[i]));
                node->left=leftNode;
                i++;
                q.push(leftNode);
            }
            if(token[i]=="#"){
                node->right=NULL;
                i++;
            }else{
                TreeNode* rightNode=new TreeNode(stoi(token[i]));
                node->right=rightNode;
                i++;
                q.push(rightNode);
            }
            

        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));