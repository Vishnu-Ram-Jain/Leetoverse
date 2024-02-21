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
    int cnt = 0;
    void f(TreeNode* root, int maxi){
        if(root==NULL)return ;
        maxi = max(maxi,root->val);
        if(root->val >= maxi)cnt++;
        f(root->left,maxi);
        f(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        int maxi = root->val;
        f(root,maxi);
        return cnt; 
    }
};