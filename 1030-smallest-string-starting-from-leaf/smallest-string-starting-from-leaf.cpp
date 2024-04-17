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
    string res;
    void f(TreeNode *root, string op){
        if(root->left==NULL && root->right==NULL){
            op += (root->val + 'a');
            reverse(op.begin(),op.end());
            // mp[op] = 1;
            if(res.size()==0)res = op;
            res = min(res,op);
            return ;
        }

        op += (root->val + 'a');
        if(root->left != NULL)f(root->left,op);
        if(root->right != NULL)f(root->right,op);
    }
    string smallestFromLeaf(TreeNode* root) {
        string op = "";
        f(root,op);
        return res;
    }
};