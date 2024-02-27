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
    bool f(TreeNode* p, TreeNode* q){
        if(p==NULL && q!=NULL)return false;
        if(p!=NULL && q==NULL)return false;
        if(p==NULL && q==NULL)return true;
        if(p->val != q->val)return false;
        bool left = f(p->left,q->right);
        bool right = f(p->right,q->left);

        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL and root->right==NULL)return true;
        return f(root->left,root->right);
    }
};