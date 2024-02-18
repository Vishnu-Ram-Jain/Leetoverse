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
    void f(TreeNode* root, vector<int> &op, vector<vector<int>> &ans, int tar){
        // if(root==NULL)return;
        if(root->left==NULL and root->right==NULL){
            if(root->val==tar){
                op.push_back(root->val);
                ans.push_back(op);
                op.pop_back();
            }
            return ;
        }
        op.push_back(root->val);
        tar = tar-root->val;
        if(root->left!=NULL)f(root->left,op,ans,tar);
        if(root->right!=NULL)f(root->right,op,ans,tar);
        tar = tar+root->val;
        op.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return {};
        vector<int> op;
        vector<vector<int>> ans;
        f(root,op,ans,targetSum);
        return ans;
    }
};