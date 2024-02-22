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
    TreeNode* f(TreeNode*root, TreeNode*p, TreeNode*q){
        if(root==NULL or root==p or root==q)return root;

        TreeNode* left = f(root->left,p,q);
        TreeNode* right = f(root->right,p,q);

        if(left==NULL)return right;
        else if(right==NULL)return left;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};