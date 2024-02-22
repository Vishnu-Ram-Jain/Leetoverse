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
    bool f(TreeNode* root, int tar, unordered_map<int,bool> &mp){
        // if(root==NULL)return false;
        if(mp.find(tar - root->val) != mp.end())return true;
        mp[root->val] = 1;
        bool l = 0;
        bool r = 0;
        if(root->left!=NULL)l = f(root->left,tar,mp);
        if(root->right!=NULL)r = f(root->right,tar,mp);
        return l or r;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool> mp;
        return f(root,k,mp);
    }
};