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
        if(p==NULL and q==NULL)return 1;
        if(p==NULL and q!=NULL)return 0;
        if(p!=NULL and q==NULL)return 0;
        if(p->val != q->val)return 0;


        bool left = f(p->left,q->left);
        bool right = f(p->right,q->right);

        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(subRoot == NULL){
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if(f(root,subRoot))return true;

        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};