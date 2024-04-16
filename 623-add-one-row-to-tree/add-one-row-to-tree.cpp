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
    void f(TreeNode *root, int depth, int val, int lvl){
        if(root==NULL)return;
        if(lvl < depth-1){
            f(root->left,depth,val,lvl+1);
            f(root->right,depth,val,lvl+1);
        }
        else{
            TreeNode* l = root->left;
            TreeNode *leftnode = new TreeNode(val);
            root->left = leftnode;
            root->left->left = l;

            TreeNode* r = root->right;
            TreeNode *rightnode = new TreeNode(val);
            root->right = rightnode;
            root->right->right = r;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* ptr = new TreeNode(val);
            ptr->left = root;
            return ptr;
        }
        f(root,depth,val,1);
        return root;
    }
};