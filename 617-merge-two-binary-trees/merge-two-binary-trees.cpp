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
        if(p==NULL and q!=NULL)return q;
        else if(p==NULL and q==NULL)return NULL;
        else if(p!=NULL and q==NULL)return p;

        TreeNode* root = new TreeNode(p->val+q->val);

        root->left = f(p->left,q->left);
        root->right = f(p->right,q->right);

        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};