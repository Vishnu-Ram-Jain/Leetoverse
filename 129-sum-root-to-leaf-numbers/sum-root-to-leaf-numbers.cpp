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
    int sum = 0;
    void f(TreeNode* root, int num){
        if(root == NULL)return ;
        if(root->left==NULL && root->right==NULL){
            num = (num * 10) + root->val;
            sum += num;
            return ;
        }
        num = (num * 10) + root->val;

        f(root->left,num);
        f(root->right,num);

    }
    int sumNumbers(TreeNode* root) {
        int num = 0;
        f(root,num);
        return sum;
    }
};