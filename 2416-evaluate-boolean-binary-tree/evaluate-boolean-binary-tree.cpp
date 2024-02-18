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
    bool f(TreeNode* root){
        if(root->left==NULL and root->right==NULL)return root->val==1;

        bool left = f(root->left);
        bool right = f(root->right);
        // OR;
        if(root->val==2)return left or right;
        // AND;
        if(root->val==3)return left && right;

        return false;
    }
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};