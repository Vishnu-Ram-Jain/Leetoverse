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
    void f(TreeNode* root, int &sum, bool flag){
        if(root->left==NULL and root->right==NULL){
            if(flag)sum += root->val;
            return ;
        }

        if(root->left!=NULL)f(root->left,sum,true);
        if(root->right!=NULL)f(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        f(root,sum,false);
        return sum;
    }
};