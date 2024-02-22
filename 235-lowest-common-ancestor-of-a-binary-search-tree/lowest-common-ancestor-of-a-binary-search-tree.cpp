/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode*root, TreeNode*p, TreeNode*q){
        if(root==NULL)return root;

        int curr = root->val;
        TreeNode* node = root;
        if(curr < p->val && curr < q->val){
            node = f(root->right,p,q);
        }
        else if(curr > p->val && curr > q->val){
            node = f(root->left,p,q);
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};