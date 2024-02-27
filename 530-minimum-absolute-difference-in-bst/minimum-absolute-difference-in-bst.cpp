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
    int ans = INT_MAX;
    int val = -1;
    void f(TreeNode* root){
        if(root->left != NULL){
            f(root->left);
        }
        if(val>=0)ans = min(ans,root->val-val);
        val = root->val;
        if(root->right != NULL){
            f(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        f(root);
        return ans;
    }
};