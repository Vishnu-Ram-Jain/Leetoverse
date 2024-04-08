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
    void f(TreeNode* root, int &sum, int num){

        if(root==NULL)return;

        if(root->left==NULL && root->right==NULL){
            num = (num*10) + root->val;
            sum += num;
            num = (num/10) - root->val;
            return ;
        }

        num = (num*10) + root->val;
        f(root->left,sum,num);
        f(root->right,sum,num);
        // num = (num/10) - root->val;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int num = 0;
        f(root,sum,num);
        return sum;
    }
};