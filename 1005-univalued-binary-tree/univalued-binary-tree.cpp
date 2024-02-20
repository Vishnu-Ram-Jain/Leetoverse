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
    bool f(TreeNode* root, int ele){
        if(root==NULL)return true;
        if(root->val != ele)return false;

        bool left = f(root->left,ele);
        bool right = f(root->right,ele);

        return left && right;
    }
    bool isUnivalTree(TreeNode* root) {
        return f(root,root->val);
    }
};