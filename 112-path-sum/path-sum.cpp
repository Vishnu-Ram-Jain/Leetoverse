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
    bool f(TreeNode* root, int tar){
        if(root->left==NULL && root->right==NULL)return root->val==tar;

        tar -= root->val;
        bool left = 0, right = 0;
        if(root->left!=NULL)left = f(root->left,tar);
        if(root->right!=NULL)right = f(root->right,tar);
        tar += root->val;

        return left or right;
    }
    bool hasPathSum(TreeNode* root, int tar) {
        if(root==NULL)return false;
        return f(root, tar);
    }
};