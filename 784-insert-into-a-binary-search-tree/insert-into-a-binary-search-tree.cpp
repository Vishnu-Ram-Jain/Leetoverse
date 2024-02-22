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
    TreeNode* f(TreeNode* root, int x){
        // if(root==NULL)return root;
        if(root->left==NULL and root->right==NULL)return root;

        TreeNode* node = root;
        if(root->val > x && root->left!=NULL){
            node = f(root->left,x);
        }
        else if(root->val < x && root->right!=NULL){
            node = f(root->right,x);
        }

        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if(root==NULL)return newnode;
        TreeNode* node = f(root,val);
        if(node->val > val)node->left = newnode;
        else node->right = newnode;
        return root;
    }
};