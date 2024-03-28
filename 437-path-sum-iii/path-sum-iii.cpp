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
    typedef long long ll;
    void f(TreeNode* root, ll tar){
        if(root==NULL)return ;
        if(root->val == tar){
            cnt++;
        }
        f(root->left,tar-root->val);
        f(root->right,tar-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        f(root,targetSum);
        if(root->left!=NULL)pathSum(root->left,targetSum);
        if(root->right!=NULL)pathSum(root->right,targetSum);
        return cnt;
    }
};