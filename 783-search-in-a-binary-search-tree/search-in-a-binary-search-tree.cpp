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
    TreeNode* f(TreeNode* root, int val){
        if(root==NULL)return NULL;
        if(root->val==val)return root;
        TreeNode* node = NULL;
        if(root->val > val){
            node = f(root->left,val);
        }
        else{
            node = f(root->right,val);
        }
        return node;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return f(root,val);
    }
};