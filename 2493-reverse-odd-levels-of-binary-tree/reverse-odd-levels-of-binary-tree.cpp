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
    void f(TreeNode* root1,TreeNode* root2, int lvl){
        if(root1==NULL or root2==NULL)return ;
        if(lvl % 2 == 0)swap(root1->val,root2->val);
        f(root1->left,root2->right,lvl+1);
        f(root1->right,root2->left,lvl+1);

        // return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        f(root->left,root->right,0);
        return root;
    }
};