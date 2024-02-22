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
    typedef long long ll;
    bool f(TreeNode* root, ll mini, ll maxi){
        if(root==NULL)return true;
        if(root->val >= maxi || root->val <= mini)return false;

        bool l = f(root->left,mini,root->val);
        bool r = f(root->right,root->val,maxi);
        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN,LONG_MAX);
    }
};