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
        if(p==NULL && q != NULL)return false;
        if(p!=NULL && q == NULL)return false;
        if(p==NULL && q == NULL)return true;
        if(p->val != q->val)return false;
        bool left = f(p->left,q->left);
        bool right = f(p->right,q->right);
        return left && right;

    }
    // TreeNode* node(TreeNode* root, TreeNode* sub){
    //     if(root==NULL)return NULL;
    //     if(root->val==sub->val){
    //         return root;
    //     }
    //     f(root->left,sub);
    //     f(root->right,sub);
    //     return NULL;
    // }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        if(subRoot==NULL)return true;

        if(f(root,subRoot))return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};