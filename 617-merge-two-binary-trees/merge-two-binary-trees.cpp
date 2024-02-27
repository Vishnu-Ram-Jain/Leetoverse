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
    TreeNode* f(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)return NULL;
        if(p==NULL && q!=NULL)return q;
        if(p!=NULL && q==NULL)return p;
        TreeNode* newnode = new TreeNode(0);
        if(p!=NULL)newnode->val += p->val;
        if(q!=NULL)newnode->val += q->val;
        newnode->left = f(p->left,q->left);
        newnode->right = f(p->right,q->right);
        return newnode;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};