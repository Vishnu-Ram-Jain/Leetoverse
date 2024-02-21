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
    int ans = 0;
    void f(TreeNode* root, int maxi, int mini){
        if(root==NULL)return ;

        maxi = max(maxi,root->val);
        mini = min(mini,root->val);

        ans = max(ans,maxi-mini);
        f(root->left,maxi,mini);
        f(root->right,maxi,mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        f(root,root->val,root->val);
        return ans;
    }
};